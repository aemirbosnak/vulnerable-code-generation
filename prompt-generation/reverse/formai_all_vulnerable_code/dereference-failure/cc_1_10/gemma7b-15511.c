//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void matrix_operations(int **a, int **b, int **c)
{
    int i, j, k;
    int rows_a = *a;
    int cols_a = *a + 1;
    int rows_b = *b;
    int cols_b = *b + 1;
    int rows_c = rows_a + 1;
    int cols_c = cols_b + 1;

    c = (int **)malloc(rows_c * sizeof(int *) + rows_c);
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
                int product = 0;
                for (int l = 0; l < cols_b; l++)
                {
                    product += a[i][j] * b[k][l];
                }
                c[i][j] = product;
            }
        }
    }
}

int main()
{
    int **a = NULL;
    int **b = NULL;
    int **c = NULL;
    int rows_a = 2;
    int cols_a = 3;
    int rows_b = 3;
    int cols_b = 2;

    a = (int **)malloc(rows_a * sizeof(int *) + rows_a);
    for (int i = 0; i < rows_a; i++)
    {
        a[i] = (int *)malloc(cols_a * sizeof(int));
    }

    b = (int **)malloc(rows_b * sizeof(int *) + rows_b);
    for (int i = 0; i < rows_b; i++)
    {
        b[i] = (int *)malloc(cols_b * sizeof(int));
    }

    matrix_operations(&a, &b, &c);

    for (int i = 0; i < rows_a; i++)
    {
        for (int j = 0; j < cols_a; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}