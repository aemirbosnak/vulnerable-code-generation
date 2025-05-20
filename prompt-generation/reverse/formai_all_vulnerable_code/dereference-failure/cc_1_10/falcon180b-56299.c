//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 1000000
#define NUM_REPEATS 10

int main() {
    int i, j, k;
    double **matrix1, **matrix2, **result;
    clock_t start, end;
    double cpu_time_used;

    // Allocate memory for matrices
    matrix1 = (double **)malloc(sizeof(double *) * MAX_SIZE);
    for (i = 0; i < MAX_SIZE; i++) {
        matrix1[i] = (double *)malloc(sizeof(double) * MAX_SIZE);
    }

    matrix2 = (double **)malloc(sizeof(double *) * MAX_SIZE);
    for (i = 0; i < MAX_SIZE; i++) {
        matrix2[i] = (double *)malloc(sizeof(double) * MAX_SIZE);
    }

    result = (double **)malloc(sizeof(double *) * MAX_SIZE);
    for (i = 0; i < MAX_SIZE; i++) {
        result[i] = (double *)malloc(sizeof(double) * MAX_SIZE);
    }

    // Initialize matrices with random values
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            matrix1[i][j] = (double)rand() / RAND_MAX;
            matrix2[i][j] = (double)rand() / RAND_MAX;
        }
    }

    // Measure time for matrix multiplication
    start = clock();
    for (k = 0; k < NUM_REPEATS; k++) {
        for (i = 0; i < MAX_SIZE; i++) {
            for (j = 0; j < MAX_SIZE; j++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Time taken for matrix multiplication: %f\n", cpu_time_used);

    // Free memory allocated for matrices
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