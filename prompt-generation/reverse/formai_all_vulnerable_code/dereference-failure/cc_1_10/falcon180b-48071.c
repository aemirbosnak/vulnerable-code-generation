//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

int main() {
    int i, j, n;
    double *array1, *array2, *array3;
    clock_t start, end;

    // Allocate memory for arrays
    array1 = (double *) malloc(MAX_SIZE * sizeof(double));
    array2 = (double *) malloc(MAX_SIZE * sizeof(double));
    array3 = (double *) malloc(MAX_SIZE * sizeof(double));

    // Initialize arrays with random numbers
    srand(time(NULL));
    for (i = 0; i < MAX_SIZE; i++) {
        array1[i] = rand() % 1000;
        array2[i] = rand() % 1000;
    }

    // Measure time for addition
    start = clock();
    for (i = 0; i < MAX_SIZE; i++) {
        array3[i] = array1[i] + array2[i];
    }
    end = clock();
    printf("Time for addition: %f seconds\n", (double) (end - start) / CLOCKS_PER_SEC);

    // Measure time for subtraction
    start = clock();
    for (i = 0; i < MAX_SIZE; i++) {
        array3[i] = array1[i] - array2[i];
    }
    end = clock();
    printf("Time for subtraction: %f seconds\n", (double) (end - start) / CLOCKS_PER_SEC);

    // Measure time for multiplication
    start = clock();
    for (i = 0; i < MAX_SIZE; i++) {
        array3[i] = array1[i] * array2[i];
    }
    end = clock();
    printf("Time for multiplication: %f seconds\n", (double) (end - start) / CLOCKS_PER_SEC);

    // Measure time for division
    start = clock();
    for (i = 0; i < MAX_SIZE; i++) {
        array3[i] = array1[i] / array2[i];
    }
    end = clock();
    printf("Time for division: %f seconds\n", (double) (end - start) / CLOCKS_PER_SEC);

    // Free memory
    free(array1);
    free(array2);
    free(array3);

    return 0;
}