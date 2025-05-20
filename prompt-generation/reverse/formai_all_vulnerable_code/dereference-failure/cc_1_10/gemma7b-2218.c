//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    int **a = NULL;
    int **b = NULL;
    int **c = NULL;

    a = malloc(sizeof(int *) * 3);
    b = malloc(sizeof(int *) * 3);
    c = malloc(sizeof(int *) * 3);

    for (int i = 0; i < 3; i++)
    {
        a[i] = malloc(sizeof(int) * 3);
        b[i] = malloc(sizeof(int) * 3);
        c[i] = malloc(sizeof(int) * 3);
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            a[i][j] = rand() % 10;
            b[i][j] = rand() % 10;
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
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
}