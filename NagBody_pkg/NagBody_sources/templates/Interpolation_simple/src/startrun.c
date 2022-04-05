/*==============================================================================
 MODULE: startrun.c				
 ==============================================================================*/

#include "globaldefs.h"
#include "protodefs.h"


local void ReadParameterFile(char *);
local void PrintParameterFile(char *);

local void startrun_parameterfile(void);
local void startrun_cmdline(void);
local void ReadParametersCmdline(void);
local void startrun_Common(void);
local void startrun_ParamStat(void);
local void CheckParameters(void);

void StartRun(string head0, string head1, string head2, string head3)
{
    real aTime;
    aTime = second();
    
    gd.headline0 = head0; gd.headline1 = head1;
    gd.headline2 = head2; gd.headline3 = head3;
    printf("\n%s\n%s: %s\n\t %s\n",
		gd.headline0, gd.headline1, gd.headline2, gd.headline3);

    cmd.paramfile = GetParam("paramfile");
    if (!strnull(cmd.paramfile))
		startrun_parameterfile();
	else
		startrun_cmdline();

    StartOutput();

    fprintf(gd.outlog,"\nStartRun elapsed time: %g sec.\n\n",second()-aTime);
    fflush(gd.outlog);
}

local void startrun_parameterfile(void)
{
	ReadParameterFile(cmd.paramfile);
    startrun_ParamStat();
	startrun_Common();
	PrintParameterFile(cmd.paramfile);
}

#define parameter_null	"parameters_null-mgpt"

local void startrun_cmdline(void)
{
	ReadParametersCmdline();
	startrun_Common();
	PrintParameterFile(parameter_null);
}

local void ReadParametersCmdline(void)
{
// Power spectrum table:
    cmd.fnamePS = GetParam("fnamePS");
    cmd.kmin = GetdParam("kmin");
    cmd.kmax = GetdParam("kmax");
    cmd.Nk = GetiParam("Nk");
//
    cmd.kin= GetdParam("kin");
//
    cmd.options = GetParam("options");
}

#undef parameter_null

local void startrun_Common(void)
{
	real dx1, dx2;
    char *ep;

    setFilesDirs_log();
    strcpy(gd.mode,"w");
	if(!(gd.outlog=fopen(gd.logfilePath, gd.mode)))
		error("\nstart_Common: error opening file '%s' \n",gd.logfilePath);

//
    CheckParameters();

    setFilesDirs();
}

local void startrun_ParamStat(void)
{
// Power spectrum table:
    if (GetParamStat("fnamePS") & ARGPARAM)
        cmd.fnamePS = GetParam("fnamePS");
    if (GetParamStat("kmin") & ARGPARAM)
        cmd.kmin = GetdParam("kmin");
    if (GetParamStat("kmax") & ARGPARAM)
        cmd.kmax = GetdParam("kmax");
    if (GetParamStat("Nk") & ARGPARAM)
        cmd.Nk = GetiParam("Nk");

    if (GetParamStat("kin") & ARGPARAM)
        cmd.kin = GetdParam("kin");

    if (GetParamStat("options") & ARGPARAM)
        cmd.options = GetParam("options");
}

local void CheckParameters(void)
{
// Power spectrum table:
    if (strnull(cmd.fnamePS))
        error("CheckParameters: You should give a power spectrum filename\n");
    if (cmd.kmin < 0.0)
        error("CheckParameters: absurd value for kmin\n");
    if (cmd.kmax < 0.0)
        error("CheckParameters: absurd value for kmax\n");
    if (cmd.kmin > cmd.kmax)
        error("CheckParameters: kmin can not be greater than kmax\n");
    if (cmd.Nk < 0)
        error("CheckParameters: absurd value for Nk\n");
//
    if (cmd.kin < 0.0)
        error("CheckParameters: absurd value for kin\n");
}

