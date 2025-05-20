//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 1000000
#define ITERATIONS 100

int main() {
    int i, j, k;
    double *array1, *array2, *result;
    clock_t start, end;

    srand(time(NULL));

    // Initialize arrays with random values
    array1 = (double*) malloc(SIZE * sizeof(double));
    array2 = (double*) malloc(SIZE * sizeof(double));
    for (i = 0; i < SIZE; i++) {
        array1[i] = rand() % 100;
        array2[i] = rand() % 100;
    }

    // Perform matrix multiplication
    result = (double*) malloc(SIZE * sizeof(double));
    start = clock();
    for (k = 0; k < ITERATIONS; k++) {
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                result[i * SIZE + j] += array1[i * SIZE + k] * array2[k * SIZE + j];
            }
        }
    }
    end = clock();

    // Print result and execution time
    printf("Result:\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%lf ", result[i * SIZE + j]);
        }
        printf("\n");
    }

    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nCPU time used: %lf seconds\n", cpu_time_used);

    free(array1);
    free(array2);
    free(result);

    return 0;
}