#include "/home/voffk4/cpu/config.h"
#include <string.h>

extern FILE *listing;
extern FILE *logs;

#if DEBUG_LVL > 0
    int list(char *CODE, int arg, int code);
#endif