//LLAMA2-13B DATASET v1.0 Category: Benchmarking ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define N 10000
#define M 1000
#define ITER 1000

int main() {
    double *a, *b, *c, *d, *e;
    int i, j, k;

    // Initialize arrays
    for (i = 0; i < N; i++) {
        a[i] = (double)i / 10.0;
        b[i] = (double)(i * 10) / 100.0;
        c[i] = (double)(i * 100) / 1000.0;
        d[i] = (double)(i * 1000) / 10000.0;
        e[i] = (double)(i * 10000) / 100000.0;
    }

    // Set up timing
    clock_t start, end;
    double time_elapsed;
    start = clock();

    // Benchmarking loop
    for (k = 0; k < ITER; k++) {
        for (j = 0; j < M; j++) {
            for (i = 0; i < N; i++) {
                // Operations on arrays a, b, c, d, and e
                c[i] = a[i] + b[i];
                d[i] = c[i] + e[i];
                e[i] = d[i] + c[i];
            }
        }
    }

    end = clock();
    time_elapsed = (end - start) / CLOCKS_PER_SEC;
    printf("Time elapsed: %f seconds\n", time_elapsed);

    // Print results
    for (i = 0; i < N; i++) {
        printf("%.4f + %.4f = %.4f\n", a[i], b[i], c[i]);
        printf("%.4f + %.4f = %.4f\n", c[i], e[i], d[i]);
    }

    return 0;
}