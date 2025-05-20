//LLAMA2-13B DATASET v1.0 Category: Benchmarking ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000
#define M 10000

int main() {
    double start, end;
    int i, j, k;
    double sum = 0;

    // Initialize the arrays
    double *a = calloc(N, sizeof(double));
    double *b = calloc(N, sizeof(double));
    double *c = calloc(N, sizeof(double));

    // Fill the arrays with random numbers
    for (i = 0; i < N; i++) {
        a[i] = drand48() * 10.0 - 5.0;
        b[i] = drand48() * 10.0 - 5.0;
        c[i] = a[i] + b[i];
    }

    // Compute the sum of the elements in the arrays
    for (i = 0; i < N; i++) {
        sum += a[i] + b[i];
    }

    // Benchmark the addition of two arrays
    for (i = 0; i < M; i++) {
        start = clock();
        for (j = 0; j < N; j++) {
            c[j] = a[j] + b[j];
        }
        end = clock();
        double time = (end - start) / CLOCKS_PER_SEC;
        printf("Time for %d array additions: %f seconds\n", M, time);
    }

    // Benchmark the multiplication of two arrays
    for (i = 0; i < M; i++) {
        start = clock();
        for (j = 0; j < N; j++) {
            c[j] = a[j] * b[j];
        }
        end = clock();
        double time = (end - start) / CLOCKS_PER_SEC;
        printf("Time for %d array multiplications: %f seconds\n", M, time);
    }

    // Free the memory
    free(a);
    free(b);
    free(c);

    return 0;
}