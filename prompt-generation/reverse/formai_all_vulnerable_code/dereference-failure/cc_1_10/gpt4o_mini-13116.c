//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

// Function to fill an array with random integers
void fill_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000; // Random integers between 0 and 999
    }
}

// Function to perform bubble sort on an array
void bubble_sort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to perform quick sort on an array
void quick_sort(int *arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                // Swap arr[i] and arr[j]
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        // Swap arr[i + 1] and arr[high] (or pivot)
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int pi = i + 1;

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

// Function to verify if the array is sorted
int is_sorted(int *arr, int size) {
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[i - 1]) {
            return 0; // Not sorted
        }
    }
    return 1; // Sorted
}

// Main benchmarking function
int main() {
    srand(time(NULL)); // Seed the random number generator

    // Create arrays for sorting
    int *array_bubble = malloc(ARRAY_SIZE * sizeof(int));
    int *array_quick = malloc(ARRAY_SIZE * sizeof(int));

    // Fill arrays with random integers
    fill_array(array_bubble, ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array_quick[i] = array_bubble[i]; // Copy to quick sort array
    }

    // Bubble Sort
    clock_t start = clock();
    bubble_sort(array_bubble, ARRAY_SIZE);
    clock_t end = clock();
    double bubble_sort_time = (double)(end - start) / CLOCKS_PER_SEC;

    // Verify bubble sort
    if (is_sorted(array_bubble, ARRAY_SIZE)) {
        printf("Bubble Sort completed in %f seconds.\n", bubble_sort_time);
    } else {
        printf("Bubble Sort failed to sort the array.\n");
    }

    // Quick Sort
    start = clock();
    quick_sort(array_quick, 0, ARRAY_SIZE - 1);
    end = clock();
    double quick_sort_time = (double)(end - start) / CLOCKS_PER_SEC;

    // Verify quick sort
    if (is_sorted(array_quick, ARRAY_SIZE)) {
        printf("Quick Sort completed in %f seconds.\n", quick_sort_time);
    } else {
        printf("Quick Sort failed to sort the array.\n");
    }

    // Clean up
    free(array_bubble);
    free(array_quick);

    return 0;
}