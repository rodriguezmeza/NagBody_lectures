/*==============================================================================
 NAME: main.c				[interpolation]
 Mario A. Rodriguez-Meza (marioalberto.rodriguez@inin.gob.mx)
 ================================================================================
 Use: interpolation -help
 Input: 	Command line parameters or Parameters file
 Output: interpolated functions.
 ==============================================================================*/

#define global

#include "globaldefs.h"
#include "cmdline_defs.h"
#include "protodefs.h"

int main(int argc, string argv[])
{
    gd.cpuinit = second();
    InitParam(argv, defv);
    StartRun(argv[0], HEAD1, HEAD2, HEAD3);
    MainLoop();
    EndRun();
    return 0;
}

