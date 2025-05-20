//FormAI DATASET v1.0 Category: Benchmarking ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MATRIX_SIZE 1000

// Benchmarks the multiplication of two matrices
void matrix_mult(int **a, int **b, int **c) {
    int i, j, k;

    for (i = 0; i < MATRIX_SIZE; i++) {
        for (j = 0; j < MATRIX_SIZE; j++) {
            c[i][j] = 0;
            for (k = 0; k < MATRIX_SIZE; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// Generates a random matrix of size MATRIX_SIZE x MATRIX_SIZE
void generate_matrix(int **matrix) {
    int i, j;

    for (i = 0; i < MATRIX_SIZE; i++) {
        for (j = 0; j < MATRIX_SIZE; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

int main() {
    int **a, **b, **c;
    int i, j;

    srand(time(NULL));

    // Allocate memory for the matrices
    a = (int **)malloc(MATRIX_SIZE * sizeof(int *));
    b = (int **)malloc(MATRIX_SIZE * sizeof(int *));
    c = (int **)malloc(MATRIX_SIZE * sizeof(int *));
    for (i = 0; i < MATRIX_SIZE; i++) {
        a[i] = (int *)malloc(MATRIX_SIZE * sizeof(int));
        b[i] = (int *)malloc(MATRIX_SIZE * sizeof(int));
        c[i] = (int *)malloc(MATRIX_SIZE * sizeof(int));
    }

    // Generate random matrices
    generate_matrix(a);
    generate_matrix(b);

    // Benchmark the multiplication of the matrices
    clock_t start = clock();
    matrix_mult(a, b, c);
    clock_t end = clock();

    // Print the result matrix
    printf("Result Matrix:\n");
    for (i = 0; i < MATRIX_SIZE; i++) {
        for (j = 0; j < MATRIX_SIZE; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    // Print the benchmark time
    double time_taken = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("Matrix multiplication took %f seconds to execute.\n", time_taken);

    // Free memory
    for (i = 0; i < MATRIX_SIZE; i++) {
        free(a[i]);
        free(b[i]);
        free(c[i]);
    }
    free(a);
    free(b);
    free(c);

    return 0;
}