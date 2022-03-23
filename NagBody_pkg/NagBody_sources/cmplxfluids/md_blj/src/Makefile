# ----- MAKE FILE FOR md_blj CODE -----
# Copyright (c) 2006-2018  Mario A. Rodriguez-Meza, Ciudad de Mexico.
#
# Se define el directorio en donde est‡n las
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

#OPT8    =  -DOPTIONNAME
#OPT9    =  -DOPTIONNAME
#OPT10   =  -DOPTIONNAME

# THESE OPTIONS IS ON BECAUSE nagbody_struct.h NEEDS gsl/gsl_rng.h
GSL_INCL =  -I/opt/local/include
GSL_LIBS =  -L/opt/local/lib

OPTIONS =  $(OPTIMIZE) \
	   $(OPT1) $(OPT2) $(OPT3) $(OPT4) $(OPT5) $(OPT6) $(OPT7) $(OPT8) \
	   $(OPT9) $(OPT10) $(GSL_INCL) $(GSL_LIBS)

CFLAGS = $(OPTIONS)
LDFLAGS = $(LIBS)

H_PATH = ./general_libs/
#H_PATH = ../../../General_libs/

EXEC = md_blj
#EXEC = md_lj_2d

OBJS	= main.o md_blj_io.o timestep.o startrun.o models.o \
	 nagbody_tree_bljforcecalc.o \
	 nagbody.o nagbody_tree.o nagbody_io.o \
	 $(H_PATH)clib.o $(H_PATH)getparam.o $(H_PATH)mathfns.o $(H_PATH)numrec.o \
	 $(H_PATH)inout.o $(H_PATH)mathutil.o $(H_PATH)lic.o

#	 $(H_PATH)general/clib.o $(H_PATH)general/getparam.o $(H_PATH)math/mathfns.o $(H_PATH)math/numrec.o \
#	 $(H_PATH)io/inout.o $(H_PATH)math/mathutil.o $(H_PATH)general/lic.o

INCL	= globaldefs.h cmdline_defs.h protodefs.h \
	 nagbody.h nagbody_struct.h nagbody_proto.h \
	 $(H_PATH)getparam.h $(H_PATH)machines.h $(H_PATH)inout.h $(H_PATH)precision.h \
	 $(H_PATH)mathfns.h $(H_PATH)mathutil.h $(H_PATH)stdinc.h $(H_PATH)strings.h \
	 $(H_PATH)vectdefs.h $(H_PATH)vectmath.h $(H_PATH)numrec.h $(H_PATH)lic.h \
	 $(H_PATH)constant.h $(H_PATH)physconstants.h $(H_PATH)switchs.h

#	 $(H_PATH)general/getparam.h $(H_PATH)general/machines.h $(H_PATH)io/inout.h $(H_PATH)general/precision.h \
#	 $(H_PATH)math/mathfns.h $(H_PATH)math/mathutil.h $(H_PATH)general/stdinc.h $(H_PATH)general/strings.h \
#	 $(H_PATH)math/vectdefs.h $(H_PATH)math/vectmath.h $(H_PATH)math/numrec.h $(H_PATH)general/lic.h \
#	 $(H_PATH)general/constant.h $(H_PATH)physics/physconstants.h $(H_PATH)general/switchs.h

$(EXEC): $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $(EXEC)

$(OBJS): $(INCL) 

.PHONY : clean
clean:
	rm -f $(OBJS) $(EXEC)

