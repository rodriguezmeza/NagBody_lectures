/*==============================================================================
 HEADER: protodefs.h				[mgpt]
 ==============================================================================*/

#ifndef _protodefs_h
#define _protodefs_h

void MainLoop(void);
void StartRun(string, string, string, string);
void StartOutput(void);
void EndRun(void);

// I/O directories:
global void setFilesDirs_log(void);
global void setFilesDirs(void);

global  real psInterpolation_nr(real k, double kPS[], double pPS[], int nPS);
//

#endif // ! _protodefs_h
