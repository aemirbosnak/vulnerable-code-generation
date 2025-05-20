//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// The surprise starts here! We are going to benchmark a set of operations.
#define ARRAY_SIZE 10000

// Function prototypes
void fill_array(int *arr, int size);
void bubble_sort(int *arr, int size);
void quick_sort(int *arr, int left, int right);
void swap(int *a, int *b);
void benchmark_sorting_algorithms();

// Surprise! A benchmarking structure to hold the timings
typedef struct {
    const char *sort_name;
    double time_taken;
} BenchmarkResult;

int main() {
    printf("Welcome to the Surprise Benchmarking Program!\n");
    benchmark_sorting_algorithms();
    return 0;
}

// Fill the array with random integers
void fill_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000; // Random integers between 0 and 9999
    }
}

// Swap function for quicksort
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble sort implementation
void bubble_sort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Quick sort implementation
void quick_sort(int *arr, int left, int right) {
    if (left < right) {
        int pivot = arr[right];
        int partition_index = left;

        for (int i = left; i < right; i++) {
            if (arr[i] <= pivot) {
                swap(&arr[i], &arr[partition_index]);
                partition_index++;
            }
        }
        swap(&arr[partition_index], &arr[right]);

        quick_sort(arr, left, partition_index - 1);
        quick_sort(arr, partition_index + 1, right);
    }
}

// Function to benchmark sorting algorithms
void benchmark_sorting_algorithms() {
    srand(time(NULL)); // Seed the random number generator

    int *random_array1 = (int *)malloc(ARRAY_SIZE * sizeof(int));
    int *random_array2 = (int *)malloc(ARRAY_SIZE * sizeof(int));
    
    // Create arrays filled with random numbers
    fill_array(random_array1, ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        random_array2[i] = random_array1[i]; // Copy for second sorting algorithm
    }

    // Benchmarking Bubble Sort
    clock_t start_time = clock();
    bubble_sort(random_array1, ARRAY_SIZE);
    clock_t end_time = clock();
    double bubble_sort_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Bubble Sort took: %f seconds\n", bubble_sort_time);

    // Benchmarking Quick Sort
    start_time = clock();
    quick_sort(random_array2, 0, ARRAY_SIZE - 1);
    end_time = clock();
    double quick_sort_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Quick Sort took: %f seconds\n", quick_sort_time);

    // Freeing up memory
    free(random_array1);
    free(random_array2);

    // Final surprise!
    printf("Benchmarking complete! It's amazing how quick sorts can be!\n");
}