local void ReadParameterFile(char *fname)
{
#define DOUBLE 1
#define STRING 2
#define INT 3
#define BOOLEAN 4
#define MAXTAGS 300

  FILE *fd,*fdout;

  char buf[200],buf1[200],buf2[200],buf3[200];
  int  i,j,nt;
  int  id[MAXTAGS];
  void *addr[MAXTAGS];
  char tag[MAXTAGS][50];
  int  errorFlag=0;

  nt=0;

// Power spectrum table:
    SPName(cmd.fnamePS,"fnamePS",100);
    RPName(cmd.kmin,"kmin");
    RPName(cmd.kmax,"kmax");
    IPName(cmd.Nk,"Nk");
//
    RPName(cmd.kin,"kin");
//
    SPName(cmd.options,"options",100);
//

	if((fd=fopen(fname,"r"))) {
		while(!feof(fd)) {
			fgets(buf,200,fd);
            if(sscanf(buf,"%s%s%s",buf1,buf2,buf3)<1)
                continue;
            if(sscanf(buf,"%s%s%s",buf1,buf2,buf3)<2)
                *buf2='\0';
            if(buf1[0]=='%')
				continue;
            for(i=0,j=-1;i<nt;i++)
                if(strcmp(buf1,tag[i])==0) {
                    j=i;
					tag[i][0]=0;
					break;
				}
			if(j>=0) {
                switch(id[j]) {
					case DOUBLE:
						*((double*)addr[j])=atof(buf2); 
						break;
					case STRING:
						strcpy(addr[j],buf2);
						break;
					case INT:
						*((int*)addr[j])=atoi(buf2);
						break;
					case BOOLEAN:
						if (strchr("tTyY1", *buf2) != NULL) {          
							*((bool*)addr[j])=TRUE;
                        } else 
                            if (strchr("fFnN0", *buf2) != NULL)  {
                                *((bool*)addr[j])=FALSE;
                            } else {
                                error("getbparam: %s=%s not bool\n",buf1,buf2);
                            }
						break;
                }
            } else {
                fprintf(stdout, "Error in file %s: Tag '%s' %s.\n",
					fname, buf1, "not allowed or multiple defined");
                errorFlag=1;
            }
        }
        fclose(fd);
    } else {
        fprintf(stdout,"Parameter file %s not found.\n", fname);
        errorFlag=1;
        exit(1); 
    }
  
    for(i=0;i<nt;i++) {
        if(*tag[i]) {
            fprintf(stdout,
                "Error. I miss a value for tag '%s' in parameter file '%s'.\n",
                tag[i],fname);
            exit(0);
        }
    }
#undef DOUBLE 
#undef STRING 
#undef INT 
#undef BOOLEAN
#undef MAXTAGS
}

#define FMTT	"%-35s%s\n"
#define FMTI	"%-35s%d\n"
#define FMTR	"%-35s%g\n"

local void PrintParameterFile(char *fname)
{
    FILE *fdout;
    char buf[200];
    
    sprintf(buf,"%s/%s%s",gd.tmpDir,fname,"-usedvalues");
    if(!(fdout=fopen(buf,"w"))) {
        fprintf(stdout,"error opening file '%s' \n",buf);
        exit(0);
    } else {
        fprintf(fdout,"%s\n",
		"%-------------------------------------------------------------------");
        fprintf(fdout,"%s %s\n","% Parameter input file for:",gd.headline0);
        fprintf(fdout,"%s\n","%");
        fprintf(fdout,"%s %s: %s\n%s\t    %s\n","%",gd.headline1,gd.headline2,"%",
            gd.headline3);
        fprintf(fdout,"%s\n%s\n",
		"%-------------------------------------------------------------------",
		"%");
// Power spectrum table:
        fprintf(fdout,FMTT,"fnamePS",cmd.fnamePS);
        fprintf(fdout,FMTR,"kmin",cmd.kmin);
        fprintf(fdout,FMTR,"kmax",cmd.kmax);
        fprintf(fdout,FMTI,"Nk",cmd.Nk);
//
        fprintf(fdout,FMTR,"kin",cmd.kin);
//
        fprintf(fdout,FMTT,"options",cmd.options);
//
        fprintf(fdout,"\n\n");
    }
    fclose(fdout);
}

#undef FMTT
#undef FMTI
#undef FMTR
