//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: Linus Torvalds
/*
 * This is a performance-critical component that optimizes matrix multiply.
 * I do not apologize for the complexity of the code. Optimization is not for the weak.
 *
 * Written by Linus Torvalds (not really)
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MATRIX_SIZE 1000

void multiply_matrices(double *A, double *B, double *C, int size)
{
    int i, j, k;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            C[i*size+j] = 0.0;
            for (k = 0; k < size; k++) {
                C[i*size+j] += A[i*size+k] * B[k*size+j];
            }
        }
    }
}

int main()
{
    double *A, *B, *C;
    clock_t start, end;
    double cpu_time_used;

    // Allocate memory for matrices
    A = (double*) malloc(MATRIX_SIZE * MATRIX_SIZE * sizeof(double));
    B = (double*) malloc(MATRIX_SIZE * MATRIX_SIZE * sizeof(double));
    C = (double*) malloc(MATRIX_SIZE * MATRIX_SIZE * sizeof(double));

    // Initialize matrices with random values between 0.0 and 1.0
    srand(time(NULL));
    for (int i = 0; i < MATRIX_SIZE * MATRIX_SIZE; i++) {
        A[i] = ((double) rand()) / ((double) RAND_MAX);
        B[i] = ((double) rand()) / ((double) RAND_MAX);
    }

    // Multiply matrices and time it
    start = clock();
    multiply_matrices(A, B, C, MATRIX_SIZE);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Matrix size = %d x %d\n", MATRIX_SIZE, MATRIX_SIZE);
    printf("Execution time = %f seconds\n", cpu_time_used);

    // Free memory
    free(A);
    free(B);
    free(C);

    return 0;
}