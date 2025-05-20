//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5

void printMatrix(int **mat, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", mat[i][j]);
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

    // Initializing the matrix with some random numbers
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            arr[i][j] = rand() % 10;
        }
    }

    // Printing the original matrix
    printMatrix(arr, ROWS, COLS);

    // Transposing the matrix
    int **transposed = (int **)malloc(COLS * sizeof(int *));
    for (int i = 0; i < COLS; i++)
    {
        transposed[i] = (int *)malloc(ROWS * sizeof(int));
    }

    for (int i = 0; i < COLS; i++)
    {
        for (int j = 0; j < ROWS; j++)
        {
            transposed[i][j] = arr[j][i];
        }
    }

    // Printing the transposed matrix
    printMatrix(transposed, COLS, ROWS);

    // Freeing the memory
    for (int i = 0; i < ROWS; i++)
    {
        free(arr[i]);
    }
    free(arr);

    for (int i = 0; i < COLS; i++)
    {
        free(transposed[i]);
    }
    free(transposed);

    return 0;
}