//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a_rows = 3, a_cols = 4;
    int b_rows = 2, b_cols = 3;
    int c_rows = 4, c_cols = 5;

    int **a = (int **)malloc(a_rows * sizeof(int *));
    for (int r = 0; r < a_rows; r++)
    {
        a[r] = (int *)malloc(a_cols * sizeof(int));
    }

    int **b = (int **)malloc(b_rows * sizeof(int *));
    for (int r = 0; r < b_rows; r++)
    {
        b[r] = (int *)malloc(b_cols * sizeof(int));
    }

    int **c = (int **)malloc(c_rows * sizeof(int *));
    for (int r = 0; r < c_rows; r++)
    {
        c[r] = (int *)malloc(c_cols * sizeof(int));
    }

    // Fill the matrices
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

    b[0][0] = 13;
    b[0][1] = 14;
    b[0][2] = 15;

    c[0][0] = 16;
    c[0][1] = 17;
    c[0][2] = 18;
    c[0][3] = 19;
    c[0][4] = 20;

    // Matrix Multiplication
    int i, j, k;
    for (i = 0; i < c_rows; i++)
    {
        for (j = 0; j < c_cols; j++)
        {
            c[i][j] = 0;
            for (k = 0; k < a_cols; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // Print the result
    for (i = 0; i < c_rows; i++)
    {
        for (j = 0; j < c_cols; j++)
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