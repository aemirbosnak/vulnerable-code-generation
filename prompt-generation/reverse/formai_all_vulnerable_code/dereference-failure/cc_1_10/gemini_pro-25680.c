//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the matrix
#define MAX_SIZE 100

// Define the types of matrix operations
typedef enum {
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION
} MatrixOperation;

// Function to create a matrix
int** createMatrix(int rows, int cols) {
    // Allocate memory for the matrix
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }

    // Initialize the matrix with zeros
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = 0;
        }
    }

    // Return the matrix
    return matrix;
}

// Function to free the memory allocated for a matrix
void freeMatrix(int** matrix, int rows) {
    // Free the memory allocated for each row of the matrix
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }

    // Free the memory allocated for the matrix itself
    free(matrix);
}

// Function to print a matrix
void printMatrix(int** matrix, int rows, int cols) {
    // Print the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to perform a matrix operation
int** performMatrixOperation(int** matrix1, int rows1, int cols1, int** matrix2, int rows2, int cols2, MatrixOperation operation) {
    // Check if the matrices are compatible for the operation
    if (operation == ADDITION || operation == SUBTRACTION) {
        if (rows1 != rows2 || cols1 != cols2) {
            printf("Error: The matrices are not compatible for the operation.\n");
            return NULL;
        }
    } else if (operation == MULTIPLICATION) {
        if (cols1 != rows2) {
            printf("Error: The matrices are not compatible for the operation.\n");
            return NULL;
        }
    }

    // Create a new matrix to store the result of the operation
    int** result = createMatrix(rows1, cols2);

    // Perform the operation on the matrices
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            switch (operation) {
                case ADDITION:
                    result[i][j] = matrix1[i][j] + matrix2[i][j];
                    break;
                case SUBTRACTION:
                    result[i][j] = matrix1[i][j] - matrix2[i][j];
                    break;
                case MULTIPLICATION:
                    result[i][j] = 0;
                    for (int k = 0; k < cols1; k++) {
                        result[i][j] += matrix1[i][k] * matrix2[k][j];
                    }
                    break;
            }
        }
    }

    // Return the result matrix
    return result;
}

// Main function
int main() {
    // Create two matrices
    int** matrix1 = createMatrix(3, 3);
    int** matrix2 = createMatrix(3, 3);

    // Initialize the matrices
    matrix1[0][0] = 1;
    matrix1[0][1] = 2;
    matrix1[0][2] = 3;
    matrix1[1][0] = 4;
    matrix1[1][1] = 5;
    matrix1[1][2] = 6;
    matrix1[2][0] = 7;
    matrix1[2][1] = 8;
    matrix1[2][2] = 9;

    matrix2[0][0] = 10;
    matrix2[0][1] = 11;
    matrix2[0][2] = 12;
    matrix2[1][0] = 13;
    matrix2[1][1] = 14;
    matrix2[1][2] = 15;
    matrix2[2][0] = 16;
    matrix2[2][1] = 17;
    matrix2[2][2] = 18;

    // Print the original matrices
    printf("Matrix 1:\n");
    printMatrix(matrix1, 3, 3);

    printf("Matrix 2:\n");
    printMatrix(matrix2, 3, 3);

    // Perform addition on the matrices
    int** result1 = performMatrixOperation(matrix1, 3, 3, matrix2, 3, 3, ADDITION);

    // Print the result of the addition
    printf("Result of addition:\n");
    printMatrix(result1, 3, 3);

    // Perform subtraction on the matrices
    int** result2 = performMatrixOperation(matrix1, 3, 3, matrix2, 3, 3, SUBTRACTION);

    // Print the result of the subtraction
    printf("Result of subtraction:\n");
    printMatrix(result2, 3, 3);

    // Perform multiplication on the matrices
    int** result3 = performMatrixOperation(matrix1, 3, 3, matrix2, 3, 3, MULTIPLICATION);

    // Print the result of the multiplication
    printf("Result of multiplication:\n");
    printMatrix(result3, 3, 3);

    // Free the memory allocated for the matrices and the result matrices
    freeMatrix(matrix1, 3);
    freeMatrix(matrix2, 3);
    freeMatrix(result1, 3);
    freeMatrix(result2, 3);
    freeMatrix(result3, 3);

    return 0;
}