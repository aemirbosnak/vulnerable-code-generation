//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void matrix_operations(int **a, int **b, int n)
{
    int i, j, k;
    int **c = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        c[i] = (int *)malloc(n * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            c[i][j] = 0;
            for (k = 0; k < n; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    free(c);
}

int main()
{
    int n;
    scanf("Enter the number of matrices:", &n);

    int **a = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        a[i] = (int *)malloc(MAX * sizeof(int));
    }

    int **b = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        b[i] = (int *)malloc(MAX * sizeof(int));
    }

    matrix_operations(a, b, n);

    for (int i = 0; i < n; i++)
    {
        free(a[i]);
        free(b[i]);
    }

    free(a);
    free(b);

    return 0;
}