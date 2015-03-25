#include "instruction.hpp"

Instruction::Instruction(const QString& name, QMap<QString, unsigned int>& registers, QVector<bool>& RAM)
    : name_(name), registers_(registers), RAM_(RAM)
{
}
