# Makefile main_exe MODELS
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

OPT8    =  -I $(HOME)/NagBody_pkg/local/gsl/include
#OPT9    =  -DOPTIONNAME
#OPT10   =  -DOPTIONNAME
# TO SOLVE LINKING ERROR:
# ld: library not found for -lSystem
OPT9    =  -I/Applications/Xcode.app//Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include
OPT10   =  -L/Applications/Xcode.app//Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/lib

GSL_INCL =  -I$(HOME)/NagBody_pkg/local/gsl/include
GSL_LIBS =  -L$(HOME)/NagBody_pkg//local/gsl/lib


OPTIONS =  $(OPTIMIZE) $(OPT1) $(OPT2) $(OPT3) $(OPT4) $(OPT5) $(OPT6)\
           $(OPT7) $(OPT8) $(OPT9) $(OPT10) $(OPT11) $(OPT12) $(OPT13)\
	   $(OPT14) $(OPT15) $(GSL_INCL) $(GSL_LIBS)

EXEC   = model

H_PATH = ./general_libs/
#NEMOPATH = $(H_PATH)nemo/

OBJS   = main.o models_io.o models.o \
	 startrun.o galaxy.o \
	 $(H_PATH)nagbody.o \
	 $(H_PATH)nagbody_tree.o \
	 $(H_PATH)nagbody_io.o \
	 $(H_PATH)clib.o \
	 $(H_PATH)getparam.o \
	 $(H_PATH)inout.o \
	 $(H_PATH)mathfns.o \
	 $(H_PATH)mathutil.o \
	 $(H_PATH)numrec.o

#	 $(H_PATH)/NagBody/nagbody.o \
#	 $(H_PATH)/NagBody/nagbody_tree.o \
#	 $(H_PATH)/NagBody/nagbody_io.o \
#	 $(H_PATH)/general/clib.o \
#	 $(H_PATH)/general/getparam.o \
#	 $(H_PATH)/io/inout.o \
#	 $(H_PATH)/math/mathfns.o \
#	 $(H_PATH)/math/mathutil.o \
#	 $(H_PATH)/math/numrec.o

#	 $(NEMOPATH)src/kernel/io/filesecret.o $(NEMOPATH)src/kernel/io/extstring.o \
#	 $(NEMOPATH)src/kernel/io/history.o $(NEMOPATH)src/kernel/cores/bswap.o \
#	 $(NEMOPATH)src/kernel/io/convert.o $(NEMOPATH)src/kernel/io/dprintf.o \
#	 $(NEMOPATH)src/kernel/cores/error.o $(NEMOPATH)src/kernel/cores/strlib.o \
#	 $(NEMOPATH)src/kernel/io/stropen.o $(NEMOPATH)src/kernel/io/getparam.o \
#	 $(NEMOPATH)src/kernel/misc/nemoinp.o $(NEMOPATH)src/kernel/cores/date_id.o \
#	 $(NEMOPATH)src/kernel/cores/file_size.o $(NEMOPATH)src/kernel/io/outdefv.o \
#	 $(NEMOPATH)src/kernel/cores/filefn.o $(NEMOPATH)src/kernel/cores/burststring.o \
#	 $(NEMOPATH)src/kernel/misc/herinp.o $(NEMOPATH)src/kernel/misc/setfblank.o

INCL   = cmdline_defs.h \
	 protodefs.h switches.h globaldefs.h models.h \
	 $(H_PATH)nagbody.h \
	 $(H_PATH)nagbody_struct.h \
	 $(H_PATH)nagbody_proto.h \
	 $(H_PATH)constant.h \
	 $(H_PATH)getparam.h \
	 $(H_PATH)machines.h \
	 $(H_PATH)param.h \
	 $(H_PATH)precision.h \
	 $(H_PATH)stdinc.h \
	 $(H_PATH)strings.h \
	 $(H_PATH)times.h \
	 $(H_PATH)switchs.h \
	 $(H_PATH)inout.h \
	 $(H_PATH)mathfns.h \
	 $(H_PATH)mathutil.h \
	 $(H_PATH)numrec.h \
	 $(H_PATH)vectdefs.h \
	 $(H_PATH)vectmath.h

#	 $(H_PATH)NagBody/nagbody.h \
#	 $(H_PATH)NagBody/nagbody_struct.h \
#	 $(H_PATH)NagBody/nagbody_proto.h \
#	 $(H_PATH)general/constant.h \
#	 $(H_PATH)general/getparam.h \
#	 $(H_PATH)general/machines.h \
#	 $(H_PATH)general/param.h \
#	 $(H_PATH)general/precision.h \
#	 $(H_PATH)general/stdinc.h \
#	 $(H_PATH)general/strings.h \
#	 $(H_PATH)general/times.h \
#	 $(H_PATH)general/switchs.h \
#	 $(H_PATH)/io/inout.h \
#	 $(H_PATH)/math/mathfns.h \
#	 $(H_PATH)/math/mathutil.h \
#	 $(H_PATH)/math/numrec.h \
#	 $(H_PATH)/math/vectdefs.h \
#	 $(H_PATH)/math/vectmath.h

#	 $(NEMOPATH)include/stdinc.h $(NEMOPATH)include/strlib.h \
#	 $(NEMOPATH)include/filestruct.h $(NEMOPATH)include/history.h \
#	 $(NEMOPATH)include/extstring.h $(NEMOPATH)include/getparam.h \
#	 $(NEMOPATH)src/kernel/io/filesecret.h $(NEMOPATH)src/tools/unproto/stdarg.h \
#	 $(NEMOPATH)src/kernel/misc/gipsyc.h \
#	 $(NEMOPATH)include/snapshot/snapshot.h $(NEMOPATH)include/snapshot/body.h \
#	 $(NEMOPATH)include/snapshot/put_snap.c $(NEMOPATH)include/snapshot/put_snap-old.c \
#	 $(NEMOPATH)include/version.h $(NEMOPATH)include/options.h $(NEMOPATH)include/mathfns.h \
#	 $(NEMOPATH)include/filefn.h $(NEMOPATH)lib/maxsizes.h $(NEMOPATH)lib/config.h

CFLAGS =   $(OPTIONS)

$(EXEC): $(OBJS) 
	$(CC) $(OPTIONS) $(OBJS) $(LIBS)   -o  $(EXEC)  

$(OBJS): $(INCL) 

.PHONY : clean
clean:
	rm -f $(OBJS) $(EXEC)
