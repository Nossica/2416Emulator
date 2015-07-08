#include "flags.h"

Flags::Flags()
{
    zero_ = "ZERO";
    carry_ = "CARRY";

    setZero(true);
    setCarry(false);
}
