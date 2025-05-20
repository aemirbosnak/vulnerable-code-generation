//Gemma-7B DATASET v1.0 Category: Classical Circuit Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>

void circuit_simulate(int **matrix, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int sum = 0;
            for (int k = 0; k < n; k++)
            {
                for (int l = 0; l < m; l++)
                {
                    if (k == i && l == j)
                    {
                        sum += matrix[k][l];
                    }
                }
            }
            matrix[i][j] = sum;
        }
    }
}

int main()
{
    int n, m;
    scanf("Enter the number of rows: ", &n);
    scanf("Enter the number of columns: ", &m);

    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        matrix[i] = (int *)malloc(m * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("Enter the element at (%d, %d): ", &matrix[i][j]);
        }
    }

    circuit_simulate(matrix, n, m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("The element at (%d, %d) is: %d\n", i, j, matrix[i][j]);
        }
    }

    free(matrix);

    return 0;
}