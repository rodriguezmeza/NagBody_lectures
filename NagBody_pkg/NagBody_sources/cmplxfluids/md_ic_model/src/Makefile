# ----- MAKE FILE FOR md_ic_model CODE -----
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

OPT8    =  -I $(HOME)/NagBody_pkg/local/gsl/include
#OPT9    =  -DOPTIONNAME
#OPT10   =  -DOPTIONNAME

OPTIONS =  $(OPTIMIZE) \
	   $(OPT1) $(OPT2) $(OPT3) $(OPT4) $(OPT5) $(OPT6) $(OPT7) $(OPT8) \
	   $(OPT9) $(OPT10) $(OPT11) $(OPT12) $(OPT13) $(OPT14) $(OPT15) \
           $(OPT16) $(OPT17) $(OPT18) $(OPT19) $(OPT20)

CFLAGS = $(OPTIONS)
LDFLAGS = $(LIBS)

H_PATH = ./general_libs/
#H_PATH = ../../../General_libs/
NEMOPATH = $(H_PATH)nemo/

EXEC = md_ic_model

OBJS	= main.o md_blj_io.o timestep.o startrun.o models.o \
	 bljforcecalc.o \
	 $(H_PATH)NagBody/nagbody.o $(H_PATH)NagBody/nagbody_tree.o $(H_PATH)NagBody/nagbody_io.o \
	 $(H_PATH)general/clib.o $(H_PATH)general/getparam.o $(H_PATH)math/mathfns.o $(H_PATH)math/numrec.o \
	 $(H_PATH)io/inout.o $(H_PATH)math/mathutil.o $(H_PATH)general/lic.o \
	 $(NEMOPATH)src/kernel/io/filesecret.o $(NEMOPATH)src/kernel/io/extstring.o \
	 $(NEMOPATH)src/kernel/io/history.o $(NEMOPATH)src/kernel/cores/bswap.o \
	 $(NEMOPATH)src/kernel/io/convert.o $(NEMOPATH)src/kernel/io/dprintf.o \
	 $(NEMOPATH)src/kernel/cores/error.o $(NEMOPATH)src/kernel/cores/strlib.o \
	 $(NEMOPATH)src/kernel/io/stropen.o $(NEMOPATH)src/kernel/io/getparam.o \
	 $(NEMOPATH)src/kernel/misc/nemoinp.o $(NEMOPATH)src/kernel/cores/date_id.o \
	 $(NEMOPATH)src/kernel/cores/file_size.o $(NEMOPATH)src/kernel/io/outdefv.o \
	 $(NEMOPATH)src/kernel/cores/filefn.o $(NEMOPATH)src/kernel/cores/burststring.o \
	 $(NEMOPATH)src/kernel/misc/herinp.o $(NEMOPATH)src/kernel/misc/setfblank.o

# 

INCL	= globaldefs.h cmdline_defs.h protodefs.h \
	 $(H_PATH)NagBody/nagbody.h $(H_PATH)NagBody/nagbody_struct.h $(H_PATH)NagBody/nagbody_proto.h \
	 $(H_PATH)general/getparam.h $(H_PATH)general/machines.h $(H_PATH)io/inout.h $(H_PATH)general/precision.h \
	 $(H_PATH)math/mathfns.h $(H_PATH)math/mathutil.h $(H_PATH)general/stdinc.h $(H_PATH)general/strings.h \
	 $(H_PATH)math/vectdefs.h $(H_PATH)math/vectmath.h $(H_PATH)math/numrec.h $(H_PATH)general/lic.h \
	 $(H_PATH)general/constant.h $(H_PATH)physics/physconstants.h $(H_PATH)general/switchs.h \
	 $(NEMOPATH)include/stdinc.h $(NEMOPATH)include/strlib.h \
	 $(NEMOPATH)include/filestruct.h $(NEMOPATH)include/history.h \
	 $(NEMOPATH)include/extstring.h $(NEMOPATH)include/getparam.h \
	 $(NEMOPATH)src/kernel/io/filesecret.h $(NEMOPATH)src/tools/unproto/stdarg.h \
	 $(NEMOPATH)src/kernel/misc/gipsyc.h \
	 $(NEMOPATH)include/snapshot/snapshot.h $(NEMOPATH)include/snapshot/body.h \
	 $(NEMOPATH)include/snapshot/put_snap.c $(NEMOPATH)include/snapshot/put_snap-old.c \
	 $(NEMOPATH)include/version.h $(NEMOPATH)include/options.h $(NEMOPATH)include/mathfns.h \
	 $(NEMOPATH)include/filefn.h $(NEMOPATH)lib/maxsizes.h $(NEMOPATH)lib/config.h

$(EXEC): $(OBJS) 
	$(CC) $(OBJS) $(LIBS) -o $(EXEC)

$(OBJS): $(INCL) 

.PHONY : clean
clean:
	rm -f $(OBJS) $(EXEC)

