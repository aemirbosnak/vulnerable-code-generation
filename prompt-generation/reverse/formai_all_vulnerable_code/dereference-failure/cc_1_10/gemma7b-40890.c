//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: secure
#include <stdio.h>
#include <stdlib.h>

void matrix_operations(int **a, int **b, int **c, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main()
{
    int n = 3;
    int **a = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        a[i] = (int *)malloc(n * sizeof(int));
    }

    int **b = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        b[i] = (int *)malloc(n * sizeof(int));
    }

    int **c = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        c[i] = (int *)malloc(n * sizeof(int));
    }

    // Matrix Operations
    matrix_operations(a, b, c, n);

    // Print the Result
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    // Free the Memory
    for (int i = 0; i < n; i++)
    {
        free(a[i]);
        free(b[i]);
        free(c[i]);
    }
    free(a);
    free(b);
    free(c);

    return 0;
}