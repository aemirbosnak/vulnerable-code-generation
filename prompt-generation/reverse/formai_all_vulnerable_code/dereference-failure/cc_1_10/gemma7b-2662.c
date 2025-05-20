//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 4;
    int b = 5;
    int c = 6;

    int **matrix_a = (int **)malloc(a * sizeof(int *));
    for (int i = 0; i < a; i++)
    {
        matrix_a[i] = (int *)malloc(b * sizeof(int));
    }

    int **matrix_b = (int **)malloc(b * sizeof(int *));
    for (int i = 0; i < b; i++)
    {
        matrix_b[i] = (int *)malloc(c * sizeof(int));
    }

    // Matrix A is 4x5 with values:
    matrix_a[0][0] = 1;
    matrix_a[0][1] = 2;
    matrix_a[0][2] = 3;
    matrix_a[0][3] = 4;
    matrix_a[0][4] = 5;

    // Matrix B is 5x6 with values:
    matrix_b[0][0] = 6;
    matrix_b[0][1] = 7;
    matrix_b[0][2] = 8;
    matrix_b[0][3] = 9;
    matrix_b[0][4] = 10;
    matrix_b[0][5] = 11;

    // Multiplying Matrix A and Matrix B
    int **matrix_c = (int **)malloc(a * sizeof(int *));
    for (int i = 0; i < a; i++)
    {
        matrix_c[i] = (int *)malloc(c * sizeof(int));
    }

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < c; j++)
        {
            matrix_c[i][j] = 0;
            for (int k = 0; k < b; k++)
            {
                matrix_c[i][j] += matrix_a[i][k] * matrix_b[k][j];
            }
        }
    }

    // Printing Matrix C
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", matrix_c[i][j]);
        }
        printf("\n");
    }

    free(matrix_a);
    free(matrix_b);
    free(matrix_c);

    return 0;
}