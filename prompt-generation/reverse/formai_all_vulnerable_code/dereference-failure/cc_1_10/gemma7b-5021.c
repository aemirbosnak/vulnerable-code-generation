//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5

void MatrixOperations(int **arr, int r, int c)
{
    int i, j, k;

    // Transpose the matrix
    int **arrT = (int **)malloc(r * sizeof(int *));
    for (i = 0; i < r; i++)
    {
        arrT[i] = (int *)malloc(c * sizeof(int));
    }
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            arrT[i][j] = arr[j][i];
        }
    }

    // Multiply the matrix by a scalar
    int scalar = 2;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            arrT[i][j] *= scalar;
        }
    }

    // Print the transposed matrix
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d ", arrT[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (i = 0; i < r; i++)
    {
        free(arrT[i]);
    }
    free(arrT);
}

int main()
{
    int **arr = (int **)malloc(ROWS * sizeof(int *));
    for (int i = 0; i < ROWS; i++)
    {
        arr[i] = (int *)malloc(COLS * sizeof(int));
    }

    // Populate the matrix
    arr[0][0] = 1;
    arr[0][1] = 2;
    arr[0][2] = 3;
    arr[0][3] = 4;
    arr[0][4] = 5;
    arr[1][0] = 6;
    arr[1][1] = 7;
    arr[1][2] = 8;
    arr[1][3] = 9;
    arr[1][4] = 10;

    MatrixOperations(arr, ROWS, COLS);

    // Free the memory
    for (int i = 0; i < ROWS; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}