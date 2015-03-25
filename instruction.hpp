#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

#include<QString>
#include<QMap>
#include<QVector>

class Instruction
{
    QString name_;
    QMap<QString, unsigned int>& registers_;
    QVector<bool> RAM_;

public:
    Instruction(const QString& name, QMap<QString, unsigned int>& registers, QVector<bool>& RAM);

    virtual bool execute() = 0;
};

#endif // INSTRUCTION_HPP
