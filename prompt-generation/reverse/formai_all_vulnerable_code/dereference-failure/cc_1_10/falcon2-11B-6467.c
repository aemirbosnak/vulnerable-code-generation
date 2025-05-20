//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// Function to create a matrix with random values
void createMatrix(int m, int n, int **matrix) {
    int i, j;
    for (i = 0; i < m; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
        for (j = 0; j < n; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

// Function to print a matrix
void printMatrix(int m, int n, int **matrix) {
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrices(int m, int n, int **a, int **b, int **c) {
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int m, int n, int **a, int **b, int **c) {
    int i, j, k;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            c[i][j] = 0;
            for (k = 0; k < m; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int m, n;
    printf("Enter the dimensions of the matrix: ");
    scanf("%d %d", &m, &n);

    // Allocate memory for the matrices
    int **matrixA, **matrixB, **matrixC;
    matrixA = (int **)malloc(m * sizeof(int *));
    matrixB = (int **)malloc(m * sizeof(int *));
    matrixC = (int **)malloc(m * sizeof(int *));

    // Create random matrices
    createMatrix(m, n, matrixA);
    createMatrix(m, n, matrixB);

    // Print the matrices
    printf("Matrix A:\n");
    printMatrix(m, n, matrixA);
    printf("\nMatrix B:\n");
    printMatrix(m, n, matrixB);

    // Add the matrices
    printf("Matrix A + Matrix B:\n");
    addMatrices(m, n, matrixA, matrixB, matrixC);
    printMatrix(m, n, matrixC);

    // Multiply the matrices
    printf("Matrix A * Matrix B:\n");
    multiplyMatrices(m, n, matrixA, matrixB, matrixC);
    printMatrix(m, n, matrixC);

    // Free memory
    for (int i = 0; i < m; i++) {
        free(matrixA[i]);
        free(matrixB[i]);
        free(matrixC[i]);
    }
    free(matrixA);
    free(matrixB);
    free(matrixC);

    return 0;
}