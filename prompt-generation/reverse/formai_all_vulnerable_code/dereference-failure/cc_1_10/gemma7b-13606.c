//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

void matrix_operations(int **a, int **b)
{
    int rows_a = *a;
    int cols_a = **a;
    int rows_b = *b;
    int cols_b = **b;

    if (cols_a != rows_b)
    {
        printf("Error: Matrices must have compatible dimensions.");
        return;
    }

    int **c = (int **)malloc(rows_a * sizeof(int *));
    for (int i = 0; i < rows_a; i++)
    {
        c[i] = (int *)malloc(cols_b * sizeof(int));
    }

    for (int i = 0; i < rows_a; i++)
    {
        for (int j = 0; j < cols_b; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < cols_a; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    free(c);
}

int main()
{
    int **a = (int **)malloc(2 * sizeof(int *));
    a[0] = (int *)malloc(3 * sizeof(int));
    a[1] = (int *)malloc(3 * sizeof(int));

    a[0][0] = 1;
    a[0][1] = 2;
    a[0][2] = 3;
    a[1][0] = 4;
    a[1][1] = 5;
    a[1][2] = 6;

    int **b = (int **)malloc(2 * sizeof(int *));
    b[0] = (int *)malloc(3 * sizeof(int));
    b[1] = (int *)malloc(3 * sizeof(int));

    b[0][0] = 2;
    b[0][1] = 3;
    b[0][2] = 4;
    b[1][0] = 5;
    b[1][1] = 6;
    b[1][2] = 7;

    matrix_operations(a, b);

    int **c = (int **)a;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    free(a);
    free(b);

    return 0;
}