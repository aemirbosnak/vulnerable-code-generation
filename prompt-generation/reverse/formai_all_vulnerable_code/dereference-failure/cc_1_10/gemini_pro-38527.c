//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <time.h>

// Define the number of elements in the array
#define ARRAY_SIZE 1000000

// Define the number of iterations
#define ITERATIONS 1000

// Define the function to be timed
uint64_t sum_array(uint32_t *arr, uint32_t size) {
    uint64_t sum = 0;
    for (uint32_t i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    // Allocate memory for the array
    uint32_t *arr = malloc(ARRAY_SIZE * sizeof(uint32_t));

    // Initialize the array with random values
    for (uint32_t i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand();
    }

    // Start the timer
    clock_t start = clock();

    // Perform the iterations
    for (uint32_t i = 0; i < ITERATIONS; i++) {
        sum_array(arr, ARRAY_SIZE);
    }

    // Stop the timer
    clock_t end = clock();

    // Calculate the time taken
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // Print the time taken
    printf("Time taken: %f seconds\n", time_taken);

    // Free the memory allocated for the array
    free(arr);

    return 0;
}