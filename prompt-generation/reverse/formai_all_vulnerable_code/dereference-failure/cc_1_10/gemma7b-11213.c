//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5

void MatrixOperations(int **a, int **b, int **c)
{
    int i, j, k;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
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
    int **a = (int **)malloc(ROWS * sizeof(int *));
    for (int i = 0; i < ROWS; i++)
    {
        a[i] = (int *)malloc(COLS * sizeof(int));
    }

    int **b = (int **)malloc(ROWS * sizeof(int *));
    for (int i = 0; i < ROWS; i++)
    {
        b[i] = (int *)malloc(COLS * sizeof(int));
    }

    int **c = (int **)malloc(ROWS * sizeof(int *));
    for (int i = 0; i < ROWS; i++)
    {
        c[i] = (int *)malloc(COLS * sizeof(int));
    }

    a[0][0] = 1;
    a[0][1] = 2;
    a[0][2] = 3;
    a[0][3] = 4;
    a[0][4] = 5;

    b[0][0] = 2;
    b[0][1] = 3;
    b[0][2] = 4;
    b[0][3] = 5;
    b[0][4] = 6;

    MatrixOperations(a, b, c);

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
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