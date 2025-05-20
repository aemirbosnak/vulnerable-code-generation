//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: calm
#include <stdio.h>
#include <stdlib.h>

void matrix_operations(int **a, int **b, int **c)
{
    int i, j, k;
    int rows_a = *a;
    int cols_a = *a + 1;
    int rows_b = *b;
    int cols_b = *b + 1;
    int rows_c = rows_a + 1;
    int cols_c = cols_b + 1;

    c = (int**)malloc(rows_c * sizeof(int *));
    for (i = 0; i < rows_c; i++)
    {
        c[i] = (int *)malloc(cols_c * sizeof(int));
    }

    for (i = 0; i < rows_a; i++)
    {
        for (j = 0; j < cols_a; j++)
        {
            for (k = 0; k < rows_b; k++)
            {
                if (a[i][j] && b[k][0] && a[i][j] == b[k][0])
                {
                    c[i][j] = 1;
                }
            }
        }
    }

    for (i = 0; i < rows_c; i++)
    {
        for (j = 0; j < cols_c; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int a_rows = 3;
    int a_cols = 4;
    int b_rows = 2;
    int b_cols = 3;

    int **a = (int **)malloc(a_rows * sizeof(int *));
    for (int i = 0; i < a_rows; i++)
    {
        a[i] = (int *)malloc(a_cols * sizeof(int));
    }

    int **b = (int **)malloc(b_rows * sizeof(int *));
    for (int i = 0; i < b_rows; i++)
    {
        b[i] = (int *)malloc(b_cols * sizeof(int));
    }

    int **c = NULL;

    matrix_operations(&a, &b, &c);

    return 0;
}