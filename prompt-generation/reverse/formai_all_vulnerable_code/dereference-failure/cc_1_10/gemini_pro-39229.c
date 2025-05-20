//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_REPS 1000000

int main(int argc, char *argv[]) {
    int i, j, k;
    clock_t start, end;
    double time_taken;

    // Allocate memory for the arrays
    int *a = (int *)malloc(NUM_REPS * sizeof(int));
    int *b = (int *)malloc(NUM_REPS * sizeof(int));
    int *c = (int *)malloc(NUM_REPS * sizeof(int));

    // Initialize the arrays
    for (i = 0; i < NUM_REPS; i++) {
        a[i] = i;
        b[i] = i + 1;
        c[i] = 0;
    }

    // Start the timer
    start = clock();

    // Perform the operations
    for (i = 0; i < NUM_REPS; i++) {
        for (j = 0; j < NUM_REPS; j++) {
            for (k = 0; k < NUM_REPS; k++) {
                c[i] += a[j] * b[k];
            }
        }
    }

    // Stop the timer
    end = clock();

    // Calculate the time taken
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Print the time taken
    printf("Time taken: %f seconds\n", time_taken);

    // Free the memory
    free(a);
    free(b);
    free(c);

    return 0;
}