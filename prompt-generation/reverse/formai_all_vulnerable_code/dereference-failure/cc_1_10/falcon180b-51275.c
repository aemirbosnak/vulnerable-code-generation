//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

int main() {
    int i, j, n;
    double *arr1, *arr2, *result;
    clock_t start, end;

    // Allocate memory for arrays
    arr1 = (double*) malloc(MAX_SIZE * sizeof(double));
    arr2 = (double*) malloc(MAX_SIZE * sizeof(double));
    result = (double*) malloc(MAX_SIZE * sizeof(double));

    // Initialize arrays with random values
    for (i = 0; i < MAX_SIZE; i++) {
        arr1[i] = rand() % 1000;
        arr2[i] = rand() % 1000;
    }

    // Start timer
    start = clock();

    // Perform matrix multiplication
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            result[i * MAX_SIZE + j] = 0;
            for (n = 0; n < MAX_SIZE; n++) {
                result[i * MAX_SIZE + j] += arr1[i * MAX_SIZE + n] * arr2[n * MAX_SIZE + j];
            }
        }
    }

    // Stop timer
    end = clock();

    // Print result and time taken
    printf("Result:\n");
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            printf("%lf ", result[i * MAX_SIZE + j]);
        }
        printf("\n");
    }

    printf("\nTime taken: %lf seconds\n", (double) (end - start) / CLOCKS_PER_SEC);

    // Free memory
    free(arr1);
    free(arr2);
    free(result);

    return 0;
}