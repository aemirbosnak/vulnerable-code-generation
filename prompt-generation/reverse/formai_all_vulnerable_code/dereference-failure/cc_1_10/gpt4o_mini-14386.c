//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define ARRAY_SIZE 1000000

void fill_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
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
    for (int i = 0; i < (size < 50 ? size : 50); i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void benchmark(const char *label, void (*sort_func)(int*, int), int *array, int size) {
    clock_t start_time = clock();
    sort_func(array, size);
    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("%s took %f seconds\n", label, time_taken);
}

int main() {
    srand(time(NULL));
    int *array1 = malloc(ARRAY_SIZE * sizeof(int));
    int *array2 = malloc(ARRAY_SIZE * sizeof(int));
    int *array3 = malloc(ARRAY_SIZE * sizeof(int));

    fill_array(array1, ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array2[i] = array1[i];
        array3[i] = array1[i];
    }

    printf("Benchmarking Sorting Algorithms on an Array of %d Elements:\n", ARRAY_SIZE);

    benchmark("Bubble Sort", bubble_sort, array1, ARRAY_SIZE);
    benchmark("Selection Sort", selection_sort, array2, ARRAY_SIZE);
    benchmark("Insertion Sort", insertion_sort, array3, ARRAY_SIZE);

    printf("First 10 sorted elements from Bubble Sort:\n");
    print_array(array1, ARRAY_SIZE);

    free(array1);
    free(array2);
    free(array3);
    
    return 0;
}