//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: future-proof
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the number of iterations for the benchmark.
#define ITERATIONS 10000000

// Define the size of the data array.
#define DATA_SIZE 1024

// Define the number of threads to use for the benchmark.
#define THREADS 4

// Define the structure of the data array.
typedef struct {
    double x;
    double y;
    double z;
} data_t;

// Define the function to be benchmarked.
double benchmark_function(const data_t *data, size_t size) {
    double sum = 0.0;
    for (size_t i = 0; i < size; i++) {
        sum += data[i].x + data[i].y + data[i].z;
    }
    return sum;
}

// Define the function to run the benchmark.
void run_benchmark(const data_t *data, size_t size, int threads) {
    // Create a timer.
    clock_t timer = clock();

    // Run the benchmark.
    double sum = 0.0;
    for (int i = 0; i < ITERATIONS; i++) {
        sum += benchmark_function(data, size);
    }

    // Stop the timer.
    timer = clock() - timer;

    // Print the results.
    printf("Time: %f seconds\n", (double)timer / CLOCKS_PER_SEC);
    printf("Sum: %f\n", sum);
}

// Define the main function.
int main() {
    // Allocate memory for the data array.
    data_t *data = malloc(DATA_SIZE * sizeof(data_t));

    // Initialize the data array.
    for (size_t i = 0; i < DATA_SIZE; i++) {
        data[i].x = (double)i;
        data[i].y = (double)(i + 1);
        data[i].z = (double)(i + 2);
    }

    // Run the benchmark.
    run_benchmark(data, DATA_SIZE, THREADS);

    // Free the memory allocated for the data array.
    free(data);

    return 0;
}