//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to perform matrix multiplication
void matrix_multiply(int **A, int **B, int **C, int m, int n) {
    int i, j, k;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                C[i][k] += A[i][j] * B[j][k];
            }
        }
    }
}

// Function to perform matrix addition
void matrix_add(int **A, int **B, int **C, int m, int n) {
    int i, j, k;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                C[i][k] += A[i][j] + B[i][k];
            }
        }
    }
}

int main() {
    int m = 3, n = 4;
    int **A, **B, **C;
    A = (int **) malloc(m * sizeof(int *));
    B = (int **) malloc(n * sizeof(int *));
    C = (int **) malloc(m * sizeof(int *));

    // Initialize matrices
    for (int i = 0; i < m; i++) {
        A[i] = (int *) malloc(n * sizeof(int));
        B[i] = (int *) malloc(n * sizeof(int));
        C[i] = (int *) malloc(n * sizeof(int));

        for (int j = 0; j < n; j++) {
            A[i][j] = i * j;
            B[i][j] = i + j;
            C[i][j] = 0;
        }
    }

    // Perform matrix multiplication
    matrix_multiply(A, B, C, m, n);

    // Print the result
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    // Perform matrix addition
    matrix_add(A, B, C, m, n);

    // Print the result
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}