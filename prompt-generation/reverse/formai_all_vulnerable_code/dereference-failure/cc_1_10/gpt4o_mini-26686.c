//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1024   // Size of the matrices
#define BLOCK_SIZE 32  // Size of the block for cache optimization

void matrix_multiply(float *A, float *B, float *C, int n) {
    for (int i = 0; i < n; i += BLOCK_SIZE) {
        for (int j = 0; j < n; j += BLOCK_SIZE) {
            for (int k = 0; k < n; k += BLOCK_SIZE) {
                // Block multiplication
                for (int ii = i; ii < i + BLOCK_SIZE && ii < n; ii++) {
                    for (int jj = j; jj < j + BLOCK_SIZE && jj < n; jj++) {
                        float sum = 0.0f;
                        for (int kk = k; kk < k + BLOCK_SIZE && kk < n; kk++) {
                            sum += A[ii * n + kk] * B[kk * n + jj];
                        }
                        C[ii * n + jj] += sum;
                    }
                }
            }
        }
    }
}

void initialize_matrix(float *matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i * n + j] = (float)(rand() % 100);
        }
    }
}

void print_matrix(float *matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%5.1f ", matrix[i * n + j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    float *A = (float *)malloc(N * N * sizeof(float));
    float *B = (float *)malloc(N * N * sizeof(float));
    float *C = (float *)malloc(N * N * sizeof(float));

    // Initialize matrices A and B, and C to zero
    initialize_matrix(A, N);
    initialize_matrix(B, N);
    for (int i = 0; i < N * N; i++) {
        C[i] = 0.0f;
    }

    // Performance measurement
    clock_t start = clock();
    matrix_multiply(A, B, C, N);
    clock_t end = clock();

    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken for matrix multiplication: %f seconds\n", elapsed_time);

    // Uncomment the following line to print the result matrix
    // print_matrix(C, N);

    // Free allocated memory
    free(A);
    free(B);
    free(C);

    return 0;
}