#include "instruction.hpp"

Instruction::Instruction(const QString& name, const int parameter, QMap<QString, unsigned int>& registers, QMap<QString, bool>& flags, QVector<bool>& RAM)
    : name_(name), parameter_(parameter), registers_(registers), flags_(flags), RAM_(RAM)
{
}
