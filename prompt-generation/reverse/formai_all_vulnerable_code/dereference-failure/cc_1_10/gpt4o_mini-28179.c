//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ARRAY_SIZE 1000000
#define RANDOM_MAX 100

// Function to fill an array with random numbers
void fill_array(int *array, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        array[i] = rand() % RANDOM_MAX;
    }
}

// Function to perform a bubble sort on the array
void bubble_sort(int *array, size_t size) {
    for (size_t i = 0; i < size - 1; ++i) {
        for (size_t j = 0; j < size - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Function to perform a quick sort on the array
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
void print_array(int *array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Helper function for timing a function
void time_function(void (*sort_func)(int*, int, int), int *array, int size) {
    clock_t start = clock();
    sort_func(array, 0, size - 1);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken for sorting: %f seconds\n", time_spent);
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    
    // Allocate memory for the arrays
    int *array_bubble = (int *)malloc(ARRAY_SIZE * sizeof(int));
    int *array_quick = (int *)malloc(ARRAY_SIZE * sizeof(int));
    
    if (array_bubble == NULL || array_quick == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    // Fill both arrays with random numbers
    fill_array(array_bubble, ARRAY_SIZE);
    memcpy(array_quick, array_bubble, ARRAY_SIZE * sizeof(int)); // Copy for the quick sort

    // Time and sort using bubble sort
    printf("Bubble Sort Performance:\n");
    time_function(bubble_sort, array_bubble, ARRAY_SIZE);
    // Uncomment to see sorted output
    // print_array(array_bubble, 10); // Print first 10 sorted numbers

    // Time and sort using quick sort
    printf("Quick Sort Performance:\n");
    time_function(quick_sort, array_quick, ARRAY_SIZE);
    // Uncomment to see sorted output
    // print_array(array_quick, 10); // Print first 10 sorted numbers

    // Free allocated memory
    free(array_bubble);
    free(array_quick);

    return EXIT_SUCCESS;
}