//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
    int **a = (int **)malloc(MAX * sizeof(int *));
    for (int i = 0; i < MAX; i++)
    {
        a[i] = (int *)malloc(MAX * sizeof(int));
    }

    int i, j, k, l;
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            a[i][j] = 0;
        }
    }

    for (k = 0; k < MAX; k++)
    {
        for (l = 0; l < MAX; l++)
        {
            a[k][l] = k + l;
        }
    }

    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            free(a[i][j]);
        }
        free(a[i]);
    }
    free(a);

    return 0;
}