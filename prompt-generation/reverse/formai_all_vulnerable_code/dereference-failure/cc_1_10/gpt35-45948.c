//FormAI DATASET v1.0 Category: Matrix operations ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// function to print a matrix of n x m elements
void printMatrix(int** matrix, int n, int m) {
    printf("\nMatrix: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// function to add two matrices of n x m elements
void addMatrix(int** matrixA, int** matrixB, int** output, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            output[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

// function to subtract two matrices of n x m elements
void subtractMatrix(int** matrixA, int** matrixB, int** output, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            output[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

// function to multiply two matrices of n x m and m x p elements
void multiplyMatrix(int** matrixA, int** matrixB, int** output, int n, int m, int p) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            output[i][j] = 0;
            for (int k = 0; k < m; k++) {
                output[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

int main() {
    // Initialize matrices A and B
    int n = 3;
    int m = 3;
    int p = 3;
    int** matrixA = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matrixA[i] = (int*) malloc(m * sizeof(int));
    }
    matrixA[0][0] = 1; matrixA[0][1] = 2; matrixA[0][2] = 3;
    matrixA[1][0] = 4; matrixA[1][1] = 5; matrixA[1][2] = 6;
    matrixA[2][0] = 7; matrixA[2][1] = 8; matrixA[2][2] = 9;

    int** matrixB = (int**) malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        matrixB[i] = (int*) malloc(p * sizeof(int));
    }
    matrixB[0][0] = 1; matrixB[0][1] = 0; matrixB[0][2] = 0;
    matrixB[1][0] = 0; matrixB[1][1] = 1; matrixB[1][2] = 0;
    matrixB[2][0] = 0; matrixB[2][1] = 0; matrixB[2][2] = 1;

    // Initialize output matrix to zeros
    int** output = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        output[i] = (int*) malloc(p * sizeof(int));
        for (int j = 0; j < p; j++) {
            output[i][j] = 0;
        }
    }

    // Test matrix add, subtract, and multiply operations
    addMatrix(matrixA, matrixB, output, n, m);
    printMatrix(output, n, p);

    subtractMatrix(matrixA, matrixB, output, n, m);
    printMatrix(output, n, p);

    multiplyMatrix(matrixA, matrixB, output, n, m, p);
    printMatrix(output, n, p);

    // Free memory allocated for matrices
    for (int i = 0; i < n; i++) {
        free(matrixA[i]);
        free(output[i]);
    }
    for (int i = 0; i < m; i++) {
        free(matrixB[i]);
    }
    free(matrixA);
    free(matrixB);
    free(output);

    return 0;
}