//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define M 3
#define N 4

// Declare matrices
float A[M][N] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
};

float B[M][N] = {
    {13, 14, 15, 16},
    {17, 18, 19, 20},
    {21, 22, 23, 24}
};

float C[M][N] = {0};

// Function to perform matrix addition
void add_matrices(float (*A)[M], float (*B)[M], float (*C)[M]) {
    int i, j, k;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < M; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Function to perform matrix multiplication
void multiply_matrices(float (*A)[M], float (*B)[N], float (*C)[M*N]) {
    int i, j, k;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            C[i][j] = 0;
            for (k = 0; k < M; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    // Perform matrix addition
    add_matrices(A, B, C);

    // Print the result
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%.2f ", C[i][j]);
        }
        printf("\n");
    }

    // Perform matrix multiplication
    multiply_matrices(A, B, C);

    // Print the result
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%.2f ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}