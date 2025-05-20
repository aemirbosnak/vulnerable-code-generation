//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
#include <sys/time.h>

// Define the size of the array
#define ARRAY_SIZE 1000000

// Define the number of iterations
#define ITERATIONS 10000

// Define the function to be timed
int64_t sum_array(int32_t *array, int32_t size) {
    int64_t sum = 0;
    for (int32_t i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum;
}

// Main function
int main() {
    // Allocate memory for the array
    int32_t *array = (int32_t *)malloc(ARRAY_SIZE * sizeof(int32_t));

    // Initialize the array
    for (int32_t i = 0; i < ARRAY_SIZE; i++) {
        array[i] = i;
    }

    // Start the timer
    struct timeval start, end;
    gettimeofday(&start, NULL);

    // Perform the iterations
    for (int32_t i = 0; i < ITERATIONS; i++) {
        sum_array(array, ARRAY_SIZE);
    }

    // Stop the timer
    gettimeofday(&end, NULL);

    // Calculate the elapsed time
    int64_t elapsed_time = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);

    // Print the results
    printf("Elapsed time: %" PRId64 " microseconds\n", elapsed_time);

    // Free the allocated memory
    free(array);

    return 0;
}