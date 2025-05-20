//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: genius
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **a, **b, **c, i, j, k;

    a = (int **)malloc(10 * sizeof(int *));
    for (i = 0; i < 10; i++)
    {
        a[i] = (int *)malloc(20 * sizeof(int));
    }

    b = (int **)malloc(10 * sizeof(int *));
    for (i = 0; i < 10; i++)
    {
        b[i] = (int *)malloc(20 * sizeof(int));
    }

    c = (int **)malloc(10 * sizeof(int *));
    for (i = 0; i < 10; i++)
    {
        c[i] = (int *)malloc(20 * sizeof(int));
    }

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 20; j++)
        {
            a[i][j] = i + j;
            b[i][j] = 2 * i + 3 * j;
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 20; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 10; i++)
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