//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

// Function to create a matrix of size m x n and initialize it with zeros
void createMatrix(int m, int n, int** matrix) {
    int i, j;
    for (i = 0; i < m; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
        for (j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int m, int n, int p, int** matrixA, int** matrixB, int** matrixC) {
    int i, j, k;
    for (i = 0; i < m; i++) {
        for (j = 0; j < p; j++) {
            matrixC[i][j] = 0;
            for (k = 0; k < n; k++) {
                matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

// Function to print a matrix
void printMatrix(int m, int n, int** matrix) {
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int m = 3, n = 2, p = 3;
    int** matrixA, **matrixB, **matrixC;

    // Create matrices A and B
    matrixA = (int**)malloc(m * sizeof(int*));
    matrixB = (int**)malloc(p * sizeof(int*));
    for (int i = 0; i < m; i++) {
        matrixA[i] = (int*)malloc(n * sizeof(int));
    }
    for (int j = 0; j < p; j++) {
        matrixB[j] = (int*)malloc(n * sizeof(int));
    }

    // Initialize matrices A and B
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrixA[i][j] = i + j;
        }
    }
    for (int j = 0; j < p; j++) {
        for (int k = 0; k < n; k++) {
            matrixB[j][k] = j + k;
        }
    }

    // Multiply matrices A and B
    createMatrix(m, n, &matrixC);
    multiplyMatrices(m, n, p, matrixA, matrixB, matrixC);

    // Print the result
    printMatrix(m, p, matrixC);

    // Free memory
    for (int i = 0; i < m; i++) {
        free(matrixA[i]);
    }
    free(matrixA);
    for (int j = 0; j < p; j++) {
        free(matrixB[j]);
    }
    free(matrixB);

    return 0;
}