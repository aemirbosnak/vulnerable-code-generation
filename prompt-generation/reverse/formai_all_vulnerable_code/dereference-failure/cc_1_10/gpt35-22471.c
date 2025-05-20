//FormAI DATASET v1.0 Category: Matrix operations ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// Function to print a matrix
void printMatrix(int **m, int rows, int cols) {
    int i, j;
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to initialize a matrix with random values
void initMatrix(int **m, int rows, int cols) {
    int i, j;
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            m[i][j] = rand() % 10;
        }
    }
}

// Function to add two matrices
void addMatrices(int **m1, int **m2, int **result, int rows, int cols) {
    int i, j;
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int **m1, int rows1, int cols1, int **m2, int rows2, int cols2, int **result) {
    int i, j, k;
    for(i = 0; i < rows1; i++) {
        for(j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for(k = 0; k < cols1; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

int main() {
    int rows1 = 3; // Number of rows in matrix 1
    int cols1 = 2; // Number of columns in matrix 1
    int rows2 = 2; // Number of rows in matrix 2
    int cols2 = 3; // Number of columns in matrix 2

    // Allocate memory for matrices
    int **matrix1 = (int **)malloc(rows1 * sizeof(int *));
    int **matrix2 = (int **)malloc(rows2 * sizeof(int *));
    int **resultMatrix = (int **)malloc(rows1 * sizeof(int *));
    int i, j;
    for(i = 0; i < rows1; i++) {
        matrix1[i] = (int *)malloc(cols1 * sizeof(int));
        resultMatrix[i] = (int *)malloc(cols2 * sizeof(int));
    }
    for(i = 0; i < rows2; i++) {
        matrix2[i] = (int *)malloc(cols2 * sizeof(int));
    }

    // Initialize matrices with random values
    initMatrix(matrix1, rows1, cols1);
    initMatrix(matrix2, rows2, cols2);

    // Print the matrices
    printf("Matrix 1:\n");
    printMatrix(matrix1, rows1, cols1);
    printf("Matrix 2:\n");
    printMatrix(matrix2, rows2, cols2);

    // Add the matrices
    addMatrices(matrix1, matrix2, resultMatrix, rows1, cols1);
    printf("Matrix 1 + Matrix 2:\n");
    printMatrix(resultMatrix, rows1, cols1);

    // Multiply the matrices
    multiplyMatrices(matrix1, rows1, cols1, matrix2, rows2, cols2, resultMatrix);
    printf("Matrix 1 * Matrix 2:\n");
    printMatrix(resultMatrix, rows1, cols2);

    // Free memory
    for(i = 0; i < rows1; i++) {
        free(matrix1[i]);
        free(resultMatrix[i]);
    }
    for(i = 0; i < rows2; i++) {
        free(matrix2[i]);
    }
    free(matrix1);
    free(matrix2);
    free(resultMatrix);

    return 0;
}