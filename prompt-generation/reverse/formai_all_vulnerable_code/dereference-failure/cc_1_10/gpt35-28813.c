//FormAI DATASET v1.0 Category: Matrix operations ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void printMatrix(int **matrix, int rows, int cols);
void fillMatrix(int **matrix, int rows, int cols);
void addMatrix(int **matrixA, int **matrixB, int **result, int rows, int cols);
void multiplyMatrix(int **matrixA, int **matrixB, int **result, int rows, int cols1, int cols2);

int main()
{
    int rows = 3, cols1 = 2, cols2 = 3;
    
    // Allocate memory for matrices
    int **matrixA = (int **)malloc(rows * sizeof(int *));
    for(int i = 0; i < rows; i++)
        matrixA[i] = (int *)malloc(cols1 * sizeof(int));
        
    int **matrixB = (int **)malloc(cols1 * sizeof(int *));
    for(int i = 0; i < cols1; i++)
        matrixB[i] = (int *)malloc(cols2 * sizeof(int));
        
    int **resultAdd = (int **)malloc(rows * sizeof(int *));
    for(int i = 0; i < rows; i++)
        resultAdd[i] = (int *)malloc(cols1 * sizeof(int));
        
    int **resultMult = (int **)malloc(rows * sizeof(int *));
    for(int i = 0; i < rows; i++)
        resultMult[i] = (int *)malloc(cols2 * sizeof(int));
    
    // Fill matrices with random numbers
    fillMatrix(matrixA, rows, cols1);
    fillMatrix(matrixB, cols1, cols2);
    
    // Perform matrix operations
    addMatrix(matrixA, matrixB, resultAdd, rows, cols1);
    multiplyMatrix(matrixA, matrixB, resultMult, rows, cols1, cols2);
    
    // Print matrices
    printf("Matrix A:\n");
    printMatrix(matrixA, rows, cols1);
    
    printf("\nMatrix B:\n");
    printMatrix(matrixB, cols1, cols2);
    
    printf("\nMatrix A + B:\n");
    printMatrix(resultAdd, rows, cols1);
    
    printf("\nMatrix A * B:\n");
    printMatrix(resultMult, rows, cols2);
    
    // Deallocate memory
    for(int i = 0; i < rows; i++)
        free(matrixA[i]);
    free(matrixA);
    
    for(int i = 0; i < cols1; i++)
        free(matrixB[i]);
    free(matrixB);
    
    for(int i = 0; i < rows; i++)
        free(resultAdd[i]);
    free(resultAdd);
    
    for(int i = 0; i < rows; i++)
        free(resultMult[i]);
    free(resultMult);
    
    return 0;
}

// Function to print a 2D matrix
void printMatrix(int **matrix, int rows, int cols)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

// Function to fill a 2D matrix with random numbers
void fillMatrix(int **matrix, int rows, int cols)
{
    srand(time(NULL));
    
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            matrix[i][j] = rand() % 10;
}

// Function to add two 2D matrices
void addMatrix(int **matrixA, int **matrixB, int **result, int rows, int cols)
{
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            result[i][j] = matrixA[i][j] + matrixB[i][j];
}

// Function to multiply two 2D matrices
void multiplyMatrix(int **matrixA, int **matrixB, int **result, int rows, int cols1, int cols2)
{
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols2; j++)
        {
            int sum = 0;
            for(int k = 0; k < cols1; k++)
                sum += matrixA[i][k] * matrixB[k][j];
            result[i][j] = sum;
        }
}