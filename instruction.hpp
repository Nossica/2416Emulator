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
    QMap<QString, unsigned int> registers_;
    QMap<QString, bool> flags_;
    QVector<bool> RAM_;

public:
    Instruction(const QString& name, QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM);

    virtual bool execute(unsigned int input = 0) = 0;
};

class JMP : public Instruction {
public:
    JMP(QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("JMP", registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
        // move the current instruction to the input value.
        // how do we relate the instruction line to the memory location.
        return true;
    }
};

class JPC : public Instruction {
public:
    JPC(QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("JPC", registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
        // move the current instruction to the input value.
        // how do we relate the instruction line to the memory location.
        return true;
    }
};

class JPZ : public Instruction {
public:
    JPZ(QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("JPZ", registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
        // move the current instruction to the input value.
        // how do we relate the instruction line to the memory location.
        return true;
    }
};

class JNC : public Instruction {
public:
    JNC(QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("JNC", registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
        // move the current instruction to the input value.
        // how do we relate the instruction line to the memory location.
        return true;
    }
};

class JNZ : public Instruction {
public:
    JNZ(QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("JNZ", registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
        // move the current instruction to the input value.
        // how do we relate the instruction line to the memory location.
        return true;
    }
};

class JPE : public Instruction {
public:
    JPE(QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("JPE", registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
        // move the current instruction to the input value.
        // how do we relate the instruction line to the memory location.
        return true;
    }
};

class NOP : public Instruction {
public:
    NOP(QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("NOP", registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
        // move the current instruction to the input value.
        // how do we relate the instruction line to the memory location.
        return true;
    }
};

class DO : public Instruction {
public:
    DO(QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("DO", registers, flags, RAM)
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
    DEC(QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("DEC", registers, flags, RAM)
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
    SUC(QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("SUC", registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
        // move the current instruction to the input value.
        // how do we relate the instruction line to the memory location.
        return true;
    }
};

class ADD : public Instruction {
public:
    ADD(QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("ADD", registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
        // move the current instruction to the input value.
        // how do we relate the instruction line to the memory location.
        return true;
    }
};

class ASL : public Instruction {
public:
    ASL(QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("ASL", registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
        // move the current instruction to the input value.
        // how do we relate the instruction line to the memory location.
        return true;
    }
};

class NOF : public Instruction {
public:
    NOF(QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("NOF", registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
        // move the current instruction to the input value.
        // how do we relate the instruction line to the memory location.
        return true;
    }
};

class INV : public Instruction {
public:
    INV(QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("INV", registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
        // move the current instruction to the input value.
        // how do we relate the instruction line to the memory location.
        return true;
    }
};

class NAN : public Instruction {
public:
    NAN(QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("NAN", registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
        // move the current instruction to the input value.
        // how do we relate the instruction line to the memory location.
        return true;
    }
};

class SET : public Instruction {
public:
    SET(QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("SET", registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
        // move the current instruction to the input value.
        // how do we relate the instruction line to the memory location.
        return true;
    }
};

class LDC : public Instruction {
public:
    LDC(QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("LDC", registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
        // move the current instruction to the input value.
        // how do we relate the instruction line to the memory location.
        return true;
    }
};

class XOR : public Instruction {
public:
    XOR(QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("XOR", registers, flags, RAM)
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
    LDA(QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("LDA", registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
        registers_["ACC"] = input;
        return true;
    }
};

class IOR : public Instruction {
public:
    IOR(QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("IOR", registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
        return true;
    }
};

class CLR : public Instruction {
public:
    CLR(QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("CLR", registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
        return true;
    }
};

class AND : public Instruction {
public:
    AND(QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("AND", registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
        return true;
    }
};

class SUB : public Instruction {
public:
    SUB(QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("SUB", registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
        return true;
    }
};

class ADI : public Instruction {
public:
    ADI(QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("ADI", registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
        return true;
    }
};

class SFI : public Instruction {
public:
    SFI(QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("SFI", registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
        return true;
    }
};

class INC : public Instruction {
public:
    INC(QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("INC", registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
        return true;
    }
};

// Store accumulator
class STA : public Instruction {
public:
    STA(QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction("STA", registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
         // RAM[input] = registers_[ALU];
        // want to do the above but it will not work - will need to convert the ACC into a binary sequence and write them
        // on by one ... or something
        return true;
    }
};


#endif // INSTRUCTION_HPP
