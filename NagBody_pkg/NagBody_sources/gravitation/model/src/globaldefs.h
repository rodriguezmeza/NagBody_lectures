/*==============================================================================
	HEADER: global_defs.h			[model]
	Written by: M.A. Rodriguez-Meza
	Starting date: February 2005
	Purpose: Definitions of global variables and parameters
	Language: C
	Use: '#include "...."
	Use in routines and functions: main, startrun

	External headers:
	Comments and notes:
	Info: M.A. Rodriguez-Meza
		Depto. de Fisica, ININ
		Apdo. Postal 18-1027 Mexico D.F. 11801 Mexico
		e-mail: marioalberto.rodriguez@inin.gob.mx
		http://www.astro.inin.mx/mar

	Major revisions: July 23, 2007
	Copyright: (c) 2005-2011 Mar.  All Rights Reserved
================================================================================
	Legal matters:
	The author does not warrant that the program and routines it contains
	listed below are free from error or suitable for particular applications,
	and he disclaims all liability from any consequences arising from their	use.
==============================================================================*/

#ifndef _globaldefs_h
#define _globaldefs_h

#if HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "switches.h"

#ifndef NOGNU
#include "../../../General_libs/general/stdinc.h"
#include "../../../General_libs/math/vectdefs.h"
#include "../../../General_libs/NagBody/nagbody.h"
#include "../../../General_libs/math/mathfns.h"
#include "../../../General_libs/math/vectmath.h"
#include "../../../General_libs/general/constant.h"
#include "../../../General_libs/math/numrec.h"
#include "../../../General_libs/math/mathutil.h"
#include "../../../General_libs/io/inout.h"
#include "../../../General_libs/general/getparam.h"
#include "../../../General_libs/general/strings.h"
#include "../../../General_libs/physics/physconstants.h"
#include "../../../General_libs/general/machines.h"
#else
#include "stdinc.h"
#include "vectdefs.h"
#include "nagbody.h"
#include "mathfns.h"
#include "vectmath.h"
#include "constant.h"
#include "numrec.h"
#include "mathutil.h"
#include "inout.h"
#include "getparam.h"
#include "strings.h"
#include "physconstants.h"
#include "machines.h"
#endif

#include "models.h"

#include "protodefs.h"


typedef struct {
	string paramfile;

	string in;
	string infmt;
	string out;
	string outfmt;

	int nbody;                       
	string model;

	string options;                  

	real Mtotal;
	real Rmax;
	real vcmx;
	real vcmy;
	real vcmz;
	real cmx;
	real cmy;
	real cmz;
	real absvel;
	real omega0;
	real a_p;
	real m_p;
	real SoundSpeed;
	real a_spheroid;
	real b_spheroid;
	real c_spheroid;

	real factor;
} cmdline_data, *cmdline_data_ptr;

typedef struct {
	real cpuinit;

	string headline0;
	string headline1;
	string headline2;
	string headline3;

	char model_comment[100];

	FILE *outlog;

	real tnow;                       
	real tout;                       
	real freq;                       

	int nstep;                       
	int nstep_grav;					

	int nfiles;
	char *filenames[40];
	int nfilefmts;
	char *filenamefmts[40];

	string headerfmt;

} global_data, *global_data_ptr;


// gcc11 :: To avoid Error :: duplicate symbol '_gd' in:
/*
global global_data gd;
global cmdline_data cmd;
global io_header_blj hdr;
*/
local global_data gd;
local cmdline_data cmd;
local io_header_blj hdr;

#endif // !_globaldefs_h

