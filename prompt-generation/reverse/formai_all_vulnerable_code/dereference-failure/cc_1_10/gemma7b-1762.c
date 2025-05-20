//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: Sherlock Holmes
// A Sherlock Holmes style C Matrix Operations Example

#include <stdio.h>
#include <stdlib.h>

// Define a 2D array to store the matrix
int **matrix_data(int r, int c)
{
    int **arr = (int **)malloc(r * sizeof(int *));
    for (int i = 0; i < r; i++)
    {
        arr[i] = (int *)malloc(c * sizeof(int));
    }
    return arr;
}

int main()
{
    // Create a 2x2 matrix
    int **matrix = matrix_data(2, 2);

    // Initialize the matrix with some data
    matrix[0][0] = 10;
    matrix[0][1] = 20;
    matrix[1][0] = 30;
    matrix[1][1] = 40;

    // Print the matrix
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Transpose the matrix
    int **transpose = matrix_data(2, 2);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            transpose[i][j] = matrix[j][i];
        }
    }

    // Print the transposed matrix
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}