/* platform.h

  (c) 1998-2002 (W3C) MIT, INRIA, Keio University
  See tidy.c for the copyright notice.

  CVS Info :

    $Author$ 
    $Date$ 
    $Revision$ 

*/

/*
  Uncomment and edit one of the following #defines if you
  want to specify the config file at compile-time.
*/

/* #define CONFIG_FILE "/etc/tidy_config.txt" */ /* original */
/* #define CONFIG_FILE "/etc/tidyrc" */
/* #define CONFIG_FILE "/etc/tidy.conf" */

/*
  Uncomment the following #define if you are on a Unix system
  supporting the call getpwnam() and the HOME environment variable.
  It enables tidy to find config files named ~/.tidyrc and
  ~your/.tidyrc etc if the HTML_TIDY environment
  variable is not set. Contributed by Todd Lewis.
*/

/* #define SUPPORT_GETPWNAM */

/* Enable/disable support for Big5 and Shift_JIS character encodings */
#ifndef SUPPORT_ASIAN_ENCODINGS
#define SUPPORT_ASIAN_ENCODINGS 0
#endif

/* Enable/disable support for UTF-16 character encodings */
#ifndef SUPPORT_UTF16_ENCODINGS
#define SUPPORT_UTF16_ENCODINGS 0
#endif

/* Enable/disable support for additional accessibility checks */
#ifndef SUPPORT_ACCESSIBILITY_CHECKS
#define SUPPORT_ACCESSIBILITY_CHECKS 1
#endif

/* Enable/disable original accessibility checks */

/* Also at runtime : 
   if !USE_ORIGINAL_ACCESSIBILITY_CHECKS
       if (AccessibilityCheckLevel == 0) then
           do the original accessibility checks anyway
*/

/* If additional accessibility checks are enabled, disable the original accessibility checks by default */
#ifndef USE_ORIGINAL_ACCESSIBILITY_CHECKS
#define USE_ORIGINAL_ACCESSIBILITY_CHECKS 0
#endif

/* If additional accessibility checks are disabled, always enable the original accessibility checks */
#if !SUPPORT_ACCESSIBILITY_CHECKS
#undef USE_ORIGINAL_ACCESSIBILITY_CHECKS
#define USE_ORIGINAL_ACCESSIBILITY_CHECKS 1
#endif

/* Convenience defines for Mac platforms */

#if defined(macintosh)
/* Mac OS 6.x/7.x/8.x/9.x, with or without CarbonLib - MPW or Metrowerks 68K/PPC compilers */
#define MAC_OS_CLASSIC
#ifndef PLATFORM_NAME
#define PLATFORM_NAME "Mac OS"
#endif

#elif defined(__linux__) && defined(__powerpc__)
#if #system(linux)
/* MkLinux on PPC  - gcc (egcs) compiler */
#define MAC_OS_MKLINUX
#ifndef PLATFORM_NAME
#define PLATFORM_NAME "MkLinux"
#endif
#endif

#elif defined(__APPLE__) && defined(__MACH__)
/* Mac OS X (client) 10.x (or server 1.x/10.x) - gcc or Metrowerks MachO compilers */
#define MAC_OS_X
#ifndef PLATFORM_NAME
#define PLATFORM_NAME "Mac OS X"
#endif

#endif

#if defined(MAC_OS_CLASSIC) || defined(MAC_OS_MKLINUX) || defined(MAC_OS_X)
/* Any OS on Mac platform */
#define MAC_OS
#endif

/* Convenience defines for BSD like platforms */
 
#if defined(__FreeBSD__)
#define BSD_BASED_OS
#ifndef PLATFORM_NAME
#define PLATFORM_NAME "FreeBSD"
#endif

#elif defined(__NetBSD__)
#define BSD_BASED_OS
#ifndef PLATFORM_NAME
#define PLATFORM_NAME "NetBSD"
#endif

#elif defined(__OpenBSD__)
#define BSD_BASED_OS
#ifndef PLATFORM_NAME
#define PLATFORM_NAME "OpenBSD"
#endif

#elif defined(__MINT__)
#define BSD_BASED_OS
#ifndef PLATFORM_NAME
#define PLATFORM_NAME "FreeMiNT"
#endif

