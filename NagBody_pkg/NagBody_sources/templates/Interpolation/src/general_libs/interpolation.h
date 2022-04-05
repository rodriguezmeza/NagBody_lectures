
#ifndef _interpolation_h
#define _interpolation_h

#include "stdinc.h"


void spline(double x[], double y[], int n, double yp1, double ypn, double y2[]);
void splint(double xa[], double ya[], double y2a[], int n, double x, double *y);


#endif // ! _interpolation_h


