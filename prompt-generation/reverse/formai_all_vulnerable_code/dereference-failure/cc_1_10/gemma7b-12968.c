//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: genius
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **a, **b, **c, n, i, j, k;
    n = 3;
    a = (int **)malloc(n * sizeof(int *));
    for(i = 0; i < n; i++)
    {
        a[i] = (int *)malloc(n * sizeof(int));
    }

    b = (int **)malloc(n * sizeof(int *));
    for(i = 0; i < n; i++)
    {
        b[i] = (int *)malloc(n * sizeof(int));
    }

    c = (int **)malloc(n * sizeof(int *));
    for(i = 0; i < n; i++)
    {
        c[i] = (int *)malloc(n * sizeof(int));
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            a[i][j] = i + j;
            b[i][j] = 2 * i + 3 * j;
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
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