#elif defined(__bsdi__)
#define BSD_BASED_OS
#ifndef PLATFORM_NAME
#define PLATFORM_NAME "BSD/OS"
#endif

#endif

/* Convenience defines for Windows platforms */
 
#if defined(WINDOWS) || defined(_WIN32)
#define WINDOWS_OS
#ifndef PLATFORM_NAME
#define PLATFORM_NAME "Windows"
#endif
#endif

/* Convenience defines for Linux platforms */
 
#if defined(linux) && defined(__alpha__)
/* Linux on Alpha - gcc compiler */
#define LINUX_OS
#ifndef PLATFORM_NAME
#define PLATFORM_NAME "Linux/Alpha"
#endif

#elif defined(linux) && defined(__sparc__)
/* Linux on Sparc - gcc compiler */
#define LINUX_OS
#ifndef PLATFORM_NAME
#define PLATFORM_NAME "Linux/Sparc"
#endif

#elif defined(linux) && (defined(__i386__) || defined(__i486__) || defined(__i586__) || defined(__i686__))
/* Linux on x86 - gcc compiler */
#define LINUX_OS
#ifndef PLATFORM_NAME
#define PLATFORM_NAME "Linux/x86"
#endif

#elif defined(linux) && defined(__powerpc__)
/* Linux on PPC - gcc compiler */
#define LINUX_OS
#ifndef PLATFORM_NAME
#define PLATFORM_NAME "Linux/PPC"
#endif

#elif defined(linux) || defined(__linux__)
/* generic Linux */
#define LINUX_OS
#ifndef PLATFORM_NAME
#define PLATFORM_NAME "Linux"
#endif

#endif

/* Convenience defines for Solaris platforms */
 
#if defined(sun)
#define SOLARIS_OS
#ifndef PLATFORM_NAME
#define PLATFORM_NAME "Solaris"
#endif
#endif

/* Convenience defines for HPUX + gcc platforms */

#if defined(__hpux)
#define HPUX_OS
#ifndef PLATFORM_NAME
#define PLATFORM_NAME "HPUX"
#endif
#endif

/* Convenience defines for RISCOS + gcc platforms */

#if defined(__riscos__)
#define RISC_OS
#ifndef PLATFORM_NAME
#define PLATFORM_NAME "RISC OS"
#endif
#endif

/* Convenience defines for OS/2 + icc/gcc platforms */

#if defined(__OS2__) || defined(__EMX__)
#define OS2_OS
#ifndef PLATFORM_NAME
#define PLATFORM_NAME "OS/2"
#endif
#endif

/* Convenience defines for IRIX */

#if defined(__sgi)
#define IRIX_OS
#ifndef PLATFORM_NAME
#define PLATFORM_NAME "SGI IRIX"
#endif
#endif

/* Convenience defines for AIX */

#if defined(_AIX)
#define AIX_OS
#ifndef PLATFORM_NAME
#define PLATFORM_NAME "IBM AIX"
#endif
#endif


/* Convenience defines for BeOS platforms */

#if defined(__BEOS__)
#define BE_OS
#ifndef PLATFORM_NAME
#define PLATFORM_NAME "BeOS"
#endif
#endif

/* Convenience defines for Cygwin platforms */

#if defined(__CYGWIN__)
#define CYGWIN_OS
#ifndef PLATFORM_NAME
#define PLATFORM_NAME "Cygwin"
#endif
#endif

/* Convenience defines for OpenVMS */

#if defined(__VMS)
#define OPENVMS_OS
#ifndef PLATFORM_NAME
#define PLATFORM_NAME "OpenVMS"
#endif
#endif

/* Convenience defines for DEC Alpha OSF + gcc platforms */

#if defined(__osf__)
#define OSF_OS
#ifndef PLATFORM_NAME
#define PLATFORM_NAME "DEC Alpha OSF"
#endif
#endif

#include <ctype.h>
#include <stdio.h>
#include <setjmp.h>  /* for longjmp on error exit */
#include <stdlib.h>
#include <stdarg.h>  /* may need <varargs.h> for Unix V */
#include <string.h>
#include <assert.h>

#ifdef NEEDS_MALLOC_H
#include <malloc.h>
#endif

