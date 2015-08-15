#include "registers.h"

Registers::Registers():acc_("ACC"), ALU_ ("ALU")
{
    setALU(0);
    setACC(0);
}
