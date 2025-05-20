//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 4

int main()
{
    int **a = (int **)malloc(ROWS * sizeof(int *));
    for (int i = 0; i < ROWS; i++)
    {
        a[i] = (int *)malloc(COLS * sizeof(int));
    }

    // Matrix initialization
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

    // Transpose the matrix
    int **b = (int **)malloc(COLS * sizeof(int *));
    for (int i = 0; i < COLS; i++)
    {
        b[i] = (int *)malloc(ROWS * sizeof(int));
    }

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            b[j][i] = a[i][j];
        }
    }

    // Print the transposed matrix
    for (int i = 0; i < COLS; i++)
    {
        for (int j = 0; j < ROWS; j++)
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < ROWS; i++)
    {
        free(a[i]);
    }
    free(a);

    for (int i = 0; i < COLS; i++)
    {
        free(b[i]);
    }
    free(b);

    return 0;
}