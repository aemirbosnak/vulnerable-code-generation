//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 10000

int main() {
    int i, j;
    double *arr1, *arr2, *result;
    clock_t start, end;

    // Allocate memory for arrays
    arr1 = (double *) malloc(MAX_SIZE * sizeof(double));
    arr2 = (double *) malloc(MAX_SIZE * sizeof(double));
    result = (double *) malloc(MAX_SIZE * sizeof(double));

    // Generate random arrays
    srand(time(NULL));
    for (i = 0; i < MAX_SIZE; i++) {
        arr1[i] = rand() % 100;
        arr2[i] = rand() % 100;
    }

    // Start timer
    start = clock();

    // Multiply arrays
    for (i = 0; i < MAX_SIZE; i++) {
        result[i] = arr1[i] * arr2[i];
    }

    // Stop timer
    end = clock();

    // Print result
    for (i = 0; i < MAX_SIZE; i++) {
        printf("%f ", result[i]);
    }
    printf("\n");

    // Free memory
    free(arr1);
    free(arr2);
    free(result);

    // Print execution time
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Execution time: %f seconds\n", cpu_time_used);

    return 0;
}