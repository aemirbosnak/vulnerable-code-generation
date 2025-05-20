//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5

int main()
{
    int **a = (int **)malloc(ROWS * sizeof(int *)), **b = (int **)malloc(ROWS * sizeof(int *)), **c = (int **)malloc(ROWS * sizeof(int *)), **d = (int **)malloc(ROWS * sizeof(int *)), **e = (int **)malloc(ROWS * sizeof(int *)), i;

    for (i = 0; i < ROWS; i++)
    {
        a[i] = (int *)malloc(COLS * sizeof(int));
        b[i] = (int *)malloc(COLS * sizeof(int));
        c[i] = (int *)malloc(COLS * sizeof(int));
        d[i] = (int *)malloc(COLS * sizeof(int));
        e[i] = (int *)malloc(COLS * sizeof(int));
    }

    for (i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            a[i][j] = i + j;
            b[i][j] = 2 * i + j;
            c[i][j] = 3 * i + j;
            d[i][j] = 4 * i + j;
            e[i][j] = 5 * i + j;
        }
    }

    for (i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%d ", a[i][j]);
            printf("%d ", b[i][j]);
            printf("%d ", c[i][j]);
            printf("%d ", d[i][j]);
            printf("%d ", e[i][j]);
            printf("\n");
        }
    }

    for (i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            free(a[i][j]);
            free(b[i][j]);
            free(c[i][j]);
            free(d[i][j]);
            free(e[i][j]);
        }
        free(a[i]);
        free(b[i]);
        free(c[i]);
        free(d[i]);
        free(e[i]);
    }

    free(a);
    free(b);
    free(c);
    free(d);
    free(e);

    return 0;
}