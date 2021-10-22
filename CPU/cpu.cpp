#include "/home/voffk4/cpu/CPU/cpu_header.h"

FILE *logs = fopen("logs", "w");

int main(void)
{
    FILE *Code = fopen("/home/voffk4/cpu/ASM/Binary", "r");
    CHECK_PTR(Code);

    Header header = {};

    fread(&header, 1, sizeof(Header), Code);
    
    if (header.sign = 'MH')
    {
        char *code = (char *) calloc(header.code_length + 1, sizeof(char));
        fread(code, header.code_length, sizeof(char), Code);

        Stack stk = {};
        stackCtor(&stk, 0);

        if (processing(&header, code, &stk) == CMD_HLT)
        {
            free(code);
            stackDtor(&stk);
            fclose(Code);
            #if DEBUG_LVL > 0
                fclose(logs);
            #endif
        }
    }  
    else
    {
        #if DEBUG_LVL > 0
            fprintf(logs, "\n\n##################################################" 
                            "\n\nERR_WRONG_SIGNATURE\n\n"
                            "##################################################\n");
        #endif
        fclose(Code);
        #if DEBUG_LVL > 0
            fclose(logs);
        #endif
    }

    return 0;
}
