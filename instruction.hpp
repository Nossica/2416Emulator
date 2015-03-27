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
    JMP(const QString& name, QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction(name, registers, flags, RAM)
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
    LDA(const QString& name, QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction(name, registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
        registers_["ACC"] = input;
        return true;
    }
};

// Decrement accumulator
class DEC : public Instruction {
public:
    DEC(const QString& name, QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction(name, registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
        // check what happens if it has not been created yet?
        // in real terms, what happens if it is zero?
        --registers_["ACC"];
        return true;
    }
};


// Store accumulator
class STA : public Instruction {
public:
    STA(const QString& name, QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM) :
        Instruction(name, registers, flags, RAM)
    {}

    virtual bool execute(unsigned int input = 0) {
         // RAM[input] = registers_[ALU];
        // want to do the above but it will not work - will need to convert the ACC into a binary sequence and write them
        // on by one ... or something
        return true;
    }
};


#endif // INSTRUCTION_HPP
