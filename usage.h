#ifndef USAGE_H
#define USAGE_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

extern void usage(const char *err);
extern int error(const char *fmt, ...);
extern void fatal(const char *fmt, ...);

typedef enum { FALSE , TURE } Boolean;
Boolean nums;
#endif /* USAGE_H */
