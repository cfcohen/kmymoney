/* config-kmymoney.h.  Generated from config-kmymoney.h.cmake by cmake  */

/* Name of package */
#define PACKAGE "kmymoney"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "kmymoney-devel@kde.org"

/* Define to the full name of this package. */
#define PACKAGE_NAME "KMyMoney"

/* Define to 1 if you have the <stdint.h> header file. */
#cmakedefine HAVE_STDINT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#cmakedefine HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <unistd.h> header file. */
#cmakedefine HAVE_UNISTD_H 1

/* The size of `long', as computed by sizeof. */
#cmakedefine SIZEOF_LONG @SIZEOF_LONG@

#cmakedefine KMM_DEBUG 1

#cmakedefine KMM_DESIGNER 1

#ifdef __GNUC__
#  define KMM_PRINTF_FORMAT(x, y) __attribute__((format(__printf__, x, y)))
#else
#  define KMM_PRINTF_FORMAT(x, y) /*NOTHING*/
#endif
