#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

#include<QString>
#include<QMap>
#include<QVector>

class Instruction
{
private:
    QString name_;
protected:
    int parameter_;
    QMap<QString, unsigned int> registers_;
    QMap<QString, bool> flags_;
    QVector<bool> RAM_;

public:
    Instruction(const QString& name, const int parameter, QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM);

    virtual bool execute(unsigned int input = 0) = 0;
};

class JMP : public Instruction {
public:
    JMP(const int parameter, QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("JMP", parameter, registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
        // move the current instruction to the input value.
        // how do we relate the instruction line to the memory location.
        return true;
    }
};

class JPC : public Instruction {
public:
    JPC(const int parameter, QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("JPC", parameter, registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
        // move the current instruction to the input value.
        // how do we relate the instruction line to the memory location.
        return true;
    }
};

class JPZ : public Instruction {
public:
    JPZ(const int parameter, QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("JPZ", parameter, registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
        // move the current instruction to the input value.
        // how do we relate the instruction line to the memory location.
        return true;
    }
};

class JNC : public Instruction {
public:
    JNC(const int parameter, QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("JNC", parameter, registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
        // move the current instruction to the input value.
        // how do we relate the instruction line to the memory location.
        return true;
    }
};

class JNZ : public Instruction {
public:
    JNZ(const int parameter, QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("JNZ", parameter, registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
        // move the current instruction to the input value.
        // how do we relate the instruction line to the memory location.
        return true;
    }
};

class JPE : public Instruction {
public:
    JPE(const int parameter, QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("JPE", parameter, registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
        // move the current instruction to the input value.
        // how do we relate the instruction line to the memory location.
        return true;
    }
};

class NOP : public Instruction {
public:
    NOP(const int parameter, QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("NOP", parameter, registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
        // move the current instruction to the input value.
        // how do we relate the instruction line to the memory location.
        return true;
    }
};

class DO : public Instruction {
public:
    DO(const int parameter, QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("DO", parameter, registers, flags, RAM)
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
    DEC(const int parameter, QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("DEC", parameter, registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
        // check what happens if it has not been created yet?
        // in real terms, what happens if it is zero?
        --registers_["ACC"];
        return true;
    }
};

class SUC : public Instruction {
public:
    SUC(const int parameter, QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("SUC", parameter, registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
        // move the current instruction to the input value.
        // how do we relate the instruction line to the memory location.
        return true;
    }
};

class ADD : public Instruction {
public:
    ADD(const int parameter, QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("ADD", parameter, registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
        // move the current instruction to the input value.
        // how do we relate the instruction line to the memory location.
        return true;
    }
};

class ASL : public Instruction {
public:
    ASL(const int parameter, QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("ASL", parameter, registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
        // move the current instruction to the input value.
        // how do we relate the instruction line to the memory location.
        return true;
    }
};

class NOF : public Instruction {
public:
    NOF(const int parameter, QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("NOF", parameter, registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
        // move the current instruction to the input value.
        // how do we relate the instruction line to the memory location.
        return true;
    }
};

class INV : public Instruction {
public:
    INV(const int parameter, QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("INV", parameter, registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
        // move the current instruction to the input value.
        // how do we relate the instruction line to the memory location.
        return true;
    }
};

class NAN : public Instruction {
public:
    NAN(const int parameter, QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("NAN", parameter, registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
        // move the current instruction to the input value.
        // how do we relate the instruction line to the memory location.
        return true;
    }
};

class SET : public Instruction {
public:
    SET(const int parameter, QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("SET", parameter, registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
        // move the current instruction to the input value.
        // how do we relate the instruction line to the memory location.
        return true;
    }
};

class LDC : public Instruction {
public:
    LDC(const int parameter, QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("LDC", parameter, registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
        // move the current instruction to the input value.
        // how do we relate the instruction line to the memory location.
        return true;
    }
};

class XOR : public Instruction {
public:
    XOR(const int parameter, QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("XOR", parameter, registers, flags, RAM)
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
    LDA(const int parameter, QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("LDA", parameter, registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
        registers_["ACC"] = input;
        return true;
    }
};

class IOR : public Instruction {
public:
    IOR(const int parameter, QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("IOR", parameter, registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
        return true;
    }
};

class CLR : public Instruction {
public:
    CLR(const int parameter, QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("CLR", parameter, registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
        return true;
    }
};

class AND : public Instruction {
public:
    AND(const int parameter, QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("AND", parameter, registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
        return true;
    }
};

class SUB : public Instruction {
public:
    SUB(const int parameter, QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("SUB", parameter, registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
        return true;
    }
};

class ADI : public Instruction {
public:
    ADI(const int parameter, QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("ADI", parameter, registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
        return true;
    }
};

class SFI : public Instruction {
public:
    SFI(const int parameter, QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("SFI", parameter, registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
        return true;
    }
};

class INC : public Instruction {
public:
    INC(const int parameter, QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("INC", parameter, registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
        return true;
    }
};

// Store accumulator
class STA : public Instruction {
public:
    STA(const int parameter, QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("STA", parameter, registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
         // RAM[input] = registers_[ALU];
        // want to do the above but it will not work - will need to convert the ACC into a binary sequence and write them
        // on by one ... or something
        return true;
    }
};


#endif // INSTRUCTION_HPP
