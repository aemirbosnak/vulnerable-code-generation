//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of iterations for the benchmark
#define ITERATIONS 1000000

// Define the size of the array for the benchmark
#define ARRAY_SIZE 10000

// Declare the function prototypes
double benchmark_addition(int *array, int size);
double benchmark_multiplication(int *array, int size);
double benchmark_division(int *array, int size);

// Main function
int main() {
    // Create an array of integers
    int *array = (int *)malloc(ARRAY_SIZE * sizeof(int));

    // Initialize the array with random values
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand();
    }

    // Benchmark the addition operation
    double addition_time = benchmark_addition(array, ARRAY_SIZE);

    // Benchmark the multiplication operation
    double multiplication_time = benchmark_multiplication(array, ARRAY_SIZE);

    // Benchmark the division operation
    double division_time = benchmark_division(array, ARRAY_SIZE);

    // Print the benchmark results
    printf("Addition time: %f seconds\n", addition_time);
    printf("Multiplication time: %f seconds\n", multiplication_time);
    printf("Division time: %f seconds\n", division_time);

    // Free the allocated memory
    free(array);

    return 0;
}

// Benchmark the addition operation
double benchmark_addition(int *array, int size) {
    // Start the timer
    clock_t start = clock();

    // Perform the addition operation
    for (int i = 0; i < ITERATIONS; i++) {
        for (int j = 0; j < size; j++) {
            array[j] += 1;
        }
    }

    // Stop the timer
    clock_t end = clock();

    // Calculate the elapsed time
    double elapsed_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Return the elapsed time
    return elapsed_time;
}

// Benchmark the multiplication operation
double benchmark_multiplication(int *array, int size) {
    // Start the timer
    clock_t start = clock();

    // Perform the multiplication operation
    for (int i = 0; i < ITERATIONS; i++) {
        for (int j = 0; j < size; j++) {
            array[j] *= 2;
        }
    }

    // Stop the timer
    clock_t end = clock();

    // Calculate the elapsed time
    double elapsed_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Return the elapsed time
    return elapsed_time;
}

// Benchmark the division operation
double benchmark_division(int *array, int size) {
    // Start the timer
    clock_t start = clock();

    // Perform the division operation
    for (int i = 0; i < ITERATIONS; i++) {
        for (int j = 0; j < size; j++) {
            array[j] /= 2;
        }
    }

    // Stop the timer
    clock_t end = clock();

    // Calculate the elapsed time
    double elapsed_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Return the elapsed time
    return elapsed_time;
}