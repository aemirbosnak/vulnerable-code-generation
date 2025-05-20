//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
    int **a, **b, **c, i, j, k;

    a = (int **)malloc(MAX * sizeof(int *));
    for (i = 0; i < MAX; i++)
    {
        a[i] = (int *)malloc(MAX * sizeof(int));
    }

    b = (int **)malloc(MAX * sizeof(int *));
    for (i = 0; i < MAX; i++)
    {
        b[i] = (int *)malloc(MAX * sizeof(int));
    }

    c = (int **)malloc(MAX * sizeof(int *));
    for (i = 0; i < MAX; i++)
    {
        c[i] = (int *)malloc(MAX * sizeof(int));
    }

    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            a[i][j] = i + j;
            b[i][j] = i - j;
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            free(a[i][j]);
            free(b[i][j]);
            free(c[i][j]);
        }
        free(a[i]);
        free(b[i]);
        free(c[i]);
    }

    free(a);
    free(b);
    free(c);

    return 0;
}