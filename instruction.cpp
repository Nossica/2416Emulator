#include "instruction.hpp"

Instruction::Instruction(const QString& name, const unsigned int value, const int parameter, Registers& registers, Flags& flags, RAM& Ram)
    : Token(value, parameter), name_(name), registers_(registers), flags_(flags), RAM_(Ram)
{
}
