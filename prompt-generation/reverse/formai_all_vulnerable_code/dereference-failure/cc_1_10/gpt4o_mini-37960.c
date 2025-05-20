//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MATRIX_SIZE 512

void initialize_matrix(double **matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = (double)(rand() % 100); // Initialize with random values
        }
    }
}

void free_matrix(double **matrix, int size) {
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

double** allocate_matrix(int size) {
    double **matrix = malloc(size * sizeof(double*));
    for (int i = 0; i < size; i++) {
        matrix[i] = malloc(size * sizeof(double));
    }
    return matrix;
}

void multiply_matrices(double **matrixA, double **matrixB, double **result, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = 0.0; // Initialize result element to zero
            for (int k = 0; k < size; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j]; // Perform multiplication
            }
        }
    }
}

void print_matrix(double **matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%5.1f ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    double **matrixA = allocate_matrix(MATRIX_SIZE);
    double **matrixB = allocate_matrix(MATRIX_SIZE);
    double **result = allocate_matrix(MATRIX_SIZE);

    // Initialize matrices
    initialize_matrix(matrixA, MATRIX_SIZE);
    initialize_matrix(matrixB, MATRIX_SIZE);

    clock_t start_time = clock();
    multiply_matrices(matrixA, matrixB, result, MATRIX_SIZE);
    clock_t end_time = clock();

    // Optionally print the result matrix
    // print_matrix(result, 10); // Print a small part of the result to avoid clutter

    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Matrix multiplication completed in %f seconds.\n", time_taken);

    // Free allocated matrices
    free_matrix(matrixA, MATRIX_SIZE);
    free_matrix(matrixB, MATRIX_SIZE);
    free_matrix(result, MATRIX_SIZE);

    return 0;
}