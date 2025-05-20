//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

void fill_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100; // Fill with random numbers from 0 to 99
    }
}

void add_arrays(int *a, int *b, int *result, int size) {
    for (int i = 0; i < size; i++) {
        result[i] = a[i] + b[i];
    }
}

void multiply_arrays(int *a, int *b, int *result, int size) {
    for (int i = 0; i < size; i++) {
        result[i] = a[i] * b[i];
    }
}

void benchmark(void (*func)(int*, int*, int*, int), int *a, int *b, int *result, int size, const char *operation) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    
    func(a, b, result, size);

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken for %s with size %d: %f seconds\n", operation, size, cpu_time_used);
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    int *arrayA = (int *)malloc(ARRAY_SIZE * sizeof(int));
    int *arrayB = (int *)malloc(ARRAY_SIZE * sizeof(int));
    int *resultAdd = (int *)malloc(ARRAY_SIZE * sizeof(int));
    int *resultMultiply = (int *)malloc(ARRAY_SIZE * sizeof(int));

    if (!arrayA || !arrayB || !resultAdd || !resultMultiply) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1; // Exit if memory allocation fails
    }

    printf("🎉 Welcome to the C Benchmarking Program! 🎉\n");
    printf("We're going to measure some joyful computations today!\n\n");

    fill_array(arrayA, ARRAY_SIZE);
    fill_array(arrayB, ARRAY_SIZE);

    benchmark(add_arrays, arrayA, arrayB, resultAdd, ARRAY_SIZE, "adding arrays");
    benchmark(multiply_arrays, arrayA, arrayB, resultMultiply, ARRAY_SIZE, "multiplying arrays");

    printf("\nAll tasks completed successfully! 🎊\n");
    printf("Happy coding and benchmarking! 💻✨\n");

    free(arrayA);
    free(arrayB);
    free(resultAdd);
    free(resultMultiply);
    
    return 0;
}