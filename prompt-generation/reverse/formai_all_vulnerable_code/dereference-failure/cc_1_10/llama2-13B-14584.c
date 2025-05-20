//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform matrix multiplication
void mat_mult(int m, int n, int p, double *A, double *B, double *C) {
    int i, j, k;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < p; k++) {
                C[i * n * p + j * p + k] = A[i * m * n + j * m + k] * B[k * p + j * p + i];
            }
        }
    }
}

// Function to perform matrix addition
void mat_add(int m, int n, int p, double *A, double *B, double *C) {
    int i, j, k;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < p; k++) {
                C[i * n * p + j * p + k] = A[i * m * n + j * m + k] + B[i * m * n + j * m + k];
            }
        }
    }
}

// Function to perform matrix inversion
double mat_inv(int m, int n, double *A) {
    int i, j;
    double det = 1, inv_det = 1;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            det *= A[i * n + j] * A[j * m + i];
            inv_det *= A[i * n + j] * A[j * m + i];
        }
    }
    return inv_det / det;
}

int main() {
    int m = 3, n = 3, p = 2;
    double *A, *B, *C, *D;

    // Initialize matrices
    A = malloc(m * n * sizeof(double));
    B = malloc(n * p * sizeof(double));
    C = malloc(m * p * sizeof(double));
    D = malloc(m * n * sizeof(double));

    // Fill matrices
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            A[i * n + j] = i + j;
            B[j * p + i] = j + i;
        }
    }

    // Perform matrix multiplication
    mat_mult(m, n, p, A, B, C);

    // Perform matrix addition
    mat_add(m, n, p, A, B, D);

    // Perform matrix inversion
    double inv = mat_inv(m, n, A);

    // Print results
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2f ", D[i * n + j]);
        }
        printf("\n");
    }

    free(A);
    free(B);
    free(C);
    free(D);

    return 0;
}