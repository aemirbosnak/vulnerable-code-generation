//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Create a new matrix with the given dimensions
int** createMatrix(int rows, int cols) {
    int** matrix = (int**)malloc(sizeof(int*) * rows);
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(sizeof(int) * cols);
    }
    return matrix;
}

// Free the memory allocated for the given matrix
void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Print the given matrix
void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Add two matrices of the same dimensions
int** addMatrices(int** matrix1, int** matrix2, int rows, int cols) {
    int** result = createMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}

// Multiply two matrices of compatible dimensions
int** multiplyMatrices(int** matrix1, int** matrix2, int rows1, int cols1, int cols2) {
    int** result = createMatrix(rows1, cols2);
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return result;
}

// Find the transpose of the given matrix
int** transposeMatrix(int** matrix, int rows, int cols) {
    int** result = createMatrix(cols, rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
    return result;
}

// Find the determinant of the given matrix
int determinant(int** matrix, int n) {
    if (n == 1) {
        return matrix[0][0];
    }
    int det = 0;
    for (int i = 0; i < n; i++) {
        int** submatrix = createMatrix(n - 1, n - 1);
        for (int j = 1; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (k < i) {
                    submatrix[j - 1][k] = matrix[j][k];
                } else if (k > i) {
                    submatrix[j - 1][k - 1] = matrix[j][k];
                }
            }
        }
        det += matrix[0][i] * determinant(submatrix, n - 1) * ((i % 2) ? -1 : 1);
        freeMatrix(submatrix, n - 1);
    }
    return det;
}

// Find the inverse of the given matrix
int** inverseMatrix(int** matrix, int n) {
    if (determinant(matrix, n) == 0) {
        return NULL;
    }
    int** result = createMatrix(n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int** submatrix = createMatrix(n - 1, n - 1);
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < n; l++) {
                    if (k < i || l < j) {
                        submatrix[k][l] = matrix[k][l];
                    } else if (k > i || l > j) {
                        submatrix[k - 1][l - 1] = matrix[k][l];
                    }
                }
            }
            result[i][j] = ((i + j) % 2) ? -1 : 1;
            result[i][j] *= determinant(submatrix, n - 1);
            freeMatrix(submatrix, n - 1);
        }
    }
    int det = determinant(matrix, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] /= det;
        }
    }
    return result;
}

int main() {
    // Create two matrices
    int** matrix1 = createMatrix(3, 3);
    int** matrix2 = createMatrix(3, 3);

    // Initialize the matrices
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix1[i][j] = i + j;
            matrix2[i][j] = j + i;
        }
    }

    // Print the matrices
    printf("Matrix 1:\n");
    printMatrix(matrix1, 3, 3);
    printf("Matrix 2:\n");
    printMatrix(matrix2, 3, 3);

    // Add the matrices
    int** result1 = addMatrices(matrix1, matrix2, 3, 3);

    // Print the result
    printf("Result of adding the matrices:\n");
    printMatrix(result1, 3, 3);
    freeMatrix(result1, 3);

    // Multiply the matrices
    int** result2 = multiplyMatrices(matrix1, matrix2, 3, 3, 3);

    // Print the result
    printf("Result of multiplying the matrices:\n");
    printMatrix(result2, 3, 3);
    freeMatrix(result2, 3);

    // Find the transpose of matrix1
    int** result3 = transposeMatrix(matrix1, 3, 3);

    // Print the result
    printf("Transpose of matrix1:\n");
    printMatrix(result3, 3, 3);
    freeMatrix(result3, 3);

    // Find the determinant of matrix1
    int det = determinant(matrix1, 3);

    // Print the result
    printf("Determinant of matrix1: %d\n", det);

    // Find the inverse of matrix1
    int** result4 = inverseMatrix(matrix1, 3);

    // Print the result
    if (result4 != NULL) {
        printf("Inverse of matrix1:\n");
        printMatrix(result4, 3, 3);
        freeMatrix(result4, 3);
    } else {
        printf("Matrix1 is not invertible.\n");
    }

    // Free the memory allocated for the matrices
    freeMatrix(matrix1, 3);
    freeMatrix(matrix2, 3);

    return 0;
}