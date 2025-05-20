//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: relaxed
// C Performance-Critical Component: Fast Matrix Multiplication

// Assumptions:
// - Square matrices with side length `N`
// - Matrix elements are 64-bit integers
// - Input and output matrices are allocated beforehand

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

// Matrix multiplication function
static void matrix_multiply(int64_t* C, const int64_t* A, const int64_t* B, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int64_t sum = 0;
            for (int k = 0; k < N; k++) {
                sum += A[i * N + k] * B[k * N + j];
            }
            C[i * N + j] = sum;
        }
    }
}

int main(void) {
    int N = 1000;  // Matrix side length
    
    // Allocate memory for matrices
    int64_t* A = malloc(N * N * sizeof(int64_t));
    int64_t* B = malloc(N * N * sizeof(int64_t));
    int64_t* C = malloc(N * N * sizeof(int64_t));
    
    // Initialize matrices with random values
    for (int i = 0; i < N * N; i++) {
        A[i] = rand() % 10000;
        B[i] = rand() % 10000;
    }

    // Perform the matrix multiplication
    matrix_multiply(C, A, B, N);

    // Print the result (for small matrices)
    if (N <= 10) {
        printf("Result matrix C:\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%ld ", C[i * N + j]);
            }
            printf("\n");
        }
    }
    
    // Free allocated memory
    free(A);
    free(B);
    free(C);
    
    return 0;
}