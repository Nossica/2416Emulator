#include "instruction.hpp"

Instruction::Instruction(const QString& name, const int parameter, Registers& registers, Flags& flags, RAM& Ram)
    : name_(name), parameter_(parameter), registers_(registers), flags_(flags), RAM_(Ram)
{
}
