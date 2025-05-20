//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

void calculate(char **arr, int size)
{
    int i, j, result = 0, operator = 0;
    char temp[MAX];

    for (i = 0; i < size; i++)
    {
        if (arr[i] >= 'a' && arr[i] <= 'z')
        {
            operator = 1;
            temp[i] = arr[i] - 32;
        }
        else if (arr[i] >= '0' && arr[i] <= '9')
        {
            temp[i] = arr[i] - '0';
        }
        else if (arr[i] == '+')
        {
            result += temp[i - 1] + temp[i - 2];
            operator = 0;
        }
        else if (arr[i] == '-')
        {
            result -= temp[i - 1] - temp[i - 2];
            operator = 0;
        }
        else if (arr[i] == '*')
        {
            result *= temp[i - 1] * temp[i - 2];
            operator = 0;
        }
        else if (arr[i] == '/')
        {
            result /= temp[i - 1] / temp[i - 2];
            operator = 0;
        }
    }

    if (operator)
    {
        printf("Error: Invalid operator.\n");
    }
    else
    {
        printf("The result is: %d\n", result);
    }
}

int main()
{
    char **arr = (char **)malloc(MAX * sizeof(char *));
    int size = 0;

    printf("Enter your calculator expression: ");
    getline(arr, MAX, stdin);

    size = strlen(arr[0]) + 1;
    calculate(arr, size);

    free(arr);

    return 0;
}