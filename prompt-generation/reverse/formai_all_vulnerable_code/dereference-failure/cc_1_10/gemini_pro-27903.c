//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of elements in the array
#define ARRAY_SIZE 100000

// Define the number of times to run the benchmark
#define BENCHMARK_RUNS 100

// Define the function to be benchmarked
double sum_array(double *array, int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum;
}

// Define the main function
int main() {
    // Create an array of random numbers
    double *array = malloc(ARRAY_SIZE * sizeof(double));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = (double)rand() / RAND_MAX;
    }

    // Start the timer
    clock_t start = clock();

    // Run the benchmark multiple times
    for (int i = 0; i < BENCHMARK_RUNS; i++) {
        // Call the function to be benchmarked
        double sum = sum_array(array, ARRAY_SIZE);

        // Print the sum of the array
        printf("The sum of the array is: %f\n", sum);
    }

    // Stop the timer
    clock_t end = clock();

    // Calculate the time taken to run the benchmark
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // Print the time taken to run the benchmark
    printf("The time taken to run the benchmark is: %f seconds\n", time_taken);

    // Free the memory allocated for the array
    free(array);

    return 0;
}