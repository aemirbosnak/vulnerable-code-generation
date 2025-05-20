//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Constants
#define ARRAY_SIZE 1000000
#define NUM_ITERATIONS 100

// Function to perform a computationally expensive operation
double expensive_computation(double a) {
    volatile double result = 0.0; // Use 'volatile' for optimization demonstration
    for (long i = 0; i < 1000000; i++) {
        result += sqrt(a * i) / (i + 1);
    }
    return result;
}

// Function to populate an array with random floating-point numbers
void populate_array(double* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = (double) rand() / RAND_MAX;
    }
}

// Function to process an array and perform computations
void process_array(double* arr, int size, double* results) {
    for (int i = 0; i < size; i++) {
        results[i] = expensive_computation(arr[i]);
    }
}

// Function to benchmark the performance
void benchmark() {
    clock_t start, end;
    double cpu_time_used;

    double *arr = (double *)malloc(ARRAY_SIZE * sizeof(double));
    double *results = (double *)malloc(ARRAY_SIZE * sizeof(double));
    
    if (arr == NULL || results == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    
    populate_array(arr, ARRAY_SIZE);
    
    start = clock();
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        process_array(arr, ARRAY_SIZE, results);
    }
    end = clock();
    
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Processed %d elements in %f seconds\n", ARRAY_SIZE * NUM_ITERATIONS, cpu_time_used);

    free(arr);
    free(results);
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    printf("Starting performance-critical computation...\n");
    
    benchmark();
    
    printf("Finished computations.\n");
    return 0;
}