//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MATRIX_SIZE 512
#define UNROLL_FACTOR 4

// Function to print the matrix (for verification purposes)
void printMatrix(float *matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%0.1f ", matrix[i * size + j]);
        }
        printf("\n");
    }
}

// Function to initialize the matrix with random values
void initMatrix(float *matrix, int size) {
    for (int i = 0; i < size * size; i++) {
        matrix[i] = (float)(rand() % 100);
    }
}

// Optimized function for matrix multiplication using loop unrolling
void matrixMultiplyOptimized(float *A, float *B, float *C, int size) {
    // Initialize the result matrix C with zeros
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i * size + j] = 0.0f;
        }
    }

    // Perform matrix multiplication with loop unrolling
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j += UNROLL_FACTOR) {
            float sum0 = C[i * size + j];
            float sum1 = C[i * size + j + 1];
            float sum2 = C[i * size + j + 2];
            float sum3 = C[i * size + j + 3];

            for (int k = 0; k < size; k++) {
                sum0 += A[i * size + k] * B[k * size + j];
                sum1 += A[i * size + k] * B[k * size + j + 1];
                sum2 += A[i * size + k] * B[k * size + j + 2];
                sum3 += A[i * size + k] * B[k * size + j + 3];
            }

            C[i * size + j] = sum0;
            C[i * size + j + 1] = sum1;
            C[i * size + j + 1] = sum2;
            C[i * size + j + 2] = sum3;
        }
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    float *A = (float *)malloc(MATRIX_SIZE * MATRIX_SIZE * sizeof(float));
    float *B = (float *)malloc(MATRIX_SIZE * MATRIX_SIZE * sizeof(float));
    float *C = (float *)malloc(MATRIX_SIZE * MATRIX_SIZE * sizeof(float));

    // Check for memory allocation success
    if (A == NULL || B == NULL || C == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return EXIT_FAILURE;
    }

    // Initialize matrices A and B
    initMatrix(A, MATRIX_SIZE);
    initMatrix(B, MATRIX_SIZE);

    // Perform matrix multiplication
    clock_t start = clock();
    matrixMultiplyOptimized(A, B, C, MATRIX_SIZE);
    clock_t end = clock();

    // Calculate and display elapsed time
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Matrix multiplication completed in %f seconds.\n", time_taken);

    // Uncomment to print matrices (beware: large output)
    // printMatrix(A, MATRIX_SIZE);
    // printMatrix(B, MATRIX_SIZE);
    // printMatrix(C, MATRIX_SIZE);

    // Free allocated memory
    free(A);
    free(B);
    free(C);

    return 0;
}