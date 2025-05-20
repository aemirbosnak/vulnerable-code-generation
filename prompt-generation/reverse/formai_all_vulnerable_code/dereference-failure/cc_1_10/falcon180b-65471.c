//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 1000000

int main() {
    int i, j, temp;
    double **matrix1, **matrix2, **result;
    struct timespec start, end;

    // Allocate memory for matrices
    matrix1 = (double **)malloc(sizeof(double *) * SIZE);
    matrix2 = (double **)malloc(sizeof(double *) * SIZE);
    result = (double **)malloc(sizeof(double *) * SIZE);
    for (i = 0; i < SIZE; i++) {
        matrix1[i] = (double *)malloc(sizeof(double) * SIZE);
        matrix2[i] = (double *)malloc(sizeof(double) * SIZE);
        result[i] = (double *)malloc(sizeof(double) * SIZE);
    }

    // Initialize matrices with random values
    srand(time(NULL));
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            matrix1[i][j] = rand() % 100;
            matrix2[i][j] = rand() % 100;
        }
    }

    // Start timer
    clock_gettime(CLOCK_REALTIME, &start);

    // Multiply matrices
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            temp = 0;
            for (int k = 0; k < SIZE; k++) {
                temp += matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] = temp;
        }
    }

    // Stop timer
    clock_gettime(CLOCK_REALTIME, &end);

    // Calculate elapsed time
    double elapsed_time = (end.tv_sec - start.tv_sec) * 1000.0;
    elapsed_time += (end.tv_nsec - start.tv_nsec) / 1000000.0;

    // Print result and elapsed time
    printf("Result:\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%lf ", result[i][j]);
        }
        printf("\n");
    }
    printf("Elapsed time: %lf ms\n", elapsed_time);

    // Free memory
    for (i = 0; i < SIZE; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(result[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}