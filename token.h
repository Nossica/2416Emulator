#ifndef TOKEN_H
#define TOKEN_H

#include<constants.hpp>

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
};

#endif // TOKEN_H
