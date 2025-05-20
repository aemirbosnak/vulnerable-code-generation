//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 10

// Function to create a new matrix
int **createMatrix(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }
    return matrix;
}

// Function to free the memory allocated for a matrix
void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to print a matrix
void printMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
int **addMatrices(int **matrix1, int **matrix2, int rows, int cols) {
    int **resultMatrix = createMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            resultMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return resultMatrix;
}

// Function to subtract two matrices
int **subtractMatrices(int **matrix1, int **matrix2, int rows, int cols) {
    int **resultMatrix = createMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            resultMatrix[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    return resultMatrix;
}

// Function to multiply two matrices
int **multiplyMatrices(int **matrix1, int **matrix2, int rows1, int cols1, int rows2, int cols2) {
    if (cols1 != rows2) {
        printf("Error: The number of columns in the first matrix must be equal to the number of rows in the second matrix.\n");
        return NULL;
    }
    int **resultMatrix = createMatrix(rows1, cols2);
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            resultMatrix[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return resultMatrix;
}

// Function to transpose a matrix
int **transposeMatrix(int **matrix, int rows, int cols) {
    int **resultMatrix = createMatrix(cols, rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            resultMatrix[j][i] = matrix[i][j];
        }
    }
    return resultMatrix;
}

// Function to find the determinant of a matrix
int determinant(int **matrix, int rows, int cols) {
    if (rows != cols) {
        printf("Error: The matrix must be square.\n");
        return -1;
    }
    if (rows == 1) {
        return matrix[0][0];
    }
    int det = 0;
    int **subMatrix = createMatrix(rows - 1, cols - 1);
    for (int i = 0; i < rows; i++) {
        int cofactor = (i % 2 == 0) ? 1 : -1;
        for (int j = 1; j < rows; j++) {
            for (int k = 0; k < cols; k++) {
                if (k == i) {
                    continue;
                }
                subMatrix[j - 1][k - 1] = matrix[j][k];
            }
        }
        det += cofactor * matrix[0][i] * determinant(subMatrix, rows - 1, cols - 1);
        freeMatrix(subMatrix, rows - 1);
    }
    return det;
}

// Function to find the inverse of a matrix
int **inverseMatrix(int **matrix, int rows, int cols) {
    if (rows != cols) {
        printf("Error: The matrix must be square.\n");
        return NULL;
    }
    int det = determinant(matrix, rows, cols);
    if (det == 0) {
        printf("Error: The matrix is not invertible.\n");
        return NULL;
    }
    int **adjointMatrix = transposeMatrix(matrix, rows, cols);
    int **inverseMatrix = createMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            inverseMatrix[i][j] = adjointMatrix[i][j] / det;
        }
    }
    freeMatrix(adjointMatrix, rows);
    return inverseMatrix;
}

// Function to test the matrix operations
int main() {
    int rows1 = 2, cols1 = 3;
    int **matrix1 = createMatrix(rows1, cols1);
    matrix1[0][0] = 1;
    matrix1[0][1] = 2;
    matrix1[0][2] = 3;
    matrix1[1][0] = 4;
    matrix1[1][1] = 5;
    matrix1[1][2] = 6;
    printf("Matrix 1:\n");
    printMatrix(matrix1, rows1, cols1);

    int rows2 = 3, cols2 = 2;
    int **matrix2 = createMatrix(rows2, cols2);
    matrix2[0][0] = 1;
    matrix2[0][1] = 2;
    matrix2[1][0] = 3;
    matrix2[1][1] = 4;
    matrix2[2][0] = 5;
    matrix2[2][1] = 6;
    printf("Matrix 2:\n");
    printMatrix(matrix2, rows2, cols2);

    // Add the two matrices
    int **resultMatrix = addMatrices(matrix1, matrix2, rows1, cols1);
    printf("Result Matrix (Addition):\n");
    printMatrix(resultMatrix, rows1, cols1);
    freeMatrix(resultMatrix, rows1);

    // Subtract the two matrices
    resultMatrix = subtractMatrices(matrix1, matrix2, rows1, cols1);
    printf("Result Matrix (Subtraction):\n");
    printMatrix(resultMatrix, rows1, cols1);
    freeMatrix(resultMatrix, rows1);

    // Multiply the two matrices
    resultMatrix = multiplyMatrices(matrix1, matrix2, rows1, cols1, rows2, cols2);
    printf("Result Matrix (Multiplication):\n");
    printMatrix(resultMatrix, rows1, cols2);
    freeMatrix(resultMatrix, rows1);

    // Transpose the first matrix
    int **transposeMatrix1 = transposeMatrix(matrix1, rows1, cols1);
    printf("Transpose of Matrix 1:\n");
    printMatrix(transposeMatrix1, cols1, rows1);
    freeMatrix(transposeMatrix1, cols1);

    // Find the determinant of the first matrix
    int det = determinant(matrix1, rows1, cols1);
    printf("Determinant of Matrix 1: %d\n", det);

    // Find the inverse of the first matrix
    int **inverseMatrix1 = inverseMatrix(matrix1, rows1, cols1);
    if (inverseMatrix1 != NULL) {
        printf("Inverse of Matrix 1:\n");
        printMatrix(inverseMatrix1, rows1, cols1);
    }
    freeMatrix(inverseMatrix1, rows1);

    // Free the memory allocated for the matrices
    freeMatrix(matrix1, rows1);
    freeMatrix(matrix2, rows2);

    return 0;
}