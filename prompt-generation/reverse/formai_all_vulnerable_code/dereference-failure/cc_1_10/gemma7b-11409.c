//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void matrix_operations(int **a, int **b, int **c)
{
    int i, j, k;
    int m = 5, n = 3, p = 4;

    a = (int **)malloc(m * sizeof(int *));
    for (i = 0; i < m; i++)
    {
        a[i] = (int *)malloc(n * sizeof(int));
    }

    b = (int **)malloc(p * sizeof(int *));
    for (i = 0; i < p; i++)
    {
        b[i] = (int *)malloc(n * sizeof(int));
    }

    c = (int **)malloc(m * sizeof(int *));
    for (i = 0; i < m; i++)
    {
        c[i] = (int *)malloc(p * sizeof(int));
    }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            for (k = 0; k < p; k++)
            {
                c[i][k] = 0;
            }
        }
    }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            for (k = 0; k < p; k++)
            {
                c[i][k] += a[i][j] * b[j][k];
            }
        }
    }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < p; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    free(a);
    free(b);
    free(c);
}

int main()
{
    int **a = NULL, **b = NULL, **c = NULL;

    matrix_operations(a, b, c);

    return 0;
}