//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100000
#define NUM_TRIALS 10

// Function to populate an array with random integers
void fill_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100; // Random numbers between 0-99
    }
}

// Function to perform the bubble sort algorithm
void bubble_sort(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                // Swap elements
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Function to perform the quick sort algorithm
void quick_sort(int *array, int low, int high) {
    if (low < high) {
        int pivot = array[high];
        int i = (low - 1);

        for (int j = low; j < high; j++) {
            if (array[j] < pivot) {
                i++;
                // Swap array[i] and array[j]
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        // Swap array[i+1] with array[high] (or pivot)
        int temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;

        int pi = i + 1;
        quick_sort(array, low, pi - 1);
        quick_sort(array, pi + 1, high);
    }
}

// Function to benchmark the sorting algorithms
void benchmark_sorting(void (*sort_function)(int*, int), const char *name) {
    int *array = malloc(ARRAY_SIZE * sizeof(int));
    double total_time = 0.0;

    for (int trial = 0; trial < NUM_TRIALS; trial++) {
        fill_array(array, ARRAY_SIZE); // Populate the array with random data

        clock_t start = clock(); // Start the timer
        sort_function(array, ARRAY_SIZE); // Run the sorting algorithm
        clock_t end = clock(); // End the timer

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Trial %d for %s: took %f seconds\n", trial + 1, name, time_taken);
        total_time += time_taken;
    }

    printf("Average time taken for %s: %f seconds\n", name, total_time / NUM_TRIALS);
    free(array); // Free allocated memory
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    printf("Welcome to the Sorting Algorithm Benchmarking Program!\n");
    printf("In this program, we will measure the performance of Bubble Sort and Quick Sort.\n");
    printf("Let's get started!\n");

    // Benchmark Bubble Sort
    benchmark_sorting(bubble_sort, "Bubble Sort");

    // Benchmark Quick Sort
    benchmark_sorting(quick_sort, "Quick Sort");

    printf("Benchmarking completed! Thank you for participating!\n");

    return 0;
}