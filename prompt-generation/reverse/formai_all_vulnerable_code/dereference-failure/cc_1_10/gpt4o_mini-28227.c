//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: grateful
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 100000

// Function to fill the array with random numbers
void fill_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
}

// Function to perform Bubble Sort
void bubble_sort(int *array, int size) {
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

// Function to perform Quick Sort
int partition(int *array, int low, int high) {
    int pivot = array[high]; 
    int i = (low - 1); 
  
    for (int j = low; j <= high - 1; j++) {
        if (array[j] < pivot) {
            i++; 
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    return (i + 1);
}

void quick_sort(int *array, int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quick_sort(array, low, pi - 1);
        quick_sort(array, pi + 1, high);
    }
}

// Function to print an array
void print_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Main function for benchmarking
int main() {
    srand(time(NULL)); // Seed for random number generation

    // Allocating memory for two arrays
    int *bubble_array = (int *)malloc(SIZE * sizeof(int));
    int *quick_array = (int *)malloc(SIZE * sizeof(int));

    if (bubble_array == NULL || quick_array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Fill the arrays with random numbers
    fill_array(bubble_array, SIZE);
    for (int i = 0; i < SIZE; i++) {
        quick_array[i] = bubble_array[i]; // Copy data for quicksort
    }

    // Bubble Sort Benchmark
    clock_t start_time_bubble = clock();
    bubble_sort(bubble_array, SIZE);
    clock_t end_time_bubble = clock();
    double time_taken_bubble = (double)(end_time_bubble - start_time_bubble) / CLOCKS_PER_SEC;

    // Quick Sort Benchmark
    clock_t start_time_quick = clock();
    quick_sort(quick_array, 0, SIZE - 1);
    clock_t end_time_quick = clock();
    double time_taken_quick = (double)(end_time_quick - start_time_quick) / CLOCKS_PER_SEC;

    // Display results
    printf("Time taken by Bubble Sort for %d elements: %f seconds\n", SIZE, time_taken_bubble);
    printf("Time taken by Quick Sort for %d elements: %f seconds\n", SIZE, time_taken_quick);
    
    // Print first 10 sorted elements (as they may be large)
    printf("First 10 elements sorted by Bubble Sort: ");
    print_array(bubble_array, 10);
    
    printf("First 10 elements sorted by Quick Sort: ");
    print_array(quick_array, 10);
    
    // Free allocated memory
    free(bubble_array);
    free(quick_array);

    return 0;
}