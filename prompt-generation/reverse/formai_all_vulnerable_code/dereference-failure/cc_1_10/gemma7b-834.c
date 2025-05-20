//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5

void matrix_operations(int **a, int **b, int **c)
{
    int i, j, k;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            c[i][j] = 0;
            for (k = 0; k < COLS; k++)
            {
                if (a[i][k] && b[k][j])
                {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
    }
}

int main()
{
    int **a = (int **)malloc(ROWS * sizeof(int *));
    int **b = (int **)malloc(COLS * sizeof(int *));
    int **c = (int **)malloc(ROWS * sizeof(int *));

    for (int i = 0; i < ROWS; i++)
    {
        a[i] = (int *)malloc(COLS * sizeof(int));
        b[i] = (int *)malloc(COLS * sizeof(int));
        c[i] = (int *)malloc(COLS * sizeof(int));
    }

    // Populate the matrices
    a[0][0] = 1;
    a[0][1] = 2;
    a[0][2] = 3;
    a[1][0] = 4;
    a[1][1] = 5;
    a[1][2] = 6;

    b[0][0] = 3;
    b[0][1] = 2;
    b[0][2] = 4;
    b[1][0] = 5;
    b[1][1] = 6;
    b[1][2] = 7;

    // Perform matrix operations
    matrix_operations(a, b, c);

    // Print the result
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < ROWS; i++)
    {
        free(a[i]);
        free(b[i]);
        free(c[i]);
    }
    free(a);
    free(b);
    free(c);

    return 0;
}