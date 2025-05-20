//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the function to be benchmarked
double sum_array(double *array, int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum;
}

// Define the main function
int main(int argc, char **argv) {
    // Check the command line arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <array size> <number of iterations>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the array size and the number of iterations from the command line arguments
    int size = atoi(argv[1]);
    int iterations = atoi(argv[2]);

    // Allocate memory for the array
    double *array = malloc(size * sizeof(double));
    if (array == NULL) {
        fprintf(stderr, "Error: could not allocate memory for the array\n");
        return EXIT_FAILURE;
    }

    // Initialize the array with random values
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        array[i] = (double)rand() / RAND_MAX;
    }

    // Run the benchmark
    clock_t start = clock();
    for (int i = 0; i < iterations; i++) {
        sum_array(array, size);
    }
    clock_t end = clock();

    // Calculate the elapsed time
    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

    // Print the results
    printf("Array size: %d\n", size);
    printf("Number of iterations: %d\n", iterations);
    printf("Elapsed time: %f seconds\n", elapsed_time);

    // Free the memory allocated for the array
    free(array);

    return EXIT_SUCCESS;
}