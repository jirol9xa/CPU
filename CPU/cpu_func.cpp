#include "/home/voffk4/cpu/CPU/cpu_header.h"

extern FILE *logs;


/*!
    \brief  Функция дампа для проца
    \param  [CPU *]cpu Указатель на процессор
    \param  [char *]binary_code Массив с кодом
    \param  [FILE *]logs Лог файл, куда будет
            записываться дамп
*/
static void cpuDump(CPU *cpu, char *binary_code, FILE *logs)
{
    PRINT_RESHETKA(logs);
    PRINT_RESHETKA(logs);
    PRINT_RESHETKA(logs);
    fprintf(logs, "        ");
    for (int i = 0; i < cpu->real_size; i++)
    {
        fprintf(logs, " %2d", i);
    }
    fprintf(logs, "\n");
    fprintf(logs, "Commands");
    for (int i = 0; i < cpu->code_size; i++)
    {
        fprintf(logs, " %2d", (int) binary_code[i]);                                                                                                                              
        if ((binary_code[i] && 32) != 0 || (binary_code[i] && 64) != 0)       
        {                                   
            i ++;                                                      
            fprintf(logs, " %2d", *((int *) (binary_code + i)));                            
            i += sizeof(int) - 1;                                                               
        }                                                                                                                                                                                      
    }
    fprintf(logs, "\n");
    fprintf(logs, "%*s----------- current command\n", cpu->real_ip * 3 + 8, "^");

    fprintf(logs, "Regs\n" "ax --- %d\n" "bx --- %d\n" "cx --- %d\n" "dx --- %d\n", cpu->regs[0], 
            cpu->regs[1], cpu->regs[2], cpu->regs[3]);
    
    PRINT_RESHETKA(logs);
    PRINT_RESHETKA(logs);
    PRINT_RESHETKA(logs);
    fprintf(logs, "\n\n\n");
}


/*!
    \brief  Функция работы процессора
    \param  [Header *]header Указатель на
            хедер бинарника
    \param  [CPU *]cpu Указатель на процессор
    \return 0 в случае успеха, 1 в противном
            случае
*/
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

            #define DEF_CMD(num, name, num_args, cmd_code)                                                       \
            case CMD_##name:                                                                                     \
                is_debug_lvl_0(cpu->real_ip ++);                                                                 \
                cpuDump(cpu, code, logs);                                                                        \
                cmd_code;                                                                                        \
            break;

            #include "/home/voffk4/cpu/commands.h"
            #undef DEF_CMD
        }
    }

    return 0;
}
