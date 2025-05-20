//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000
#define REPEAT 100

void fill_array(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Fill array with values from 0 to 99
    }
}

void bubble_sort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selection_sort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
}

void insertion_sort(int* arr, int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void benchmark_sort(void (*sort_func)(int*, int), int* arr, int size) {
    clock_t start, end;
    start = clock();
    sort_func(arr, size);
    end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %.6f seconds\n", time_spent);
}

int main() {
    srand(time(0));
    int* arr_bubble = (int*)malloc(SIZE * sizeof(int));
    int* arr_selection = (int*)malloc(SIZE * sizeof(int));
    int* arr_insertion = (int*)malloc(SIZE * sizeof(int));
    
    printf("Benchmarking sorting algorithms...\n");
    
    // Bubble Sort Benchmark
    printf("Bubble Sort Benchmark:\n");
    for (int i = 0; i < REPEAT; i++) {
        fill_array(arr_bubble, SIZE);
        benchmark_sort(bubble_sort, arr_bubble, SIZE);
    }

    // Selection Sort Benchmark
    printf("Selection Sort Benchmark:\n");
    for (int i = 0; i < REPEAT; i++) {
        fill_array(arr_selection, SIZE);
        benchmark_sort(selection_sort, arr_selection, SIZE);
    }

    // Insertion Sort Benchmark
    printf("Insertion Sort Benchmark:\n");
    for (int i = 0; i < REPEAT; i++) {
        fill_array(arr_insertion, SIZE);
        benchmark_sort(insertion_sort, arr_insertion, SIZE);
    }
    
    // Free the allocated memory
    free(arr_bubble);
    free(arr_selection);
    free(arr_insertion);

    return 0;
}