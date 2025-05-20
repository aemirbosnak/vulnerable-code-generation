//LLAMA2-13B DATASET v1.0 Category: Benchmarking ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define N 10000
#define M 100
#define MAX_ITER 1000

void bench_ops(const char* name, int n, int m, int iter) {
    int i, j, k;
    double sum = 0;
    double mean = 0;
    double stddev = 0;

    // Initialize random data
    srand(time(NULL));
    double* data = malloc(n * sizeof(double));
    for (i = 0; i < n; i++) {
        data[i] = (double)rand() / RAND_MAX;
    }

    // Warm up
    for (i = 0; i < M; i++) {
        for (j = 0; j < m; j++) {
            sum += data[j];
        }
        mean = sum / m;
        sum = 0;
    }

    // Benchmark
    for (i = 0; i < iter; i++) {
        for (j = 0; j < m; j++) {
            sum += data[j];
        }
        mean = sum / m;
        sum = 0;
    }

    // Calculate standard deviation
    for (j = 0; j < m; j++) {
        sum += (data[j] - mean) * (data[j] - mean);
    }
    stddev = sqrt(sum / (m - 1));

    // Print results
    printf("%s: mean = %f, stddev = %f\n", name, mean, stddev);
}

int main() {
    int i;

    // Warm up
    for (i = 0; i < M; i++) {
        bench_ops("warm up", N, M, MAX_ITER);
    }

    // Benchmark
    for (i = 0; i < MAX_ITER; i++) {
        bench_ops("benchmark", N, M, MAX_ITER);
    }

    return 0;
}