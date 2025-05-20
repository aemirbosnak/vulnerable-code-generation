//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

void matrix_operations(int **a, int **b, int **c, int n)
{
    int i, j, k, l;

    c = (int **)malloc(n * sizeof(int *));
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
                for (l = 0; l < n; l++)
                {
                    if (a[i][k] && b[k][l])
                    {
                        c[i][j] += a[i][k] * b[k][l];
                    }
                }
            }
        }
    }

    free(c);
}

int main()
{
    int n;
    scanf("Enter the number of rows and columns:", &n);

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

    matrix_operations(a, b, c, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    free(a);
    free(b);
    free(c);

    return 0;
}