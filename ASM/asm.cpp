#include "/home/voffk4/cpu/ASM/Asm-header.h"

FILE *logs = fopen("logs", "w");

#if DEBUG_LVL > 0
    FILE *listing = fopen("Listing", "w");                                   
#endif

int main(void)
{   
    FILE *sourse = fopen("Sourse", "r");
    FILE *binary = fopen("Binary", "wb");

    Text commands = {};

    constructText(sourse, &commands);

    char *code = (char *) calloc(commands.string_amount * 2, sizeof(int));
    
    Header header = {};
    header.sign = 'MH';
    header.ver = 0;
    header.hash = 0;

    int code_size = 0; //by dima (gondon)
    
    code_size += sizeof(Header);
        
    for (int i = 0; i < commands.string_amount; i++)
    {   
        char *CMD = nullptr;
        int arg = NAN;

        sscanf(commands.text[i].string, "%ms %d", &CMD, &arg);
        
        CHECK_PTR(CMD);

        if (strcmp(CMD, "PUSH")     == 0)
        {   
            code[code_size++] = CMD_PUSH;
            *((int *) (code + code_size)) = arg;
            list(CMD, arg, code[code_size - 1]);
            code_size += sizeof(int);

        }
        else if (strcmp(CMD, "IN")  == 0)
        {
            code[code_size++] = CMD_IN;
            list(CMD, arg, code[code_size - 1]);

        }
        else if (strcmp(CMD, "HLT") == 0)
        {
            code[code_size++] = CMD_HLT;
            list(CMD, arg, code[code_size - 1]);
        }
        else if (strcmp(CMD, "OUT") == 0)
        {
            code[code_size++] = CMD_OUT;
            list(CMD, arg, code[code_size - 1]);
        }
        else if (strcmp(CMD, "ADD") == 0)
        {
            code[code_size++] = CMD_ADD;
            list(CMD, arg, code[code_size - 1]);
        }
        else if (strcmp(CMD, "SUB") == 0)
        {
            code[code_size++] = CMD_SUB;
            list(CMD, arg, code[code_size - 1]);
        }
        else if (strcmp(CMD, "MUL") == 0)
        {
            code[code_size++] = CMD_MUL;
            list(CMD, arg, code[code_size - 1]);
        }
        else if (strcmp(CMD, "DIV") == 0)
        {
            code[code_size++] = CMD_DIV;
            list(CMD, arg, code[code_size - 1]);
        }

        free(CMD);
    }
    
    header.code_length = code_size - sizeof(Header);
    *((Header *) code) = header;
    
    for (int i = 0; i < code_size; i++)
    {
        printf("%d\n", code[i]);
    }

    fwrite(code, sizeof(char) * code_size, 1, binary);

    free(code);
    fclose(sourse);
    fclose(binary);
    finish_poem(&commands);
    #if DEBUG_LVL > 0
        fclose(listing);
        fclose(logs);
    #endif

    return 0;
}