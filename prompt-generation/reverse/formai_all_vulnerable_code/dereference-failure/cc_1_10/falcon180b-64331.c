//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define RANDOM_SEED 42

int main(int argc, char *argv[]) {
    int i, j;
    double *array1, *array2;
    clock_t start, end;
    double cpu_time_used;

    // Initialize random seed
    srand(RANDOM_SEED);

    // Allocate memory for arrays
    array1 = (double *)malloc(MAX_SIZE * sizeof(double));
    array2 = (double *)malloc(MAX_SIZE * sizeof(double));

    // Initialize arrays with random numbers
    for (i = 0; i < MAX_SIZE; i++) {
        array1[i] = rand() % 1000;
        array2[i] = rand() % 1000;
    }

    // Start timer
    start = clock();

    // Perform matrix multiplication
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            array1[i] += array2[i * MAX_SIZE + j] * array1[j];
        }
    }

    // Stop timer
    end = clock();

    // Calculate CPU time used
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Print results
    printf("Matrix multiplication completed in %lf seconds.\n", cpu_time_used);

    // Free memory
    free(array1);
    free(array2);

    return 0;
}