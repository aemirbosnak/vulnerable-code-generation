//FormAI DATASET v1.0 Category: Benchmarking ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ARRAY_SIZE 10000
#define MAX_RANDOM_NUM 1000

// Random numbers generator function
int* generate_random_numbers(int size) {
    int* arr = (int*) malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_RANDOM_NUM;
    }

    return arr;
}

// Bubble Sort algorithm
void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Benchmark test function
void benchmark(int size) {
    clock_t start_time, end_time;
    double total_time;

    // Generate random numbers for testing
    int* arr = generate_random_numbers(size);

    // Start time measurement
    start_time = clock();

    // Bubble sort the array
    bubble_sort(arr, size);

    // End time measurement
    end_time = clock();

    // Calculate total time taken for sorting
    total_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    // Print benchmarking results
    printf("Sorting time for array of size %d: %f seconds\n", size, total_time);

    // Free the dynamically allocated memory
    free(arr);
}

int main() {
    // Set random seed
    srand(time(NULL));

    // Benchmark tests for various array sizes
    benchmark(1000);
    benchmark(5000);
    benchmark(10000);

    return 0;
}