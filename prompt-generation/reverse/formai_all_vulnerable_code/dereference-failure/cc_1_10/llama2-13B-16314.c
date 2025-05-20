//LLAMA2-13B DATASET v1.0 Category: Benchmarking ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 100000
#define M 1000

int main() {
    double start, end, elapsed;
    double *arr1, *arr2, *arr3;
    int i, j, k;

    // Initialize arrays
    arr1 = (double*)calloc(N, sizeof(double));
    arr2 = (double*)calloc(N, sizeof(double));
    arr3 = (double*)calloc(N, sizeof(double));

    // Generate random numbers
    for (i = 0; i < N; i++) {
        arr1[i] = drand48() * 10.0 - 5.0;
        arr2[i] = drand48() * 10.0 - 5.0;
        arr3[i] = drand48() * 10.0 - 5.0;
    }

    // Loop 1000 times
    for (k = 0; k < 1000; k++) {
        // Initialize timers
        clock_t start_time = clock();

        // Loop 1000 times
        for (j = 0; j < M; j++) {
            // Inner loop
            for (i = 0; i < N; i++) {
                arr2[i] = arr1[i] + arr3[i];
            }
        }

        // End timer
        clock_t end_time = clock();
        elapsed = (double)(end_time - start_time) / CLOCKS_PER_SEC;

        // Print timing information
        printf("Iteration %d: Elapsed time = %f seconds\n", k, elapsed);
    }

    // Free memory
    free(arr1);
    free(arr2);
    free(arr3);

    return 0;
}