//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

void matrix_operations(int **a, int **b, int **c)
{
    int i, j, k;
    int rows_a = *a, cols_a = **a;
    int rows_b = *b, cols_b = **b;
    int rows_c = rows_a, cols_c = cols_b;

    c = (int **)malloc(rows_c * sizeof(int *));
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
                if (a[i][j] && b[k][0] && c[i][k])
                {
                    c[i][k] += a[i][j] * b[k][0];
                }
            }
        }
    }

    free(c);
}

int main()
{
    int **a = NULL;
    int **b = NULL;
    int **c = NULL;

    int rows_a = 2, cols_a = 3;
    int rows_b = 3, cols_b = 2;

    a = (int **)malloc(rows_a * sizeof(int *));
    for (int i = 0; i < rows_a; i++)
    {
        a[i] = (int *)malloc(cols_a * sizeof(int));
    }

    b = (int **)malloc(rows_b * sizeof(int *));
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

    free(a);
    free(b);
    free(c);

    return 0;
}