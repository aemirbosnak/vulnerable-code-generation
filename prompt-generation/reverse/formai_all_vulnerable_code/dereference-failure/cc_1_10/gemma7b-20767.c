//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 4

void matrix_operations(int **a, int **b, int **c)
{
    int r = ROWS;
    int c1 = COLS;
    int c2 = COLS;
    int i, j, k;

    *c = (int *)malloc(r * c1 * c2 * sizeof(int));

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c1; j++)
        {
            for (k = 0; k < c2; k++)
            {
                (*c)[i * c1 * c2 + j * c2 + k] = 0;
            }
        }
    }

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c1; j++)
        {
            for (k = 0; k < c2; k++)
            {
                int sum = 0;
                for (int l = 0; l < COLS; l++)
                {
                    sum += a[i][l] * b[l][k];
                }
                (*c)[i * c1 * c2 + j * c2 + k] = sum;
            }
        }
    }
}

int main()
{
    int **a = (int **)malloc(ROWS * COLS * sizeof(int));
    int **b = (int **)malloc(ROWS * COLS * sizeof(int));
    int **c = NULL;

    a[0][0] = 1;
    a[0][1] = 2;
    a[0][2] = 3;
    a[0][3] = 4;
    a[1][0] = 5;
    a[1][1] = 6;
    a[1][2] = 7;
    a[1][3] = 8;
    a[2][0] = 9;
    a[2][1] = 10;
    a[2][2] = 11;
    a[2][3] = 12;

    b[0][0] = 3;
    b[0][1] = 2;
    b[0][2] = 1;
    b[0][3] = 4;
    b[1][0] = 5;
    b[1][1] = 6;
    b[1][2] = 7;
    b[1][3] = 8;
    b[2][0] = 9;
    b[2][1] = 10;
    b[2][2] = 11;
    b[2][3] = 12;

    matrix_operations(a, b, &c);

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