#include "instruction.hpp"

Instruction::Instruction(const QString& name, QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM)
    : name_(name), registers_(registers), flags_(flags), RAM_(RAM)
{
}
