/* config.h.  Generated by configure.  */
/* config.h.in.  Generated automatically from configure.in by autoheader.  */
/* diff $NEMO/config.h $NEMOLIB */

/* Define to empty if the keyword does not work.  */
/* #undef const */

/* Define to the type of elements in the array set by `getgroups'.
   Usually this is either `int' or `gid_t'.  */
#define GETGROUPS_T gid_t

/* Define to `int' if <sys/types.h> doesn't define.  */
/* #undef gid_t */

/* Define if you don't have vprintf but do have _doprnt.  */
/* #undef HAVE_DOPRNT */

/* Define if you have a working `mmap' system call.  */
#define HAVE_MMAP 1

/* Define if you have <sys/wait.h> that is POSIX.1 compatible.  */
#define HAVE_SYS_WAIT_H 1

/* Define if you have <vfork.h>.  */
/* #undef HAVE_VFORK_H */

/* Define if you have the vprintf function.  */
#define HAVE_VPRINTF 1

/* Define as __inline if that's what the C compiler calls it.  */
/* #undef inline */

/* Define to `long' if <sys/types.h> doesn't define.  */
/* #undef off_t */

/* Define to `int' if <sys/types.h> doesn't define.  */
/* #undef pid_t */

/* Define as the return type of signal handlers (int or void).  */
#define RETSIGTYPE void

/* Define to `unsigned' if <sys/types.h> doesn't define.  */
/* #undef size_t */

/* Define if you have the ANSI C header files.  */
#define STDC_HEADERS 1

/* Define if you can safely include both <sys/time.h> and <time.h>.  */
#define TIME_WITH_SYS_TIME 1

/* Define if your <sys/time.h> declares struct tm.  */
/* #undef TM_IN_SYS_TIME */

/* Define to `int' if <sys/types.h> doesn't define.  */
/* #undef uid_t */

/* Define vfork as fork if vfork does not work.  */
/* #undef vfork */

/* Define if you have the ftime function.  */
#define HAVE_FTIME 1

/* Define if you have the gethostname function.  */
#define HAVE_GETHOSTNAME 1

/* Define if you have the getpagesize function.  */
#define HAVE_GETPAGESIZE 1

/* Define if you have the gettimeofday function.  */
#define HAVE_GETTIMEOFDAY 1

/* Define if you have the getwd function.  */
#define HAVE_GETWD 1

/* Define if you have the mkdir function.  */
#define HAVE_MKDIR 1

/* Define if you have the select function.  */
#define HAVE_SELECT 1

/* Define if you have the strdup function.  */
#define HAVE_STRDUP 1

/* Define if you have the strtod function.  */
#define HAVE_STRTOD 1

/* Define if you have the strtol function.  */
#define HAVE_STRTOL 1

/* Define if you have the strtoul function.  */
#define HAVE_STRTOUL 1

/* Define if you have the dprintf function.  */
/* #undef HAVE_DPRINTF */

/* Define if you have the log2 function.  */
#define HAVE_LOG2 1

/* Define if you have the <dirent.h> header file.  */
#define HAVE_DIRENT_H 1

/* Define if you have the <fcntl.h> header file.  */
#define HAVE_FCNTL_H 1

/* Define if you have the <limits.h> header file.  */
#define HAVE_LIMITS_H 1

/* Define if you have the <malloc.h> header file.  */
/* #undef HAVE_MALLOC_H */

/* Define if you have the <ndir.h> header file.  */
/* #undef HAVE_NDIR_H */

/* Define if you have the <sgtty.h> header file.  */
#define HAVE_SGTTY_H 1

/* Define if you have the <strings.h> header file.  */
#define HAVE_STRINGS_H 1

/* Define if you have the <sys/dir.h> header file.  */
/* #undef HAVE_SYS_DIR_H */

/* Define if you have the <sys/file.h> header file.  */
#define HAVE_SYS_FILE_H 1

/* Define if you have the <sys/ioctl.h> header file.  */
#define HAVE_SYS_IOCTL_H 1

/* Define if you have the <sys/ndir.h> header file.  */
/* #undef HAVE_SYS_NDIR_H */

/* Define if you have the <sys/time.h> header file.  */
#define HAVE_SYS_TIME_H 1

/* Define if you have the <unistd.h> header file.  */
#define HAVE_UNISTD_H 1

/* Define if you have the Accessx library (-lAccessx).  */
/* #undef HAVE_LIBACCESSX */

/* Define if you have the X11 library (-lX11).  */
/* #undef HAVE_LIBX11 */

/* Define if you have the df library (-ldf).  */
/* #undef HAVE_LIBDF */

/* Define if you have the f2c library (-lf2c).  */
/* #undef HAVE_LIBF2C */

/* Define if you have the pgplot library (-lpgplot).  */
#define HAVE_LIBPGPLOT 1

/* Define if you have the readline library (-lreadline).  */
#define HAVE_LIBREADLINE 1

/* Define if you have the readline library (-lhistory).  */
/* #undef HAVE_LIBHISTORY */

/* Define if you have the gsl library (-lgsl).  */
/* #undef HAVE_LIBGSL */

/* Define if you have the cfitsio library (-lcfitsio).  */
/* #undef HAVE_LIBCFITSIO */

/* Define if you have the vogl library (-lvogl).  */
/* #undef HAVE_LIBVOGL */

/* Define if you have the yapp_x library (-lyapp_x).  */
/* #undef HAVE_LIBYAPP_X */

/* Define if you have the z library (-lz).  */
#define HAVE_LIBZ 1

/* Define this if your machine is big endian (like Sparcs) */
#define WORDS_BIGENDIAN 1

/* The size of a `float', as computed by sizeof. */
#define SIZEOF_FLOAT 4

/* The size of a `double', as computed by sizeof. */
#define SIZEOF_DOUBLE 8

/* The size of a `int', as computed by sizeof. */
#define SIZEOF_INT 4

/* The size of a `long', as computed by sizeof. */
#define SIZEOF_LONG 4

/* The size of a `long long', as computed by sizeof. */
#define SIZEOF_LONG_LONG 8



/* Fortran unformatted I/O header size (should be 4 or 8) */
#define UNFIO_HDR_SIZE 4


/* define to specify how to mangle identifiers for the Fortran linker: */
#define FORTRANIZE_LOWERCASE 0
#define FORTRANIZE_UPPERCASE 0
#define FORTRANIZE_LOWERCASE_UNDERSCORE 1 /* the default */
#define FORTRANIZE_UPPERCASE_UNDERSCORE 0
#define FORTRANIZE_EXTRA_UNDERSCORE 0

#if FORTRANIZE_LOWERCASE
#  define F77_FUNC(x,X) x
#elif FORTRANIZE_UPPERCASE
#  define F77_FUNC(x,X) X
#elif FORTRANIZE_LOWERCASE_UNDERSCORE
#  define F77_FUNC(x,X) x##_
#elif FORTRANIZE_UPPERCASE_UNDERSCORE
#  define F77_FUNC(x,X) X##_
#endif

