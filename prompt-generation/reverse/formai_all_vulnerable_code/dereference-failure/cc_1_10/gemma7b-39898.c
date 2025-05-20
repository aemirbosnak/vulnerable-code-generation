//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 5
#define COLS 10

void matrix_ops(int **a, int **b, int **c)
{
    int i, j, k;
    int ra = *a, rb = *b, rc = *c;

    for (i = 0; i < ra; i++)
    {
        for (j = 0; j < rb; j++)
        {
            c[i][j] = 0;
            for (k = 0; k < COLS; k++)
            {
                if (a[i][k] && b[k][j])
                {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
    }
}

int main()
{
    int **a = NULL, **b = NULL, **c = NULL;

    a = (int **)malloc(ROWS * sizeof(int *));
    b = (int **)malloc(COLS * sizeof(int *));
    c = (int **)malloc(ROWS * sizeof(int *));

    for (int i = 0; i < ROWS; i++)
    {
        a[i] = (int *)malloc(COLS * sizeof(int));
        c[i] = (int *)malloc(COLS * sizeof(int));
    }

    for (int i = 0; i < COLS; i++)
    {
        b[i] = (int *)malloc(ROWS * sizeof(int));
    }

    int n1 = 3, n2 = 4, n3 = 2;

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            a[i][j] = i + j;
        }
    }

    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < n3; j++)
        {
            b[i][j] = i - j;
        }
    }

    matrix_ops(a, b, c);

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n3; j++)
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