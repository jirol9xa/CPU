#include "/home/voffk4/cpu/CPU/cpu_header.h"

extern FILE *logs;

int processing(Header *header, char *code, CPU *cpu)
{
    CHECK_PTR(header);
    CHECK_PTR(code);
    CHECK_PTR(cpu);

    cpu->ip = 0;

    while (cpu->ip < header->code_length)
    {
        switch (code[cpu->ip++] & 31)
        {
        #define DEF_CMD(num, name, num_args, code)                                                       \
        case CMD_##name:                                                                                 \
            code;                                                                                        \
        break;

        #include "/home/voffk4/cpu/commands.h"
        #undef DEF_CMD
        }
    }

    return 0;
}