#ifdef SUPPORT_GETPWNAM
#include <pwd.h>
#endif

/* #define __USE_MISC */

/*
  Tidy preserves the last modified time for the files it
  cleans up.
*/

/*
  If your platform doesn't support <utime.h> and the
  utime() function, or <sys/futime> and the futime()
  function then set PRESERVE_FILE_TIMES to 0.
  
  If your platform doesn't support <sys/utime.h> and the
  futime() function, then set HAS_FUTIME to 0.
  
  If your platform supports <utime.h> and the
  utime() function requires the file to be
  closed first, then set UTIME_NEEDS_CLOSED_FILE to 1.
*/

/* Keep old PRESERVEFILETIMES define for compatibility */
#ifdef PRESERVEFILETIMES
#undef PRESERVE_FILE_TIMES
#define PRESERVE_FILE_TIMES PRESERVEFILETIMES
#endif

#ifndef PRESERVE_FILE_TIMES
#if defined(RISC_OS) || defined(OPENVMS_OS) || defined(OSF_OS)
#define PRESERVE_FILE_TIMES 0
#else
#define PRESERVE_FILE_TIMES 1
#endif
#endif

#if PRESERVE_FILE_TIMES

#ifndef HAS_FUTIME
#if defined(CYGWIN_OS) || defined(BE_OS) || defined(OS2_OS) || defined(HPUX_OS) || defined(SOLARIS_OS) || defined(LINUX_OS) || defined(BSD_BASED_OS) || defined(MAC_OS) || defined(__MSL__) || defined(IRIX_OS) || defined(AIX_OS) || defined(__BORLANDC__)
#define HAS_FUTIME 0
#else
#define HAS_FUTIME 1
#endif
#endif

#ifndef UTIME_NEEDS_CLOSED_FILE
#if defined(SOLARIS_OS) || defined(BSD_BASED_OS) || defined(MAC_OS) || defined(__MSL__) || defined(LINUX_OS)
#define UTIME_NEEDS_CLOSED_FILE 1
#else
#define UTIME_NEEDS_CLOSED_FILE 0
#endif
#endif

#if defined(MAC_OS_X) || (!defined(MAC_OS_CLASSIC) && !defined(__MSL__))
#include <sys/types.h> 
#include <sys/stat.h>
#else
#include <stat.h>
#endif

#if HAS_FUTIME
#include <sys/utime.h>
#else
#include <utime.h>
#endif /* HASFUTIME */

/*
  MS Windows needs _ prefix for Unix file functions.
  Not required by Metrowerks Standard Library (MSL).
  
  Tidy uses following for preserving the last modified time.

  WINDOWS automatically set by Win16 compilers.
  _WIN32 automatically set by Win32 compilers.
*/
#if defined(_WIN32) && !defined(__MSL__) && !defined(__BORLANDC__)
#define futime _futime
#define fstat _fstat
#define utimbuf _utimbuf
#define stat _stat
#define fileno _fileno
#endif /* _WIN32 */

#endif /* PRESERVE_FILE_TIMES */

/* hack for gnu sys/types.h file  which defines uint and ulong */
/* you may need to delete the #ifndef and #endif on your system */

#ifndef __USE_MISC
#if defined(BE_OS) || defined(SOLARIS_OS) || defined(BSD_BASED_OS) || defined(MAC_OS_X) || defined(OSF_OS) || defined(IRIX_OS) || defined(AIX_OS)
#include <sys/types.h>
#else
#if !defined(HPUX_OS) && !defined(CYGWIN_OS)
typedef unsigned int uint;
#endif
typedef unsigned long ulong;
#endif
#endif /* __USE_MISC */

typedef unsigned char byte;
           
/*
  bool is a reserved word in some but
  not all C++ compilers depending on age
  work around is to avoid bool altogether
  by introducing a new enum called Bool
*/
typedef enum
{
   no,
   yes
} Bool;

/* for null pointers */
#define null 0

#if defined(DMALLOC)
#include "dmalloc.h"
#endif

/* were defined in html.h - TRT */
void *MemAlloc(uint size);
void *MemRealloc(void *mem, uint newsize);
void MemFree(void *mem);
void ClearMemory(void *, uint size);
