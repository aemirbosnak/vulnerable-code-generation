//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Recursive function to add two matrices
int **addMatricesRecursive(int **matrix1, int **matrix2, int rows, int cols)
{
    // Base case: if either matrix is empty, return the other matrix
    if (rows == 0 || cols == 0)
        return matrix1 ? matrix1 : matrix2;

    // Create a new matrix to store the result
    int **result = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        result[i] = (int *)malloc(cols * sizeof(int));
    }

    // Recursively add the corresponding elements of the two matrices
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // Return the result matrix
    return result;
}

// Recursive function to subtract two matrices
int **subtractMatricesRecursive(int **matrix1, int **matrix2, int rows, int cols)
{
    // Base case: if either matrix is empty, return the other matrix
    if (rows == 0 || cols == 0)
        return matrix1 ? matrix1 : matrix2;

    // Create a new matrix to store the result
    int **result = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        result[i] = (int *)malloc(cols * sizeof(int));
    }

    // Recursively subtract the corresponding elements of the two matrices
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }

    // Return the result matrix
    return result;
}

// Recursive function to multiply two matrices
int **multiplyMatricesRecursive(int **matrix1, int **matrix2, int rows1, int cols1, int cols2)
{
    // Base case: if either matrix is empty, return a zero matrix
    if (rows1 == 0 || cols2 == 0) {
        int **result = (int **)malloc(rows1 * sizeof(int *));
        for (int i = 0; i < rows1; i++) {
            result[i] = (int *)malloc(cols2 * sizeof(int));
        }
        return result;
    }

    // Create a new matrix to store the result
    int **result = (int **)malloc(rows1 * sizeof(int *));
    for (int i = 0; i < rows1; i++) {
        result[i] = (int *)malloc(cols2 * sizeof(int));
    }

    // Recursively multiply the corresponding elements of the two matrices
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // Return the result matrix
    return result;
}

// Print a matrix
void printMatrix(int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    // Define the first matrix
    int rows1 = 3;
    int cols1 = 2;
    int **matrix1 = (int **)malloc(rows1 * sizeof(int *));
    for (int i = 0; i < rows1; i++) {
        matrix1[i] = (int *)malloc(cols1 * sizeof(int));
    }
    matrix1[0][0] = 1;
    matrix1[0][1] = 2;
    matrix1[1][0] = 3;
    matrix1[1][1] = 4;
    matrix1[2][0] = 5;
    matrix1[2][1] = 6;

    // Define the second matrix
    int rows2 = 2;
    int cols2 = 3;
    int **matrix2 = (int **)malloc(rows2 * sizeof(int *));
    for (int i = 0; i < rows2; i++) {
        matrix2[i] = (int *)malloc(cols2 * sizeof(int));
    }
    matrix2[0][0] = 7;
    matrix2[0][1] = 8;
    matrix2[0][2] = 9;
    matrix2[1][0] = 10;
    matrix2[1][1] = 11;
    matrix2[1][2] = 12;

    // Add the two matrices
    int **sumMatrix = addMatricesRecursive(matrix1, matrix2, rows1, cols1);

    // Subtract the two matrices
    int **differenceMatrix = subtractMatricesRecursive(matrix1, matrix2, rows1, cols1);

    // Multiply the two matrices
    int **productMatrix = multiplyMatricesRecursive(matrix1, matrix2, rows1, cols1, cols2);

    // Print the original matrices
    printf("Matrix 1:\n");
    printMatrix(matrix1, rows1, cols1);
    printf("\nMatrix 2:\n");
    printMatrix(matrix2, rows2, cols2);

    // Print the result matrices
    printf("\nSum Matrix:\n");
    printMatrix(sumMatrix, rows1, cols1);
    printf("\nDifference Matrix:\n");
    printMatrix(differenceMatrix, rows1, cols1);
    printf("\nProduct Matrix:\n");
    printMatrix(productMatrix, rows1, cols2);

    return 0;
}