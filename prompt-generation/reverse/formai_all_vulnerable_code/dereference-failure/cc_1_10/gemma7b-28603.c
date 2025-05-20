//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

void parse_expression(char **buffer, int *num_ops, int *num_vars);

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    int num_ops = 0;
    int num_vars = 0;

    printf("Enter an expression: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    parse_expression(buffer, &num_ops, &num_vars);

    printf("Number of operators: %d\n", num_ops);
    printf("Number of variables: %d\n", num_vars);

    return 0;
}

void parse_expression(char **buffer, int *num_ops, int *num_vars)
{
    char *p = *buffer;
    char operator;
    int variable_count = 0;

    while (p && (*p != '\0'))
    {
        switch (*p)
        {
            case '+':
            case '-':
            case '*':
            case '/':
            case '(':
            case ')':
                *num_ops++;
                break;
            case 'x':
            case 'y':
            case 'z':
                variable_count++;
                break;
            default:
                break;
        }

        p++;
    }

    *num_vars = variable_count;
}