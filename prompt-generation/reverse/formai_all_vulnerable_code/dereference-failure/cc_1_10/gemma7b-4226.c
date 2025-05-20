//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

void Matrix_Operations(int **a, int **b, int n)
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
    int n = 2;
    int **a = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        a[i] = (int *)malloc(n * sizeof(int));
    }

    a[0][0] = 1;
    a[0][1] = 2;
    a[1][0] = 3;
    a[1][1] = 4;

    int **b = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        b[i] = (int *)malloc(n * sizeof(int));
    }

    b[0][0] = 2;
    b[0][1] = 3;
    b[1][0] = 4;
    b[1][1] = 5;

    Matrix_Operations(a, b, n);

    int **c = (int **)a;
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
    return 0;
}