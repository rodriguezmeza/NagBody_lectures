# ----- MAKE FILE FOR nplot2d CODE --------------------------
# Copyright (c) 2006-2022  M.A. Rodriguez-Meza, Mexico, D.F.
#
# define directory where can be found a particular system
MACHINES_DIR = ../../../../Machines/
include $(MACHINES_DIR)machine.inc

# Define local options to this code
# 	OPT1 -- OPT10
# Use as many OPT as you need

#OPT1    =  -DOPTIONNAME     
#OPT2    =  -DOPTIONNAME     
#OPT7    =  -I /opt/local/include/plplot/
OPT7    =  -I $(HOME)/NagBody_lectures/NagBody_pkg/local/include/plplot/
#
#PKG_CONFIG_ENV = PKG_CONFIG_PATH=/opt/local/lib/pkgconfig
PKG_CONFIG_ENV = PKG_CONFIG_PATH=$(HOME)/NagBody_lectures/NagBody_pkg/local/lib/pkgconfig
LIB_TAG =
RPATHCMD = 

OPTIONS =  $(OPTIMIZE) $(OPT1) $(OPT2) $(OPT3) $(OPT4) $(OPT5) $(OPT6)\
	$(OPT7) $(OPT8) $(OPT9) $(OPT10)

CFLAGS = $(OPTIONS)
LDFLAGS = $(LIBS)

H_PATH = ./general_libs/

EXEC = nplot2d

OBJS	= main.o nplot2dio.o nplot2d.o startrun.o \
	$(H_PATH)general/clib.o $(H_PATH)general/getparam.o $(H_PATH)general/lic.o \
	$(H_PATH)math/mathfns.o $(H_PATH)math/numrec.o $(H_PATH)io/inout.o

INCL	= globaldefs.h cmdlinedefs.h protodefs.h $(H_PATH)visual/pldefs.h \
	 $(H_PATH)general/stdinc.h $(H_PATH)math/vectdefs.h $(H_PATH)general/getparam.h \
	 $(H_PATH)general/lic.h $(H_PATH)general/machines.h $(H_PATH)general/switchs.h \
	 $(H_PATH)general/machines.h $(H_PATH)math/mathfns.h $(H_PATH)math/numrec.h $(H_PATH)math/vectmath.h \
	 $(H_PATH)general/precision.h $(H_PATH)NagBody/nagbody_struct.h \
	 $(H_PATH)io/inout.h $(H_PATH)NagBody/nagbody.h $(H_PATH)NagBody/nagbody_proto.h 


$(EXEC): $(OBJS)
	$(CC) $(OBJS) $(LIBS) $(LDFLAGS) -o $(EXEC) $(RPATHCMD) `$(PKG_CONFIG_ENV) pkg-config --cflags --libs plplot$(LIB_TAG)`

$(OBJS): $(INCL) 

.PHONY : clean
clean:
	rm -f $(OBJS) $(EXEC)

