//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define ROW 5
#define COL 5

void matrix_operations(int **a, int **b)
{
    int i, j, k;

    // Allocate memory for the product matrix
    int **c = (int **)malloc(ROW * sizeof(int *));
    for (i = 0; i < ROW; i++)
    {
        c[i] = (int *)malloc(COL * sizeof(int));
    }

    // Perform the matrix multiplication
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            c[i][j] = 0;
            for (k = 0; k < COL; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // Print the product matrix
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (i = 0; i < ROW; i++)
    {
        free(c[i]);
    }
    free(c);
}

int main()
{
    int **a = (int **)malloc(ROW * sizeof(int *));
    for (int i = 0; i < ROW; i++)
    {
        a[i] = (int *)malloc(COL * sizeof(int));
    }

    // Populate the matrix a
    a[0][0] = 1;
    a[0][1] = 2;
    a[0][2] = 3;
    a[0][3] = 4;
    a[0][4] = 5;

    int **b = (int **)malloc(ROW * sizeof(int *));
    for (int i = 0; i < ROW; i++)
    {
        b[i] = (int *)malloc(COL * sizeof(int));
    }

    // Populate the matrix b
    b[0][0] = 2;
    b[0][1] = 3;
    b[0][2] = 4;
    b[0][3] = 5;
    b[0][4] = 6;

    // Perform matrix operations
    matrix_operations(a, b);

    // Free memory
    for (int i = 0; i < ROW; i++)
    {
        free(a[i]);
        free(b[i]);
    }
    free(a);
    free(b);

    return 0;
}