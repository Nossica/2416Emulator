#include "registers.h"

Registers::Registers():acc_("ACC"), ALU_ ("ALU"), RAR_("RAR")
{
    setALU(0);
    setACC(0);
}
