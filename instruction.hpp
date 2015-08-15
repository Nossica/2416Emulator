#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

#include<iostream>
#include<QString>
#include<QMap>
#include<QVector>
#include<flags.h>
#include<registers.h>
#include<ram.h>
#include<token.h>

class Instruction : public Token
{
private:
    QString name_;
protected:
    Registers& registers_;
    Flags& flags_;
    RAM& RAM_;

public:
    Instruction(const QString& name, const unsigned int value, const int parameter, Registers& registers, Flags& flags, RAM& Ram);

    virtual QString getName() { return name_; }
    virtual QString getParameter() { return QString::number(parameter_,16); }
    virtual QString outputToLog() {
        // Instruction name, value, param, RAR, ALU, ACC, Carry, Zero

        QString logString;
        logString.append("Name: ");
        logString.append(getName());
        logString.append("\t");
        logString.append("Value: ");
        logString.append(QString::number(getValue(), 16));
        logString.append('\t');

        return logString;
    }
};

class JMP : public Instruction {
public:
    JMP(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("JMP", 0x00, parameter, registers, flags, Ram)
    {}

    bool execute() {
        RAM_.setCurrent(parameter_);
        return false;
    }
};

class RJMP : public Instruction {
public:
    RJMP(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("RJMP", 0x30, parameter, registers, flags, Ram)
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
        Instruction("JPC", 0x0B, parameter, registers, flags, Ram)
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
        Instruction("JPC", 0x3B, parameter, registers, flags, Ram)
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
        Instruction("JPZ", 0x0E, parameter, registers, flags, Ram)
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
        Instruction("JPZ", 0x3E, parameter, registers, flags, Ram)
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
        Instruction("JNC", 0x0D, parameter, registers, flags, Ram)
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
        Instruction("JNC", 0x3D, parameter, registers, flags, Ram)
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
        Instruction("JNZ", 0x07, parameter, registers, flags, Ram)
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
        Instruction("JNZ", 0x37, parameter, registers, flags, Ram)
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
        Instruction("JPE", 0x0A, parameter, registers, flags, Ram)
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
        Instruction("JPE", 0x3A, parameter, registers, flags, Ram)
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
        Instruction("NOP", 0x0F, parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        RAM_.setRAR();
        return true;
    }
};

class RNOP : public Instruction {
public:
    RNOP(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("NOP", 0x3F, parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        RAM_.setRAR();
        return true;
    }
};

class DO : public Instruction {
public:
    DO(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("DO", 0x3F, parameter, registers, flags, Ram)
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
        Instruction("DEC", 0x40, parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        flags_.setFlags(registers_.subACC(1));
        return true;
    }
};

class SUC : public Instruction {
public:
    SUC(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("SUC", 0x46, parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        flags_.setFlags(registers_.subACC(RAM_.readFromMemory(parameter_)->getValue()));
        flags_.setFlags(registers_.subACC(1));
        return true;
    }
};

class ADD : public Instruction {
public:
    ADD(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("ADD", 0x49, parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        flags_.setFlags(registers_.addACC(RAM_.readFromMemory(parameter_)->getValue()));
        return true;
    }
};

class ASL : public Instruction {
public:
    ASL(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("ASL", 0x4C, parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        flags_.setFlags(registers_.shiftACCUp());
        return true;
    }
};

class NOF : public Instruction {
public:
    NOF(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("NOF", 0x4F, parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        //flags_.setFlags(registers_.getACC());
        return true;
    }
};

class INV : public Instruction {
public:
    INV(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("INV", 0x50, parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        registers_.invACC();
        return true;
    }
};

class NAN : public Instruction {
public:
    NAN(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("NAN", 0x51, parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        registers_.setACC((~(registers_.getACC() & RAM_.readFromMemory(parameter_)->getValue()))%0xFFFF);
        return true;
    }
};

class SET : public Instruction {
public:
    SET(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("SET", 0x52, parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        flags_.setFlags(registers_.setACC(parameter_));
        return true;
    }
};

class LDC : public Instruction {
public:
    LDC(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("LDC", 0x54, parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        flags_.setFlags(registers_.setACC(~RAM_.readFromMemory(parameter_)->getValue()));
        return true;
    }
};

class XOR : public Instruction {
public:
    XOR(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("XOR", 0x59, parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        flags_.setFlags(registers_.setACC(registers_.getACC() ^ RAM_.readFromMemory(parameter_)->getValue()));
        return true;
    }
};

// Load accumulator
class LDA : public Instruction {
public:
    LDA(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("LDA", 0x5A, parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        flags_.setFlags(registers_.setACC(RAM_.readFromMemory(parameter_)->getValue()));
        return true;
    }
};

class IOR : public Instruction {
public:
    IOR(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("IOR", 0x5B, parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        flags_.setFlags(registers_.setACC(registers_.getACC() | RAM_.readFromMemory(parameter_)->getValue()));
        return true;
    }
};

class CLR : public Instruction {
public:
    CLR(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("CLR", 0x5C, parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        flags_.setFlags(registers_.setACC(0));
        return true;
    }
};

class AND : public Instruction {
public:
    AND(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("AND", 0x5E, parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        flags_.setFlags(registers_.setACC(registers_.getACC() & RAM_.readFromMemory(parameter_)->getValue()));
        return true;
    }
};

class SUB : public Instruction {
public:
    SUB(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("SUB", 0x66, parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        flags_.setFlags(registers_.subACC(RAM_.readFromMemory(parameter_)->getValue()));
        return true;
    }
};

class ADI : public Instruction {
public:
    ADI(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("ADI", 0x69, parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        flags_.setFlags(registers_.addACC(1 + RAM_.readFromMemory(parameter_)->getValue()));
        return true;
    }
};

class SFI : public Instruction {
public:
    SFI(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("SFI", 0x6C, parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        flags_.setFlags(registers_.shiftACCUp(0x1));
        return true;
    }
};

class INC : public Instruction {
public:
    INC(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("INC", 0x6F, parameter, registers, flags, Ram)
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
        Instruction("STA", 0x80, parameter, registers, flags, Ram)
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
        Instruction("STA", 0xB0, parameter, registers, flags, Ram)
    {}

    virtual bool execute() {
        RAM_.setRAR();
        RAM_.writeToMemory(parameter_, registers_.getACC());
        return true;
    }
};

#endif // INSTRUCTION_HPP
