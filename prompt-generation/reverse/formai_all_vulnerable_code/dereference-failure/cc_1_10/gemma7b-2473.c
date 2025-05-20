//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5

void matrix_operations(int **a, int **b)
{
    int i, j, k;
    int **c = (int **)malloc(ROWS * sizeof(int *)), *p = NULL;
    for (i = 0; i < ROWS; i++)
    {
        c[i] = (int *)malloc(COLS * sizeof(int));
        p = c[i];
        for (j = 0; j < COLS; j++)
        {
            *p++ = 0;
        }
    }

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            for (k = 0; k < COLS; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    free(c);
}

int main()
{
    int **a = (int **)malloc(ROWS * sizeof(int *)), *p = NULL;
    for (int i = 0; i < ROWS; i++)
    {
        a[i] = (int *)malloc(COLS * sizeof(int));
        p = a[i];
        for (int j = 0; j < COLS; j++)
        {
            *p++ = rand() % 10;
        }
    }

    int **b = (int **)malloc(ROWS * sizeof(int *)), *q = NULL;
    for (int i = 0; i < ROWS; i++)
    {
        b[i] = (int *)malloc(COLS * sizeof(int));
        q = b[i];
        for (int j = 0; j < COLS; j++)
        {
            *q++ = rand() % 10;
        }
    }

    matrix_operations(a, b);

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    free(a);
    free(b);

    return 0;
}