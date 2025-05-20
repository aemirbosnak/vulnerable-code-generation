//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100000

void generate_random_numbers(int *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 1000; // Random number between 0 and 999
    }
}

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

void selection_sort(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[min_idx]) {
                min_idx = j;
            }
        }
        int temp = array[min_idx];
        array[min_idx] = array[i];
        array[i] = temp;
    }
}

void print_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void benchmark_sorting_algorithm(void (*sort_function)(int*, int), const char *sort_name, int *array, int size) {
    clock_t start, end;
    
    start = clock();
    sort_function(array, size);
    end = clock();

    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken by %s: %f seconds\n", sort_name, time_spent);
}

int main() {
    srand(time(NULL));
    
    int *array1 = (int*)malloc(ARRAY_SIZE * sizeof(int));
    int *array2 = (int*)malloc(ARRAY_SIZE * sizeof(int));
    
    if (!array1 || !array2) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    generate_random_numbers(array1, ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array2[i] = array1[i]; // Copy original array to another for second sort
    }

    printf("Benchmarking Sorting Algorithms...\n");

    benchmark_sorting_algorithm(bubble_sort, "Bubble Sort", array1, ARRAY_SIZE);
    benchmark_sorting_algorithm(selection_sort, "Selection Sort", array2, ARRAY_SIZE);

    // Uncomment to see the sorted arrays
    // printf("Sorted Array (Bubble Sort):\n");
    // print_array(array1, ARRAY_SIZE);
    // printf("Sorted Array (Selection Sort):\n");
    // print_array(array2, ARRAY_SIZE);

    free(array1);
    free(array2);

    return EXIT_SUCCESS;
}