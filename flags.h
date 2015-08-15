#ifndef FLAGS_H
#define FLAGS_H

#include <QMap>
#include <QString>
#include<constants.hpp>

class Flags
{
    QString zero_;
    QString carry_;
    QMap<QString, bool> flags_;
public:
    Flags();
    void setFlags(FLAGSTATES newState) {
        switch (newState)
        {
        case SET_CARRY_UNSET_ZERO:
            setCarry(true);
            setZero(false);
            break;
        case SET_CARRY_SET_ZERO:
            setCarry(true);
            setZero(true);
            break;
        case UNSET_CARRY_UNSET_ZERO:
            setCarry(false);
            setZero(false);
            break;
        case UNSET_CARRY_SET_ZERO:
            setCarry(false);
            setZero(true);
            break;
        case SET_CARRY:
            setCarry(true);
            break;
        case UNSET_CARRY:
            setCarry(false);
            break;
        case SET_ZERO:
            setZero(true);
            break;
        case UNSET_ZERO:
            setZero(false);
            break;
        default:
            break;
        }
    };

    void setZero(const bool newVal) { flags_[zero_] = newVal; }
    void setCarry(const bool newVal) { flags_[carry_] = newVal; }
    bool getZero() const { return flags_[zero_]; }
    bool getCarry() const { return flags_[carry_]; }

    QString outputToLog() {
        QString logString;

        logString.append("Carry: ");
        logString.append(QString::number(getCarry(),2));
        logString.append('\t');
        logString.append("Zero: ");
        logString.append(QString::number(getZero(),2));
        logString.append('\t');
        return logString;
    }
};

#endif // FLAGS_H
