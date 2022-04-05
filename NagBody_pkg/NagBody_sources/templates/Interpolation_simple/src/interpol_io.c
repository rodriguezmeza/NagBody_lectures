/*==============================================================================
 MODULE: template_io.c		[interpolation]
 ==============================================================================*/

#include "globaldefs.h"
#include "protodefs.h"


void StartOutput(void)
{
    if (! strnull(cmd.options))
        fprintf(stdout,"\n\toptions: %s\n", cmd.options);
    
}

// I/O directories:
global void setFilesDirs_log(void)
{
    char buf[200];
    
    sprintf(gd.tmpDir,"tmp");
    
    sprintf(buf,"if [ ! -d %s ]; then mkdir %s; fi",gd.tmpDir,gd.tmpDir);
    system(buf);
    
    sprintf(gd.logfilePath,"%s/interpol.log",gd.tmpDir);
}

global void setFilesDirs(void)
{
    char buf[200];
    
    sprintf(gd.clptDir,"Output");
    sprintf(buf,"if [ ! -d %s ]; then mkdir %s; fi",gd.clptDir,gd.clptDir);
    fprintf(gd.outlog,"system: %s\n",buf);
    system(buf);
    
    sprintf(gd.fpfnamekfun,"Output/kfunctions.dat");
}

void EndRun(void)
{
    char   buf[200];
	FILE *fd;

	fclose(gd.outlog);
    
    printf("\nFinal CPU time : %g sec.\n\n", second() - gd.cpuinit);
}



