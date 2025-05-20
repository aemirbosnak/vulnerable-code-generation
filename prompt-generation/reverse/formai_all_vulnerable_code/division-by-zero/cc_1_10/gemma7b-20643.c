//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calculate(char **arr, int n)
{
    int i, j, result = 0, operand1 = 0, operand2 = 0;
    char operator;

    for (i = 0; i < n; i++)
    {
        if (isdigit(arr[i]) || isdigit(arr[i + 1]))
        {
            operand2 = operand2 * 10 + arr[i] - '0';
            operand2 = operand2 * 10 + arr[i + 1] - '0';
        }
        else if (operator = arr[i])
        {
            operand1 = operand1 * 10 + arr[i - 1] - '0';
            switch (operator)
            {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
            }
            operand1 = result;
        }
    }

    printf("The result is: %d\n", result);
}

int main()
{
    char *arr[] = {"12", "34", "+", "5", "*", "2"};
    int n = sizeof(arr) / sizeof(arr[0]);

    calculate(arr, n);

    return 0;
}