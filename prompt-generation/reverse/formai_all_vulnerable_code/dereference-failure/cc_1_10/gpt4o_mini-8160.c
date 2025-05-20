//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ARRAY_SIZE 100000

void fill_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 1000; // Fill with random numbers from 0 to 999
    }
}

void bubble_sort(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                // Swap
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void selection_sort(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[min_idx]) {
                min_idx = j;
            }
        }
        // Swap
        int temp = array[i];
        array[i] = array[min_idx];
        array[min_idx] = temp;
    }
}

void insertion_sort(int *array, int size) {
    for (int i = 1; i < size; i++) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

void print_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    // Array for sorting algorithms
    int *array_bubble = malloc(ARRAY_SIZE * sizeof(int));
    int *array_selection = malloc(ARRAY_SIZE * sizeof(int));
    int *array_insertion = malloc(ARRAY_SIZE * sizeof(int));

    if (array_bubble == NULL || array_selection == NULL || array_insertion == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return EXIT_FAILURE;
    }

    fill_array(array_bubble, ARRAY_SIZE);
    memcpy(array_selection, array_bubble, ARRAY_SIZE * sizeof(int));
    memcpy(array_insertion, array_bubble, ARRAY_SIZE * sizeof(int));

    // Benchmark Bubble Sort
    clock_t start_time = clock();
    bubble_sort(array_bubble, ARRAY_SIZE);
    clock_t end_time = clock();
    double bubble_sort_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Bubble Sort Time: %f seconds\n", bubble_sort_time);

    // Benchmark Selection Sort
    start_time = clock();
    selection_sort(array_selection, ARRAY_SIZE);
    end_time = clock();
    double selection_sort_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Selection Sort Time: %f seconds\n", selection_sort_time);

    // Benchmark Insertion Sort
    start_time = clock();
    insertion_sort(array_insertion, ARRAY_SIZE);
    end_time = clock();
    double insertion_sort_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Insertion Sort Time: %f seconds\n", insertion_sort_time);

    // Free allocated memory
    free(array_bubble);
    free(array_selection);
    free(array_insertion);

    return EXIT_SUCCESS;
}