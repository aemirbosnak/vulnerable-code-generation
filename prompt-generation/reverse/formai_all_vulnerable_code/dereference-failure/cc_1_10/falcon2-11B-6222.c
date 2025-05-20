//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

// Function to create a matrix of given size
int **createMatrix(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }
    return matrix;
}

// Function to display a matrix
void displayMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrices(int **matrix1, int **matrix2, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix1[i][j] += matrix2[i][j];
        }
    }
}

// Function to multiply a matrix by a scalar
void multiplyMatrixByScalar(int **matrix, int scalar, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] *= scalar;
        }
    }
}

int main() {
    int rows = 2, cols = 3;
    int **matrix1 = createMatrix(rows, cols);
    int **matrix2 = createMatrix(rows, cols);
    int **matrix3 = createMatrix(rows, cols);

    // Create matrix1 and matrix2
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix1[i][j] = i + j;
            matrix2[i][j] = i + j;
        }
    }

    // Add matrix1 and matrix2
    addMatrices(matrix1, matrix2, rows, cols);

    // Display matrix1 and matrix2
    displayMatrix(matrix1, rows, cols);
    displayMatrix(matrix2, rows, cols);

    // Multiply matrix1 by scalar 2
    multiplyMatrixByScalar(matrix1, 2, rows, cols);

    // Display matrix1
    displayMatrix(matrix1, rows, cols);

    return 0;
}