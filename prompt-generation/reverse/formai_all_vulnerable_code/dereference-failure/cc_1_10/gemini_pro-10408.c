//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to store the result of the benchmark
typedef struct {
    double time_taken;
    int operations_performed;
} benchmark_result;

// Function to perform the benchmark
benchmark_result benchmark(int *array, int n, int iterations) {
    clock_t start_time = clock();

    // Perform the operations to be benchmarked
    for (int i = 0; i < iterations; i++) {
        for (int j = 0; j < n; j++) {
            array[j] = rand() % n;
        }
    }

    clock_t end_time = clock();

    // Calculate the time taken and operations performed
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    int operations_performed = iterations * n;

    // Return the result
    return (benchmark_result){time_taken, operations_performed};
}

// Function to print the result of the benchmark
void print_result(benchmark_result result) {
    printf("Time taken: %.6f seconds\n", result.time_taken);
    printf("Operations performed: %d\n", result.operations_performed);
}

// Main function
int main() {
    // Initialize the array
    int n = 1000000;
    int *array = malloc(n * sizeof(int));

    // Perform the benchmark
    benchmark_result result = benchmark(array, n, 1000);

    // Print the result
    print_result(result);

    // Free the memory
    free(array);

    return 0;
}