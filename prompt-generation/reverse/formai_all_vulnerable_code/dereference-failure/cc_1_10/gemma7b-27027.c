//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 2

int main()
{
    // Define a 2D array to store the Matrix
    int **matrix = (int **)malloc(ROWS * sizeof(int *) + COLS * sizeof(int));
    for (int i = 0; i < ROWS; i++)
    {
        matrix[i] = (int *)malloc(COLS * sizeof(int));
    }

    // Initialize the Matrix with sample data
    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[1][0] = 3;
    matrix[1][1] = 4;
    matrix[2][0] = 5;
    matrix[2][1] = 6;

    // Define the transpose of the Matrix
    int **transpose = (int **)malloc(COLS * sizeof(int *) + ROWS * sizeof(int));
    for (int i = 0; i < COLS; i++)
    {
        transpose[i] = (int *)malloc(ROWS * sizeof(int));
    }

    // Transpose the Matrix
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }

    // Print the transposed Matrix
    for (int i = 0; i < COLS; i++)
    {
        for (int j = 0; j < ROWS; j++)
        {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the Matrix and its transpose
    for (int i = 0; i < ROWS; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    for (int i = 0; i < COLS; i++)
    {
        free(transpose[i]);
    }
    free(transpose);

    return 0;
}