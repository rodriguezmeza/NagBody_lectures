/*==============================================================================
 HEADER: cmdline_defs.h		[interpolation]
*/

#ifndef _cmdline_defs_h
#define _cmdline_defs_h

#define HEAD1	""
#define HEAD2	"interpolation code."
#define HEAD3	"..."

string defv[] = {  ";"HEAD1": " HEAD2 "\n\t " HEAD3,
    "paramfile=",                   ";Parameter input file. Overwritten by what follows",
//
// Power spectrum table:
    "fnamePS=psLCDM.in",		    ";Input filename with the linear power spectrum table (k,P(k))",
    "kmin=1e-3",                    ";kmin to compute the power spectrum",
    "kmax=100",                     ";kmax to compute the power spectrum",
    "Nk=200",                       ";Total number of k in the power spectrum",":nk",
//
    "kin=1.0",                     ";k to compute an interpolated value of the power spectrum",
//
    "options=",                     ";Various control options", ":opt",
//
    "Version=1.0.0",                ";Mario A. Rodríguez-Meza/Alejandro Aviles 2018",
    NULL,
};

#endif // ! _cmdline_defs_h
