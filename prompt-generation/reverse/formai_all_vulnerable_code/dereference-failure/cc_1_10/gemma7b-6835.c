//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

void MatrixOperations(int **arr)
{
    int i, j, k;

    // Transpose the matrix
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            for (k = 0; k < COLS; k++)
            {
                arr[k][j] = arr[j][k];
            }
        }
    }

    // Multiply the matrix by a scalar
    int scalar = 2;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            arr[i][j] *= scalar;
        }
    }

    // Print the matrix
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int **arr = (int **)malloc(ROWS * sizeof(int *));
    for (int i = 0; i < ROWS; i++)
    {
        arr[i] = (int *)malloc(COLS * sizeof(int));
    }

    // Initialize the matrix
    arr[0][0] = 1;
    arr[0][1] = 2;
    arr[0][2] = 3;
    arr[1][0] = 4;
    arr[1][1] = 5;
    arr[1][2] = 6;
    arr[2][0] = 7;
    arr[2][1] = 8;
    arr[2][2] = 9;

    MatrixOperations(arr);

    return 0;
}