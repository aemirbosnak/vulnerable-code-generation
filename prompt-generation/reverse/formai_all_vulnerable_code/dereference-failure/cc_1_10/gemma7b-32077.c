//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **a = NULL;
    int **b = NULL;
    int **c = NULL;

    a = (int**)malloc(5 * sizeof(int*));
    for (int i = 0; i < 5; i++)
    {
        a[i] = (int*)malloc(5 * sizeof(int));
    }

    b = (int**)malloc(5 * sizeof(int*));
    for (int i = 0; i < 5; i++)
    {
        b[i] = (int*)malloc(5 * sizeof(int));
    }

    c = (int**)malloc(5 * sizeof(int*));
    for (int i = 0; i < 5; i++)
    {
        c[i] = (int*)malloc(5 * sizeof(int));
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            a[i][j] = 2 * i + j;
            b[i][j] = 3 * i - j;
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
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