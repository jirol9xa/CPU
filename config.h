/* THE FILE IS GENERATED AUTOMATICALLY!!!!!!!!!
THE FILE IS GENERATED AUTOMATICALLY!!!!!!!!!
THE FILE IS GENERATED AUTOMATICALLY!!!!!!!!!
THE FILE IS GENERATED AUTOMATICALLY!!!!!!!!!
THE FILE IS GENERATED AUTOMATICALLY!!!!!!!!!
THE FILE IS GENERATED AUTOMATICALLY!!!!!!!!!
THE FILE IS GENERATED AUTOMATICALLY!!!!!!!!!
THE FILE IS GENERATED AUTOMATICALLY!!!!!!!!!
THE FILE IS GENERATED AUTOMATICALLY!!!!!!!!!
THE FILE IS GENERATED AUTOMATICALLY!!!!!!!!!
THE FILE IS GENERATED AUTOMATICALLY!!!!!!!!!
THE FILE IS GENERATED AUTOMATICALLY!!!!!!!!!
THE FILE IS GENERATED AUTOMATICALLY!!!!!!!!!
THE FILE IS GENERATED AUTOMATICALLY!!!!!!!!!
THE FILE IS GENERATED AUTOMATICALLY!!!!!!!!!
*/




#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include "/home/voffk4/cpu/onegin.h"
#include "/home/voffk4/cpu/stack.h"

#define DEBUG_LVL 1

enum COMMANDS{
    CMD_IN   = 0,
    CMD_HLT  = 1,
    CMD_PUSH = 2,
    CMD_OUT  = 3,
    CMD_ADD  = 4,
    CMD_SUB  = 5,
    CMD_MUL  = 6,
    CMD_DIV  = 7
};

struct Header{
    int sign;
    int ver;
    int hash;
    int code_length;
};

#define MEMCPY(type, arg)                                                            \
{                                                                                    \
    MemCpy(CODE + code_size, &arg, sizeof(type));                                    \
    code_size += sizeof(type);                                                       \
}                                                                                    