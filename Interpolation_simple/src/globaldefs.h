/*==============================================================================
 HEADER: globaldefs.h		[interpolation]
 ==============================================================================*/

#ifndef _globaldefs_h
#define _globaldefs_h

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
//

#include "general_libs/stdinc.h"
#include "general_libs/numrec.h"
#include "general_libs/interpolation.h"
#include "general_libs/mathfns.h"
#include "general_libs/mathutil.h"
#include "general_libs/inout.h"
#include "general_libs/getparam.h"

#if !defined(global)
#  define global extern
#endif

#define IPName(param,paramtext)    \
{strcpy(tag[nt],paramtext);    \
addr[nt]=&(param);    \
id[nt++]=INT;}

#define RPName(param,paramtext)    \
{strcpy(tag[nt],paramtext);    \
addr[nt]=&param;    \
id[nt++]=DOUBLE;}

#define BPName(param,paramtext)    \
{strcpy(tag[nt],paramtext);    \
addr[nt]=&param;    \
id[nt++]=BOOLEAN;}

#define SPName(param,paramtext,n)    \
{strcpy(tag[nt],paramtext);    \
param=(string) malloc(n);    \
addr[nt]=param;    \
id[nt++]=STRING;}
//

#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FOURPI2   39.4784176043574
#define PI2     9.8696044010893586188
#define TWOPI2     19.739208802178716
#define SIXPI2  59.21762640653615
#define INVSQRTDTWOPI 0.39894228040143267794

typedef struct {

// Power spectrum table
    string fnamePS;
    real kmin;
    real kmax;
    int Nk;
//
    real kin;
//
    string options;
//
    string paramfile;
//
} cmdline_data, *cmdline_data_ptr;

typedef struct {
	real cpuinit;

	string headline0;
	string headline1;
	string headline2;
	string headline3;

	FILE *outlog;

	char mode[2];

// 
    char fnamePSPath[100];
    char logfilePath[100];
    char clptDir[100];
    char tmpDir[100];
    char fpfnamekfun[100];

} global_data, *global_data_ptr;


global global_data gd;
global cmdline_data cmd;

typedef struct _pointPSTable {
    real k;
    real ps;
} pointPSTable, *pointPSTableptr;

global int nPSTable;
global pointPSTableptr PSLCDMtab;
global int nPSLogT;
global pointPSTableptr PSLCDMLogtab;

global int nPSLT;
global pointPSTableptr PSLT;
global int nPSLTLog;
global pointPSTableptr PSLTLog;

global real *kPS;
global real *pPS;
global real *pPS2;


#define kPos(x)    (((pointPSTableptr) (x))->k)
#define PS(x)    (((pointPSTableptr) (x))->ps)

// STATIC problem: gcc version 11
// From inout.h
global real *inout_xval;
global real *inout_yval;
global real *inout_zval;
global real *inout_wval;

// STATIC problem: gcc version 11
// From stdinc.h
global long idum;                // seed for random generators

#endif // ! _globaldefs_h

