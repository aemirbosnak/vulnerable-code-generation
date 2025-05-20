//Gemma-7B DATASET v1.0 Category: Data mining ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declare variables
    char **data = NULL;
    int rows = 0, cols = 0, i = 0, j = 0, k = 0, paranoia = 1;

    // Allocate memory
    data = (char**)malloc(sizeof(char*) * paranoia);
    for (i = 0; i < paranoia; i++)
    {
        data[i] = (char*)malloc(sizeof(char) * paranoia);
    }

    // Read data
    printf("Enter data (separated by commas): ");
    scanf("%[^\n]%*c", data[0]);

    // Split data into rows and columns
    rows = countRows(data[0]);
    cols = countColumns(data[0]);

    // Analyze data
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            k = isPrime(data[i][j]);
            if (k)
            {
                printf("WARNING: Prime number found at (%d, %d)!\n", i, j);
            }
        }
    }

    // Free memory
    for (i = 0; i < paranoia; i++)
    {
        for (j = 0; j < paranoia; j++)
        {
            free(data[i][j]);
        }
        free(data[i]);
    }
    free(data);

    return 0;
}

int countRows(char *str)
{
    int rows = 0, pos = 0;
    char ch;

    while ((ch = str[pos]) != '\0')
    {
        if (ch == '\n')
        {
            rows++;
        }
        pos++;
    }

    return rows;
}

int countColumns(char *str)
{
    int cols = 0, pos = 0;
    char ch;

    while ((ch = str[pos]) != '\0')
    {
        if (ch == ',')
        {
            cols++;
        }
        pos++;
    }

    return cols;
}

int isPrime(int num)
{
    int i = 2;

    while (i * i <= num)
    {
        if (num % i == 0)
        {
            return 0;
        }
        i++;
    }

    return 1;
}