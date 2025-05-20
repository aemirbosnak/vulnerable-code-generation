//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **a = NULL;
    int **b = NULL;
    int **c = NULL;
    int i, j, k, l;

    a = (int **)malloc(sizeof(int *) * 3);
    b = (int **)malloc(sizeof(int *) * 3);
    c = (int **)malloc(sizeof(int *) * 3);

    for (i = 0; i < 3; i++)
    {
        a[i] = (int *)malloc(sizeof(int) * 3);
        b[i] = (int *)malloc(sizeof(int) * 3);
        c[i] = (int *)malloc(sizeof(int) * 3);
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            a[i][j] = 1;
            b[i][j] = 2;
            c[i][j] = 3;
        }
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", a[i][j] + b[i][j] - c[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
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