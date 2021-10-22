#include "/home/voffk4/cpu/ASM/Asm-header.h"

#if DEBUG_LVL > 0
    int list(char *CODE, int arg, int code)
    {
        CHECK_PTR(CODE);

        fprintf(listing, "%4s %d ------>  %d %d\n", CODE, arg, code, arg);
    }
#endif