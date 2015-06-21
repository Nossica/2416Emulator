#ifndef FLAGS_H
#define FLAGS_H

#include <QMap>
#include <QString>

class Flags
{
    QString zero_;
    QString carry_;
    QMap<QString, bool> flags_;
public:
    Flags();

    void setZero(const bool newVal) { flags_[zero_] = newVal; }
    void setCarry(const bool newVal) { flags_[carry_] = newVal; }
    const bool getZero() { return flags_[zero_]; }
    const bool getCarry() { return flags_[carry_]; }
};

#endif // FLAGS_H
