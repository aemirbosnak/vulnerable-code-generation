//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Secure random number generator
int secure_rand(int min, int max) {
    // Get a random seed from the system's entropy pool
    int seed;
    FILE *f = fopen("/dev/urandom", "rb");
    fread(&seed, sizeof(int), 1, f);
    fclose(f);

    // Initialize the random number generator
    srand(seed);

    // Generate a random number between min and max
    return rand() % (max - min + 1) + min;
}

// Benchmarking function
void benchmark(void (*func)(int *), int *array, int size) {
    // Initialize the timer
    clock_t start = clock();

    // Call the function
    func(array);

    // Stop the timer
    clock_t end = clock();

    // Calculate the elapsed time
    double elapsed = (double)(end - start) / CLOCKS_PER_SEC;

    // Print the results
    printf("Elapsed time: %f seconds\n", elapsed);
}

// Function to be benchmarked
void sort_array(int *array, int size) {
    // Simple bubble sort algorithm
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main() {
    // Initialize the array
    int size = 10000;
    int *array = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        array[i] = secure_rand(0, 1000);
    }

    // Benchmark the function
    benchmark(sort_array, array, size);

    // Free the array
    free(array);

    return 0;
}