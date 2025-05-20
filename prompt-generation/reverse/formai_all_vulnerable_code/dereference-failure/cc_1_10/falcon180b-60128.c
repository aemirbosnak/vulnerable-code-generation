//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 1000000

int main() {
    double *a, *b, *c;
    int i, j, k;
    clock_t start, end;

    // Allocate memory for arrays
    a = (double*) malloc(SIZE * sizeof(double));
    b = (double*) malloc(SIZE * sizeof(double));
    c = (double*) malloc(SIZE * sizeof(double));

    // Initialize arrays
    for (i = 0; i < SIZE; i++) {
        a[i] = i;
        b[i] = i * 2;
        c[i] = 0;
    }

    // Start timing
    start = clock();

    // Perform matrix multiplication
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            for (k = 0; k < SIZE; k++) {
                c[i*SIZE+j] += a[i*SIZE+k] * b[k*SIZE+j];
            }
        }
    }

    // Stop timing
    end = clock();

    // Calculate elapsed time
    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

    // Print results
    printf("Matrix multiplication completed in %f seconds.\n", elapsed_time);

    // Free memory
    free(a);
    free(b);
    free(c);

    return 0;
}