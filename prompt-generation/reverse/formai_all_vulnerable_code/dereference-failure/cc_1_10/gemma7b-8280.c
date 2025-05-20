//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

void matrix_operations(int **a, int **b)
{
    int i, j, k;
    int rows_a = *a;
    int cols_a = *a + 1;
    int rows_b = *b;
    int cols_b = *b + 1;

    int **c = (int **)malloc(rows_a * sizeof(int *));
    for (i = 0; i < rows_a; i++)
    {
        c[i] = (int *)malloc(cols_b * sizeof(int));
    }

    for (i = 0; i < rows_a; i++)
    {
        for (j = 0; j < cols_b; j++)
        {
            c[i][j] = 0;
            for (k = 0; k < cols_a; k++)
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
    int a_rows = 2;
    int a_cols = 3;
    int **a = (int **)malloc(a_rows * sizeof(int *));
    for (int i = 0; i < a_rows; i++)
    {
        a[i] = (int *)malloc(a_cols * sizeof(int));
    }

    a[0][0] = 1;
    a[0][1] = 2;
    a[0][2] = 3;
    a[1][0] = 4;
    a[1][1] = 5;
    a[1][2] = 6;

    int b_rows = 3;
    int b_cols = 2;
    int **b = (int **)malloc(b_rows * sizeof(int *));
    for (int i = 0; i < b_rows; i++)
    {
        b[i] = (int *)malloc(b_cols * sizeof(int));
    }

    b[0][0] = 2;
    b[0][1] = 3;
    b[1][0] = 4;
    b[1][1] = 5;
    b[2][0] = 6;
    b[2][1] = 7;

    matrix_operations(&a, &b);

    int c_rows = a_rows;
    int c_cols = b_cols;
    int **c = (int **)malloc(c_rows * sizeof(int *));
    for (int i = 0; i < c_rows; i++)
    {
        c[i] = (int *)malloc(c_cols * sizeof(int));
    }

    c = a;

    for (int i = 0; i < c_rows; i++)
    {
        for (int j = 0; j < c_cols; j++)
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