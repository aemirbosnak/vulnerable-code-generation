//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

void initialize_array(int *array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
}

void bubble_sort(int *array, size_t size) {
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void selection_sort(int *array, size_t size) {
    for (size_t i = 0; i < size - 1; i++) {
        size_t min_idx = i;
        for (size_t j = i + 1; j < size; j++) {
            if (array[j] < array[min_idx]) {
                min_idx = j;
            }
        }
        int temp = array[min_idx];
        array[min_idx] = array[i];
        array[i] = temp;
    }
}

void insertion_sort(int *array, size_t size) {
    for (size_t i = 1; i < size; i++) {
        int key = array[i];
        size_t j = i - 1;
        while (j < size && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

void print_array(int *array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

double benchmark_sorting_function(void (*sort_func)(int*, size_t), int *array, size_t size) {
    clock_t start, end;
    start = clock();

    sort_func(array, size);

    end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

int main() {
    int *array_bubble = malloc(sizeof(int) * ARRAY_SIZE);
    int *array_selection = malloc(sizeof(int) * ARRAY_SIZE);
    int *array_insertion = malloc(sizeof(int) * ARRAY_SIZE);
    
    if (!array_bubble || !array_selection || !array_insertion) {
        printf("Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    srand(time(NULL));
    
    initialize_array(array_bubble, ARRAY_SIZE);
    for (size_t i = 0; i < ARRAY_SIZE; i++) {
        array_selection[i] = array_bubble[i];
        array_insertion[i] = array_bubble[i];
    }
    
    printf("Benchmarking Bubble Sort...\n");
    double bubble_time = benchmark_sorting_function(bubble_sort, array_bubble, ARRAY_SIZE);
    printf("Bubble Sort took %f seconds to sort %d elements.\n", bubble_time, ARRAY_SIZE);
    
    printf("Benchmarking Selection Sort...\n");
    double selection_time = benchmark_sorting_function(selection_sort, array_selection, ARRAY_SIZE);
    printf("Selection Sort took %f seconds to sort %d elements.\n", selection_time, ARRAY_SIZE);
    
    printf("Benchmarking Insertion Sort...\n");
    double insertion_time = benchmark_sorting_function(insertion_sort, array_insertion, ARRAY_SIZE);
    printf("Insertion Sort took %f seconds to sort %d elements.\n", insertion_time, ARRAY_SIZE);
    
    free(array_bubble);
    free(array_selection);
    free(array_insertion);
    
    return EXIT_SUCCESS;
}