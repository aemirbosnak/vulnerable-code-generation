//FormAI DATASET v1.0 Category: Matrix operations ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Function to initialize a matrix with random values
void initializeMatrix(int **matrix, int rows, int columns)
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<columns; j++)
        {
            matrix[i][j] = rand() % 10;
        }
    }
}

// Function to print a matrix
void printMatrix(int **matrix, int rows, int columns)
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<columns; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrices(int **matrix1, int **matrix2, int **result, int rows, int columns)
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<columns; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

int main()
{
    int rows = 3;
    int columns = 3;

    // Allocate memory for matrices
    int **matrix1 = (int **)malloc(rows * sizeof(int *));
    int **matrix2 = (int **)malloc(rows * sizeof(int *));
    int **result = (int **)malloc(rows * sizeof(int *));
    for(int i=0; i<rows; i++)
    {
        matrix1[i] = (int *)malloc(columns * sizeof(int));
        matrix2[i] = (int *)malloc(columns * sizeof(int));
        result[i] = (int *)malloc(columns * sizeof(int));
    }

    // Initialize matrices
    initializeMatrix(matrix1, rows, columns);
    initializeMatrix(matrix2, rows, columns);

    // Print matrices
    printf("Matrix 1:\n");
    printMatrix(matrix1, rows, columns);

    printf("\nMatrix 2:\n");
    printMatrix(matrix2, rows, columns);

    // Add matrices
    addMatrices(matrix1, matrix2, result, rows, columns);

    // Print result matrix
    printf("\nResult:\n");
    printMatrix(result, rows, columns);

    // Free memory
    for(int i=0; i<rows; i++)
    {
        free(matrix1[i]);
        free(matrix2[i]);
        free(result[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}