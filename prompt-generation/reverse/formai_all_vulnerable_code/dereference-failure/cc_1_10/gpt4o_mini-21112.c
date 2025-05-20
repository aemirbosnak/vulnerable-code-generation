//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

void fill_array(int *array, size_t size) {
    for(size_t i = 0; i < size; i++) {
        array[i] = rand() % 100; // Fill the array with random numbers
    }
}

void bubble_sort(int *array, size_t size) {
    for(size_t i = 0; i < size - 1; i++) {
        for(size_t j = 0; j < size - i - 1; j++) {
            if(array[j] > array[j + 1]) {
                // Swap array[j] and array[j + 1]
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void quick_sort(int *array, int low, int high) {
    if(low < high) {
        int pivot = array[high];
        int i = low - 1;
        for(int j = low; j < high; j++) {
            if(array[j] < pivot) {
                i++;
                // Swap array[i] and array[j]
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        // Swap array[i + 1] and array[high] (or pivot)
        int temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;

        int pi = i + 1;

        quick_sort(array, low, pi - 1);
        quick_sort(array, pi + 1, high);
    }
}

void measure_bubble_sort(int *array, size_t size) {
    clock_t start = clock();
    bubble_sort(array, size);
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Bubble Sort took %f seconds to sort %zu elements.\n", time_taken, size);
}

void measure_quick_sort(int *array, size_t size) {
    clock_t start = clock();
    quick_sort(array, 0, size - 1);
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Quick Sort took %f seconds to sort %zu elements.\n", time_taken, size);
}

int main() {
    srand((unsigned int)time(NULL));
    
    int *array1 = (int *)malloc(ARRAY_SIZE * sizeof(int));
    int *array2 = (int *)malloc(ARRAY_SIZE * sizeof(int));

    if (array1 == NULL || array2 == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return EXIT_FAILURE;
    }

    fill_array(array1, ARRAY_SIZE);
    for(size_t i = 0; i < ARRAY_SIZE; i++) {
        array2[i] = array1[i]; // Copy for quick sort
    }

    measure_bubble_sort(array1, ARRAY_SIZE);
    measure_quick_sort(array2, ARRAY_SIZE);

    free(array1);
    free(array2);

    return EXIT_SUCCESS;
}