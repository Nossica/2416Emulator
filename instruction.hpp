#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

#include<QString>
#include<QMap>
#include<QVector>
#include<flags.h>
#include<registers.h>
#include<ram.h>

// could we do bitwise and and or regardless of the base the number is in?

class Instruction
{
private:
    QString name_;
protected:
    int parameter_;
    Registers& registers_;
    Flags& flags_;
    RAM& RAM_;

public:
    Instruction(const QString& name, const int parameter, Registers& registers, Flags& flags, RAM& Ram);

    virtual bool execute() = 0;
    virtual QString getName() { return name_; }
    virtual QString getParameter() { return QString::number(parameter_); }
};

class JMP : public Instruction {
public:
    JMP(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("JMP", parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        RAM_.setCurrent(parameter_);
        return false;
    }
};

class RJMP : public Instruction {
public:
    RJMP(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("RJMP", parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        RAM_.setRAR();
        RAM_.setCurrent(parameter_);
        return false;
    }
};

class JPC : public Instruction {
public:
    JPC(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("JPC", parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        if (flags_.getCarry()) {
            RAM_.setCurrent(parameter_);
            return false;
        }
        return true;
    }
};

class NJPC : public Instruction {
public:
    NJPC(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("JPC", parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        if (flags_.getCarry()) {
            RAM_.setRAR();
            RAM_.setCurrent(parameter_);
            return false;
        }
        return true;
    }
};

class JPZ : public Instruction {
public:
    JPZ(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("JPZ", parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        if (flags_.getZero()) {
            RAM_.setCurrent(parameter_);
            return false;
        }
        return true;
    }
};

class RJPZ : public Instruction {
public:
    RJPZ(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("JPZ", parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        if (flags_.getZero()) {
            RAM_.setRAR();
            RAM_.setCurrent(parameter_);
            return false;
        }
        return true;
    }
};

class JNC : public Instruction {
public:
    JNC(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("JNC", parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        if (flags_.getCarry() == false) {
            RAM_.setCurrent(parameter_);
            return false;
        }
        return true;
    }
};

class RJNC : public Instruction {
public:
    RJNC(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("JNC", parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        if (flags_.getCarry() == false) {
            RAM_.setRAR();
            RAM_.setCurrent(parameter_);
            return false;
        }
        return true;
    }
};

class JNZ : public Instruction {
public:
    JNZ(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("JNZ", parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        if (flags_.getZero() == false) {
            RAM_.setCurrent(parameter_);
            return false;
        }
        return true;
    }
};

class RJNZ : public Instruction {
public:
    RJNZ(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("JNZ", parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        if (flags_.getZero() == false) {
            RAM_.setRAR();
            RAM_.setCurrent(parameter_);
            return false;
        }
        return true;
    }
};

class JPE : public Instruction {
public:
    JPE(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("JPE", parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        if (flags_.getCarry() || flags_.getZero()) {
            RAM_.setCurrent(parameter_);
            return false;
        }
        return true;
    }
};

class RJPE : public Instruction {
public:
    RJPE(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("JPE", parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        if (flags_.getCarry() || flags_.getZero()) {
            RAM_.setRAR();
            RAM_.setCurrent(parameter_);
            return false;
        }
        return true;
    }
};

class NOP : public Instruction {
public:
    NOP(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("NOP", parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        RAM_.setRAR();
        return true;
    }
};

class RNOP : public Instruction {
public:
    RNOP(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("NOP", parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        RAM_.setRAR();
        return true;
    }
};

class DO : public Instruction {
public:
    DO(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("DO", parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        RAM_.setRAR();
        return true;
    }
};

// Decrement accumulator
class DEC : public Instruction {
public:
    DEC(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("DEC", parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        flags_.setFlags(registers_.subACC(1));
        return true;
    }
};

class SUC : public Instruction {
public:
    SUC(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("SUC", parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        flags_.setFlags(registers_.subACC(RAM_.readFromMemory(parameter_)));
        flags_.setFlags(registers_.subACC(1));
        return true;
    }
};

class ADD : public Instruction {
public:
    ADD(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("ADD", parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        flags_.setFlags(registers_.addACC(RAM_.readFromMemory(parameter_)));
        return true;
    }
};

class ASL : public Instruction {
public:
    ASL(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("ASL", parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        flags_.setFlags(registers_.shiftACCUp());
        return true;
    }
};

class NOF : public Instruction {
public:
    NOF(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("NOF", parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        //flags_.setFlags(registers_.getACC());
        return true;
    }
};

class INV : public Instruction {
public:
    INV(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("INV", parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        registers_.invACC();
        return true;
    }
};

class NAN : public Instruction {
public:
    NAN(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("NAN", parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        unsigned int i = registers_.getACC();
        unsigned int j = RAM_.readFromMemory(parameter_);
        unsigned int q = (i&j);
        unsigned int z = ~q;

        registers_.setACC((~(registers_.getACC() & RAM_.readFromMemory(parameter_)))%0xFFFF);
        return true;
    }
};

class SET : public Instruction {
public:
    SET(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("SET", parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        flags_.setFlags(registers_.setACC(parameter_));
        return true;
    }
};

class LDC : public Instruction {
public:
    LDC(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("LDC", parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        flags_.setFlags(registers_.setACC(~RAM_.readFromMemory(parameter_)));
        return true;
    }
};

class XOR : public Instruction {
public:
    XOR(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("XOR", parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        flags_.setFlags(registers_.setACC(registers_.getACC() ^ RAM_.readFromMemory(parameter_)));
        return true;
    }
};

// Load accumulator
class LDA : public Instruction {
public:
    LDA(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("LDA", parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        flags_.setFlags(registers_.setACC(RAM_.readFromMemory(parameter_)));
        return true;
    }
};

class IOR : public Instruction {
public:
    IOR(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("IOR", parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        flags_.setFlags(registers_.setACC(registers_.getACC() | RAM_.readFromMemory(parameter_)));
        return true;
    }
};

class CLR : public Instruction {
public:
    CLR(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("CLR", parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        flags_.setFlags(registers_.setACC(0));
        return true;
    }
};

class AND : public Instruction {
public:
    AND(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("AND", parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        flags_.setFlags(registers_.setACC(registers_.getACC() & RAM_.readFromMemory(parameter_)));
        return true;
    }
};

class SUB : public Instruction {
public:
    SUB(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("SUB", parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        flags_.setFlags(registers_.subACC(RAM_.readFromMemory(parameter_)));
        return true;
    }
};

class ADI : public Instruction {
public:
    ADI(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("ADI", parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        flags_.setFlags(registers_.addACC(1 + RAM_.readFromMemory(parameter_)));
        return true;
    }
};

class SFI : public Instruction {
public:
    SFI(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("SFI", parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        flags_.setFlags(registers_.shiftACCUp(0x1));
        return true;
    }
};

class INC : public Instruction {
public:
    INC(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("INC", parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        flags_.setFlags(registers_.addACC(1));
        return true;
    }
};

// Store accumulator
class STA : public Instruction {
public:
    STA(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("STA", parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        RAM_.writeToMemory(parameter_, registers_.getACC());
        return true;
    }
};

// Store accumulator
class RSTA : public Instruction {
public:
    RSTA(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("STA", parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        RAM_.setRAR();
        RAM_.writeToMemory(parameter_, registers_.getACC());
        return true;
    }
};

#endif // INSTRUCTION_HPP
