//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define the Matrix
    int **matrix = NULL;
    int rows = 0, cols = 0;

    // Allocate memory for the matrix
    matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    // Populate the matrix
    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[1][0] = 3;
    matrix[1][1] = 4;

    // Transpose the matrix
    int **transpose = NULL;
    transpose = (int **)malloc(cols * sizeof(int *));
    for (int i = 0; i < cols; i++)
    {
        transpose[i] = (int *)malloc(rows * sizeof(int));
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }

    // Print the transpose matrix
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    free(matrix);
    free(transpose);

    return 0;
}