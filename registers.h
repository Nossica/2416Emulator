#ifndef REGISTERS_H
#define REGISTERS_H

#include<QMap>
#include<QString>

class Registers
{
    QString acc_;
    QString ALU_;
    QMap<QString, unsigned int> registers_;
public:
    Registers();
    void setACC(unsigned int newValue) { registers_[acc_] = newValue; }
    void subACC(unsigned int index) { registers_[acc_] -= newValue; }
    void addACC(unsigned int index) { registers_[acc_] += newValue; }

    void setALU(unsigned int newValue) { registers_[ALU_] = newValue; }

    unsigned int getACC() { return registers_[acc_]; }
    unsigned int getALU() { return registers_[ALU_]; }
};

#endif // REGISTERS_H
