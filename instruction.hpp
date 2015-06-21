#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

#include<QString>
#include<QMap>
#include<QVector>
#include<flags.h>
#include<registers.h>
#include<ram.h>

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

    virtual bool execute(unsigned int input = 0) = 0;
    virtual QString getName() { return name_; }
    virtual QString getParameter() { return QString::number(parameter_); }
};

class JMP : public Instruction {
public:
    JMP(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("JMP", parameter, registers, flags, Ram)
    {}

    virtual bool execute(unsigned int input = 0) {
        RAM_.setCurrent(parameter_);
        return false;
    }
};

class JPC : public Instruction {
public:
    JPC(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("JPC", parameter, registers, flags, Ram)
    {}

    virtual bool execute(unsigned int input = 0) {
        if (flags_.getCarry()) {
            RAM_.setCurrent(input);
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

    virtual bool execute(unsigned int input = 0) {
        if (flags_.getZero()) {
            RAM_.setCurrent(input);
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

    virtual bool execute(unsigned int input = 0) {
        if (flags_.getCarry() == false) {
            RAM_.setCurrent(input);
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

    virtual bool execute(unsigned int input = 0) {
        if (flags_.getZero() == false) {
            RAM_.setCurrent(input);
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

    virtual bool execute(unsigned int input = 0) {
        if (flags_.getCarry() || flags_.getZero()) {
            RAM_.setCurrent(input);
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

    virtual bool execute(unsigned int input = 0) {
        // WTF?
        return true;
    }
};

class DO : public Instruction {
public:
    DO(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("DO", parameter, registers, flags, Ram)
    {}

    virtual bool execute(unsigned int input = 0) {
        // move the current instruction to the input value.
        // how do we relate the instruction line to the memory location.
        return true;
    }
};

// Decrement accumulator
class DEC : public Instruction {
public:
    DEC(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("DEC", parameter, registers, flags, Ram)
    {}

    virtual bool execute(unsigned int input = 0) {
        // check what happens if it has not been created yet?
        // in real terms, what happens if it is zero?
        registers_.subACC(1);
        return true;
    }
};

class SUC : public Instruction {
public:
    SUC(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("SUC", parameter, registers, flags, Ram)
    {}

    virtual bool execute(unsigned int input = 0) {
        registers_.subACC(input - 1);
        return true;
    }
};

class ADD : public Instruction {
public:
    ADD(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("ADD", parameter, registers, flags, Ram)
    {}

    virtual bool execute(unsigned int input = 0) {
        registers_.addACC(input);
        return true;
    }
};

class ASL : public Instruction {
public:
    ASL(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("ASL", parameter, registers, flags, Ram)
    {}

    virtual bool execute(unsigned int input = 0) {
        // move the current instruction to the input value.
        // how do we relate the instruction line to the memory location.
        return true;
    }
};

class NOF : public Instruction {
public:
    NOF(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("NOF", parameter, registers, flags, Ram)
    {}

    virtual bool execute(unsigned int input = 0) {
        // move the current instruction to the input value.
        // how do we relate the instruction line to the memory location.
        return true;
    }
};

class INV : public Instruction {
public:
    INV(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("INV", parameter, registers, flags, Ram)
    {}

    virtual bool execute(unsigned int input = 0) {
        // move the current instruction to the input value.
        // how do we relate the instruction line to the memory location.
        return true;
    }
};

class NAN : public Instruction {
public:
    NAN(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("NAN", parameter, registers, flags, Ram)
    {}

    virtual bool execute(unsigned int input = 0) {
        // move the current instruction to the input value.
        // how do we relate the instruction line to the memory location.
        return true;
    }
};

class SET : public Instruction {
public:
    SET(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("SET", parameter, registers, flags, Ram)
    {}

    virtual bool execute(unsigned int input = 0) {
        registers_.setACC(input);
        return true;
    }
};

class LDC : public Instruction {
public:
    LDC(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("LDC", parameter, registers, flags, Ram)
    {}

    virtual bool execute(unsigned int input = 0) {
        // move the current instruction to the input value.
        // how do we relate the instruction line to the memory location.
        return true;
    }
};

class XOR : public Instruction {
public:
    XOR(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("XOR", parameter, registers, flags, Ram)
    {}

    virtual bool execute(unsigned int input = 0) {
        // move the current instruction to the input value.
        // how do we relate the instruction line to the memory location.
        return true;
    }
};

// Load accumulator
class LDA : public Instruction {
public:
    LDA(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("LDA", parameter, registers, flags, Ram)
    {}

    virtual bool execute(unsigned int input = 0) {
        Ram_[input]=registers_.getACC();
        return true;
    }
};

class IOR : public Instruction {
public:
    IOR(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("IOR", parameter, registers, flags, Ram)
    {}

    virtual bool execute(unsigned int input = 0) {
        return true;
    }
};

class CLR : public Instruction {
public:
    CLR(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("CLR", parameter, registers, flags, Ram)
    {}

    virtual bool execute(unsigned int input = 0) {
        return true;
    }
};

class AND : public Instruction {
public:
    AND(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("AND", parameter, registers, flags, Ram)
    {}

    virtual bool execute(unsigned int input = 0) {
        return true;
    }
};

class SUB : public Instruction {
public:
    SUB(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("SUB", parameter, registers, flags, Ram)
    {}

    virtual bool execute(unsigned int input = 0) {
        return true;
    }
};

class ADI : public Instruction {
public:
    ADI(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("ADI", parameter, registers, flags, Ram)
    {}

    virtual bool execute(unsigned int input = 0) {
        return true;
    }
};

class SFI : public Instruction {
public:
    SFI(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("SFI", parameter, registers, flags, Ram)
    {}

    virtual bool execute(unsigned int input = 0) {
        return true;
    }
};

class INC : public Instruction {
public:
    INC(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("INC", parameter, registers, flags, Ram)
    {}

    virtual bool execute(unsigned int input = 0) {
        registers_.addACC(1);
        return true;
    }
};

// Store accumulator
class STA : public Instruction {
public:
    STA(const int parameter, Registers& registers, Flags& flags, RAM& Ram) :
        Instruction("STA", parameter, registers, flags, Ram)
    {}

    virtual bool execute(unsigned int input = 0) {
        RAM_[input] = registers_.getACC();
        return true;
    }
};


#endif // INSTRUCTION_HPP
