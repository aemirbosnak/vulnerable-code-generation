//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

char buffer[MAX_BUFFER_SIZE];

void calculate(char **argv)
{
    int i = 0;
    double num1 = 0, num2 = 0, result = 0;
    char operator = '\0';

    // Iterate over the arguments to find the operator and operands
    for (i = 1; argv[i] != NULL; i++)
    {
        if (operator == '\0')
        {
            operator = argv[i][0];
        }
        else if (num1 == 0)
        {
            num1 = atof(argv[i]);
        }
        else
        {
            num2 = atof(argv[i]);
        }
    }

    // Perform the calculation based on the operator
    switch (operator)
    {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0)
            {
                printf("Error: division by zero is not allowed.\n");
                exit(1);
            }
            result = num1 / num2;
            break;
        default:
            printf("Error: invalid operator.\n");
            exit(1);
    }

    // Print the result
    printf("The result is: %.2lf\n", result);
}

int main(int argc, char **argv)
{
    calculate(argv);

    return 0;
}