#include "/home/voffk4/cpu/config.h"

extern FILE *logs;

int processing(Header *header, char *code, Stack *stk)
{
    CHECK_PTR(header);
    CHECK_PTR(code);

    int ip = 0;

    while (ip < header->code_length)
    {
        switch (code[ip++])
        {
        case CMD_IN:
            {
                printf("Enter the value:\n");
                int value = 0;
                while (scanf("%d", &value) != 1)
                {
                    printf("Enter correct value (((((\n");
                }
                stackPush(stk, value);
                break;
            }
        case CMD_HLT:
            return CMD_HLT;
            break;
        case CMD_PUSH:
            {
                int value = *((int*) (code + ip));
                stackPush(stk, value);
                ip += sizeof(int);
                break;
            }
        case CMD_OUT:
            {
                int value = 0;
                stackPop(stk, &value);
                printf("%d\n", value);
                break;
            }
        case CMD_ADD:
            {
                int first = 0, second = 0;
                stackPop(stk, &first);
                stackPop(stk, &second);
                stackPush(stk, first + second);
                break;
            }
        case CMD_SUB:
            {
                int first = 0, second = 0;
                stackPop(stk, &first);
                stackPop(stk, &second);
                stackPush(stk, second - first);
                break;
            }
        case CMD_MUL:
            {
                int first = 0, second = 0;
                stackPop(stk, &first);
                stackPop(stk, &second);
                stackPush(stk, first * second);
                break;
            }
        case CMD_DIV:
            {
                int first = 0, second = 0;
                stackPop(stk, &first);
                stackPop(stk, &second);
                stackPush(stk, second / first);
                break;
            }
        }
    }

    return 0;
}