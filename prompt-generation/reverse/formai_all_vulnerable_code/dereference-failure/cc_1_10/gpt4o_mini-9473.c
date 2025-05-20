//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void perform_computation(int size) {
    double *array = (double *)malloc(size * sizeof(double));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    // Initialize the array with some values
    for (int i = 0; i < size; i++) {
        array[i] = sin(i) + cos(i); // A trivial computation
    }

    // Perform a simple benchmarked operation
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }

    free(array);
}

void benchmark(int iterations, int size) {
    clock_t start_time, end_time;
    double cpu_time_used;

    for (int i = 0; i < iterations; i++) {
        start_time = clock();

        perform_computation(size);

        end_time = clock();
        cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
        printf("Iteration %d: Computation time: %f seconds\n", i + 1, cpu_time_used);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <number_of_iterations> <array_size>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int iterations = atoi(argv[1]);
    int size = atoi(argv[2]);

    if (iterations <= 0 || size <= 0) {
        fprintf(stderr, "Both iterations and array size must be positive integers.\n");
        return EXIT_FAILURE;
    }

    printf("Starting benchmarking with %d iterations and array size of %d...\n", iterations, size);
    benchmark(iterations, size);
    printf("Benchmarking completed successfully!\n");

    return EXIT_SUCCESS;
}