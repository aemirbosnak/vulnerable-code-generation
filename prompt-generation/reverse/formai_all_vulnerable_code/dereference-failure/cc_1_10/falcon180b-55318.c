//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 10000000
#define MAX_ITERATIONS 1000

int main() {
    int i, j;
    double *array1, *array2, *result;
    double sum = 0.0;
    int size;
    int iterations;
    struct timespec start, end;

    printf("Enter the size of the arrays: ");
    scanf("%d", &size);

    if (size > MAX_SIZE) {
        printf("Error: Array size too large.\n");
        return 1;
    }

    array1 = (double *) malloc(size * sizeof(double));
    array2 = (double *) malloc(size * sizeof(double));
    result = (double *) malloc(size * sizeof(double));

    for (i = 0; i < size; i++) {
        array1[i] = i + 1.0;
        array2[i] = i + 2.0;
    }

    printf("Enter the number of iterations: ");
    scanf("%d", &iterations);

    if (iterations > MAX_ITERATIONS) {
        printf("Error: Too many iterations.\n");
        return 1;
    }

    for (i = 0; i < iterations; i++) {
        clock_gettime(CLOCK_MONOTONIC, &start);
        for (j = 0; j < size; j++) {
            result[j] = array1[j] + array2[j];
        }
        clock_gettime(CLOCK_MONOTONIC, &end);
        sum += (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;
    }

    printf("The sum of %d iterations is: %.9f\n", iterations, sum);

    free(array1);
    free(array2);
    free(result);

    return 0;
}