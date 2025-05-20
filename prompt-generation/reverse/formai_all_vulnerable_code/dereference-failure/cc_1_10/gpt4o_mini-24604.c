//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1024  // Dimension of the matrices

void initialize_matrices(int a[N][N], int b[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            a[i][j] = rand() % 100;  // Initialize matrix a with random values
            b[i][j] = rand() % 100;  // Initialize matrix b with random values
        }
    }
}

void print_matrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void multiply_matrices(int a[N][N], int b[N][N], int result[N][N]) {
    // Matrix multiplication with loop interchanging for better cache performance
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = 0;  // Initialize result cell to 0
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    srand(time(NULL));  // Seed for random number generation
    int (*a)[N] = malloc(N * N * sizeof(int));  // Dynamic allocation for matrix a
    int (*b)[N] = malloc(N * N * sizeof(int));  // Dynamic allocation for matrix b
    int (*result)[N] = malloc(N * N * sizeof(int));  // Dynamic allocation for result matrix

    if (a == NULL || b == NULL || result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    initialize_matrices(a, b);  // Initialize matrices with random values

    clock_t start_time = clock();  // Start timing the operation

    multiply_matrices(a, b, result);  // Perform matrix multiplication

    clock_t end_time = clock();  // End timing the operation

    double time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;  // Calculate elapsed time

    printf("Matrix multiplication completed in %f seconds\n", time_spent);

    // Uncomment to print matrices (may slow down due to large size)
    // print_matrix(a);
    // print_matrix(b);
    // print_matrix(result);

    free(a);  // Free allocated memory for matrix a
    free(b);  // Free allocated memory for matrix b
    free(result);  // Free allocated memory for result matrix

    return 0;
}