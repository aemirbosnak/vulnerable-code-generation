//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of elements in the array
#define ARRAY_SIZE 1000000

// Define the number of iterations for the benchmark
#define ITERATIONS 100

// Define the function to be benchmarked
double sum_array(double *array, int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum;
}

// Define the main function
int main() {
    // Allocate memory for the array
    double *array = malloc(ARRAY_SIZE * sizeof(double));

    // Initialize the array with random values
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() / (double)RAND_MAX;
    }

    // Start the timer
    clock_t start = clock();

    // Run the benchmark
    for (int i = 0; i < ITERATIONS; i++) {
        sum_array(array, ARRAY_SIZE);
    }

    // Stop the timer
    clock_t end = clock();

    // Calculate the elapsed time
    double elapsed = (double)(end - start) / CLOCKS_PER_SEC;

    // Print the elapsed time
    printf("Elapsed time: %f seconds\n", elapsed);

    // Free the memory allocated for the array
    free(array);

    return 0;
}