//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Define variables
    int size, i;
    double *array1, *array2, *result;
    clock_t start, end;
    double cpu_time_used;

    // Get input size from user
    printf("Enter the size of the arrays: ");
    scanf("%d", &size);

    // Allocate memory for arrays
    array1 = (double *) malloc(size * sizeof(double));
    array2 = (double *) malloc(size * sizeof(double));
    result = (double *) malloc(size * sizeof(double));

    // Initialize arrays with random numbers
    for (i = 0; i < size; i++) {
        array1[i] = rand() % 100;
        array2[i] = rand() % 100;
    }

    // Start timer
    start = clock();

    // Multiply arrays
    for (i = 0; i < size; i++) {
        result[i] = array1[i] * array2[i];
    }

    // Stop timer
    end = clock();

    // Calculate CPU time used
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Print results
    printf("Size of arrays: %d\n", size);
    printf("Multiplication completed in %.6f seconds.\n", cpu_time_used);

    // Free memory
    free(array1);
    free(array2);
    free(result);

    return 0;
}