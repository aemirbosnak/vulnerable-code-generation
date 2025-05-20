//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 1000000
#define NUM_ITERATIONS 1000

int main() {
    int i, j, k;
    double **matrix1, **matrix2, **result;
    clock_t start, end;
    double cpu_time_used;

    srand(time(NULL));

    // Initialize matrices
    matrix1 = (double **)malloc(MAX_SIZE * sizeof(double *));
    matrix2 = (double **)malloc(MAX_SIZE * sizeof(double *));
    result = (double **)malloc(MAX_SIZE * sizeof(double *));
    for (i = 0; i < MAX_SIZE; i++) {
        matrix1[i] = (double *)malloc(MAX_SIZE * sizeof(double));
        matrix2[i] = (double *)malloc(MAX_SIZE * sizeof(double));
        result[i] = (double *)malloc(MAX_SIZE * sizeof(double));
        for (j = 0; j < MAX_SIZE; j++) {
            matrix1[i][j] = rand() % 100;
            matrix2[i][j] = rand() % 100;
        }
    }

    // Perform matrix multiplication
    start = clock();
    for (i = 0; i < NUM_ITERATIONS; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            for (k = 0; k < MAX_SIZE; k++) {
                result[j][k] += matrix1[j][i] * matrix2[i][k];
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Matrix Multiplication Completed in %f seconds\n", cpu_time_used);

    // Free memory
    for (i = 0; i < MAX_SIZE; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(result[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}