# ----- MAKE FILE FOR starscream CODE -----
# Copyright (c) 2006-2013  M.A. Rodriguez-Meza, Mexico, D.F.
#
# Se define el directorio en donde estan las
# definiciones de las arquitecturas particulares.
MACHINES_DIR = ../../../../Machines/
include $(MACHINES_DIR)machine.inc

# Se definen opciones locales de este codigo
# 	OPT1 -- OPT10
# La serie de opciones OPT11 -- OPT20 y OPTIMIZE son para la arquitectura 
# particular y estan en el archivo machine.inc o pmachine.inc
#
#OPT1    =  -DOPTIONNAME
#OPT2    =  -DOPTIONNAME
#OPT3    =  -DOPTIONNAME
#OPT4    =  -DOPTIONNAME
#OPT5    =  -DOPTIONNAME
#OPT6    =  -DOPTIONNAME

#OPT7    =  -I $(HOME)/plplot/include/plplot/

#OPT8    =  -I $(HOME)/NagBody_pkg/local/gsl/include
OPT8    =  -I /opt/local/include
#OPT9    =  -I $(HOME)/NagBody_pkg/local/fftw3/include
#OPT10    =  -L $(HOME)/NagBody_pkg/local/fftw3/lib
#OPT9    =  -DOPTIONNAME
#OPT10   =  -DOPTIONNAME

OPTIONS =  $(OPTIMIZE) \
	   $(OPT1) $(OPT2) $(OPT3) $(OPT4) $(OPT5) $(OPT6) $(OPT7) $(OPT8) \
	   $(OPT9) $(OPT10) $(OPT11) $(OPT12) $(OPT13) $(OPT14) $(OPT15) \
           $(OPT16) $(OPT17) $(OPT18) $(OPT19) $(OPT20)

#GSL_CFLAGS = -I$(HOME)/NagBody_pkg/local/gsl/include 
#GSL_LIBS   = -L$(HOME)/NagBody_pkg/local/gsl/lib -lgsl -lgslcblas -lm 
GSL_CFLAGS = -I/opt/local/include 
GSL_LIBS   = -L/opt/local/lib -lgsl -lgslcblas -lm 
#FFTW_CFLAGS = -I/opt/local/include 
#FFTW_LIBS = -L/opt/local/lib -lfftw3 -lm  -lfftw3_threads
#FFTW_LIBS = -L/opt/local/lib -lfftw3 -lm
OPENMPFLAG = -fopenmp

CFLAGS = $(OPTIONS) $(GSL_CFLAGS) $(FFTW_CFLAGS) $(OPENMPFLAG)
LDFLAGS = $(LIBS)

#PRECISION = DOUBLEPREC

H_PATH = ./general_libs/
#H_PATH = ../../../General_libs/

EXEC = galaxy_starscream

OBJS	= starscream.o starscream_init.o starscream_io.o \
	main.o startrun.o \
	$(H_PATH)general/clib.o $(H_PATH)general/getparam.o

INCL	= starscream.h Makefile \
	globaldefs.h cmdline_defs.h protodefs.h \
	$(H_PATH)general/getparam.h \
	$(H_PATH)general/switchs.h $(H_PATH)general/machines.h \
	$(H_PATH)general/stdinc.h $(H_PATH)general/precision.h
	

$(EXEC): $(OBJS) 
	$(CC) $(OBJS) $(LIBS) $(GSL_LIBS) $(OPENMPFLAG) $(OPT10) -o $(EXEC)

#	$(CC) $(OBJS) $(LIBS) $(GSL_LIBS) $(FFTW_LIBS) $(OPENMPFLAG) $(OPT10) -o $(EXEC)

$(OBJS): $(INCL)

.PHONY : clean
clean:
	rm -f $(OBJS) $(EXEC)

