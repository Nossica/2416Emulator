#ifndef REGISTERS_H
#define REGISTERS_H

#include<QMap>
#include<QString>
#include<constants.hpp>

class Registers
{
    QString acc_;
    QString ALU_;
    QString RAR_;
    QMap<QString, unsigned int> registers_;
public:
    Registers();
    FLAGSTATES setACC(int newValue) {
        FLAGSTATES retVal = UNSET_CARRY_UNSET_ZERO;

        registers_[acc_] = newValue;

        if (registers_[acc_] == 0x0)
            retVal = UNSET_CARRY_SET_ZERO;
        if (registers_[acc_] > 0xFFFF)
            retVal = SET_CARRY_UNSET_ZERO;

        registers_[acc_] %= 0xFFFF;

        return retVal;
    }

    unsigned int getACC() { return registers_[acc_]; }

    FLAGSTATES subACC(unsigned int offset) { return setACC(getACC() - offset); }
    FLAGSTATES addACC(unsigned int offset) { return setACC(getACC() + offset); }
    FLAGSTATES shiftACCUp(const int bitSet = 0x0) { return setACC((getACC() << 1) | bitSet); }
    void invACC() {
        registers_[acc_] = ~getACC();
        registers_[acc_] %= 0xFFFF;
    }

    void setALU(unsigned int newValue) { registers_[ALU_] = newValue; }
    unsigned int getALU() { return registers_[ALU_]; }
};

#endif // REGISTERS_H
