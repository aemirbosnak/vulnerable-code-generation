//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate an array of random integers
int* generate_random_array(int size) {
    int* array = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 1000;
    }
    return array;
}

// Function to find the maximum element in an array
int find_max(int* array, int size) {
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

// Function to find the minimum element in an array
int find_min(int* array, int size) {
    int min = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

// Function to calculate the average of an array
float calculate_average(int* array, int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum / size;
}

// Function to benchmark the performance of an array operation
void benchmark_array_operation(void (*operation)(int*, int), int* array, int size) {
    clock_t start, end;
    double time_taken;

    // Start the clock
    start = clock();

    // Call the operation function
    operation(array, size);

    // Stop the clock
    end = clock();

    // Calculate the time taken
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // Print the time taken
    printf("Time taken: %f seconds\n", time_taken);
}

int main() {
    // Generate a random array
    int* array = generate_random_array(100000);

    // Benchmark the performance of the find_max function
    benchmark_array_operation(find_max, array, 100000);

    // Benchmark the performance of the find_min function
    benchmark_array_operation(find_min, array, 100000);

    // Benchmark the performance of the calculate_average function
    benchmark_array_operation(calculate_average, array, 100000);

    // Free the memory allocated for the array
    free(array);

    return 0;
}