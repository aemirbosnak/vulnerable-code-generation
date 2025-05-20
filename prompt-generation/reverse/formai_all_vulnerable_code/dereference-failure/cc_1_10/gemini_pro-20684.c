//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Benchmarking function
double benchmark(void (*func)(void *), void *arg, long int iterations) {
    clock_t start, end;
    double elapsed;

    // Warm-up run
    func(arg);

    // Start timing
    start = clock();
    for (long int i = 0; i < iterations; i++) {
        func(arg);
    }

    // Stop timing
    end = clock();

    // Calculate elapsed time
    elapsed = ((double)(end - start)) / CLOCKS_PER_SEC;

    return elapsed;
}

// Function to benchmark
void sum_array(int *array, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
}

// Main function
int main() {
    // Initialize array
    int size = 1000000;
    int *array = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        array[i] = i;
    }

    // Benchmark function
    double elapsed = benchmark(sum_array, array, size);

    // Print results
    printf("Elapsed time: %f seconds\n", elapsed);

    // Clean up
    free(array);

    return 0;
}