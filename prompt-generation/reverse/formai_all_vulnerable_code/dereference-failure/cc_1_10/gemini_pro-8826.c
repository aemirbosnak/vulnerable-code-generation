//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the array to be benchmarked
#define ARRAY_SIZE 1000000

// Define the number of iterations for the benchmark
#define ITERATIONS 1000

// Create an array of random numbers
int *create_random_array(int size) {
    int *array = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 1000;
    }
    return array;
}

// Find the minimum value in an array
int find_min(int *array, int size) {
    int min = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

// Find the maximum value in an array
int find_max(int *array, int size) {
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

// Calculate the average value in an array
double find_average(int *array, int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum / size;
}

// Benchmark the find_min function
double benchmark_find_min(int *array, int size, int iterations) {
    clock_t start = clock();
    for (int i = 0; i < iterations; i++) {
        find_min(array, size);
    }
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}

// Benchmark the find_max function
double benchmark_find_max(int *array, int size, int iterations) {
    clock_t start = clock();
    for (int i = 0; i < iterations; i++) {
        find_max(array, size);
    }
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}

// Benchmark the find_average function
double benchmark_find_average(int *array, int size, int iterations) {
    clock_t start = clock();
    for (int i = 0; i < iterations; i++) {
        find_average(array, size);
    }
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}

// Print the results of the benchmark
void print_results(double find_min_time, double find_max_time, double find_average_time) {
    printf("Find min time: %f seconds\n", find_min_time);
    printf("Find max time: %f seconds\n", find_max_time);
    printf("Find average time: %f seconds\n", find_average_time);
}

int main() {
    // Create an array of random numbers
    int *array = create_random_array(ARRAY_SIZE);

    // Benchmark the find_min function
    double find_min_time = benchmark_find_min(array, ARRAY_SIZE, ITERATIONS);

    // Benchmark the find_max function
    double find_max_time = benchmark_find_max(array, ARRAY_SIZE, ITERATIONS);

    // Benchmark the find_average function
    double find_average_time = benchmark_find_average(array, ARRAY_SIZE, ITERATIONS);

    // Print the results of the benchmark
    print_results(find_min_time, find_max_time, find_average_time);

    // Free the memory allocated for the array
    free(array);

    return 0;
}