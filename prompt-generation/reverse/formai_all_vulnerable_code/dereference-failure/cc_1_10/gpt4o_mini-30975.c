//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform matrix multiplication
void matrix_multiply(int size, int **A, int **B, int **C) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = 0;
            for (int k = 0; k < size; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Function to allocate a matrix
int **allocate_matrix(int size) {
    int **matrix = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        matrix[i] = (int *)malloc(size * sizeof(int));
    }
    return matrix;
}

// Function to fill matrix with random values
void fill_matrix(int **matrix, int size, int upper_bound) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % upper_bound;
        }
    }
}

// Function to free allocated matrix
void free_matrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to print the matrix (optional, for verification)
void print_matrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    
    int size = 512; // Size of the matrix
    int upper_bound = 100; // Upper bound for random values

    // Allocate matrices
    int **A = allocate_matrix(size);
    int **B = allocate_matrix(size);
    int **C = allocate_matrix(size);

    // Fill matrices A and B with random values
    fill_matrix(A, size, upper_bound);
    fill_matrix(B, size, upper_bound);

    // Start benchmarking
    clock_t start = clock();

    // Perform matrix multiplication
    matrix_multiply(size, A, B, C);

    // End benchmarking
    clock_t end = clock();
    
    // Calculate elapsed time in seconds
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Output the runtime of the matrix multiplication
    printf("Matrix multiplication of size %d took %f seconds.\n", size, cpu_time_used);

    // Free allocated memory
    free_matrix(A, size);
    free_matrix(B, size);
    free_matrix(C, size);

    return 0;
}