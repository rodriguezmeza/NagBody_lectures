/*==============================================================================
 MODULE: interpol.c				[interpolation]
==============================================================================*/

#include "globaldefs.h"
#include "protodefs.h"

local void PSLTable(void);

void MainLoop(void)
{
    real k, PSLB;
    
    if (!strnull(cmd.fnamePS)) {
        sprintf(gd.fnamePSPath,"Input/%s",cmd.fnamePS);
        fprintf(gd.outlog,"PS file Path and file name: %s\n",gd.fnamePSPath);
        fflush(gd.outlog);
        PSLTable();
    }
    
    k = cmd.kin;
    PSLB = psInterpolation_nr(k, kPS, pPS, nPSLT);
    fprintf(stdout,"\n\n kin, PS :: %g %g\n\n",k,PSLB);
}

local void PSLTable(void)
{
    char namebuf[256];
    stream outstr;
    int i;
//
    fprintf(gd.outlog,"\n\nReading power spectrum from file %s...\n",gd.fnamePSPath);
    inout_InputData(gd.fnamePSPath, 1, 2, &nPSLT);

    if (nPSLT < 1)
        error("\n\nInputPSTable: nPSTable = %d is absurd\n\n", nPSLT);

    fprintf(gd.outlog,"nPSTable : %d\n", nPSLT);

    kPS = dvector(1,nPSLT);
    pPS = dvector(1,nPSLT);
    pPS2 = dvector(1,nPSLT);

    for (i = 1; i<nPSLT; i++) {
        kPS[i] = inout_xval[i];
        pPS[i] = inout_yval[i];
    }
//
    spline(kPS,pPS,nPSLT,1.0e30,1.0e30,pPS2);

    sprintf(namebuf,"%s/%s%s",gd.clptDir,"PSL",".dat");
    outstr = stropen(namebuf,"w!");
    for (i=1; i<=nPSLT; i++) {
        fprintf(outstr,"%e %e\n",
                kPS[i],pPS[i]);
    }
    fclose(outstr);
}

global  real psInterpolation_nr(real k, double kPS[], double pPS[], int nPS)
{
    real psftmp;

    splint(kPS,pPS,pPS2,nPS,k,&psftmp);
    
    return (psftmp);
}
