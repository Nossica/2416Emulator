#ifndef TOKEN_H
#define TOKEN_H

#include<constants.hpp>
#include<QString>

class Token {
protected:
    unsigned int value_;
    unsigned int parameter_;

    void setValue(const unsigned int value) {
        value_ = value%0xFFFF;
    }

    void setParameter(const unsigned int value) {
        parameter_ = value%0xFFFFFF;
    }

public:
    virtual bool execute() {
        eNotAnInstruction e;
        throw e;
    }

    Token(unsigned int value, unsigned int parameter) {
        setValue(value);
        setParameter(parameter);
    }

    virtual unsigned int getValue() const { return value_; }
    virtual unsigned int getParameter() const { return parameter_; }

    // Instruction value, param
    virtual QString outputToLog() {
        QString line;
        line.append("Value: ");
        line.append(QString::number(getValue(),16));
        line.append('\t');
        line.append("Parameter: ");
        line.append(getParameter());
        line.append('\t');
        return line;
    }

};

#endif // TOKEN_H
