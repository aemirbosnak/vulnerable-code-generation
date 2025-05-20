//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5

void MatrixOperations(int **a, int **b, int **c)
{
    int i, j, k;
    int r = ROWS;
    int c1 = COLS;
    int c2 = COLS;

    c = (int **)malloc(r * sizeof(int *));
    for (i = 0; i < r; i++)
    {
        c[i] = (int *)malloc(c1 * sizeof(int));
    }

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c1; j++)
        {
            c[i][j] = 0;
            for (k = 0; k < c2; k++)
            {
                if (a[i][k] && b[k][j])
                {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
    }

    free(c);
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

    int **c = NULL;

    a[0][0] = 1;
    a[0][1] = 2;
    a[0][2] = 3;
    a[1][0] = 4;
    a[1][1] = 5;
    a[1][2] = 6;

    b[0][0] = 7;
    b[0][1] = 8;
    b[0][2] = 9;
    b[1][0] = 10;
    b[1][1] = 11;
    b[1][2] = 12;

    MatrixOperations(a, b, c);

    printf("The product of the two matrices is:\n");

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