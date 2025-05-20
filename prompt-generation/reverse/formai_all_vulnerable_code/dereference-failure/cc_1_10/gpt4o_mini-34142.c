//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100000

void fill_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 1000; // Populate with random numbers
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

double benchmark_sort(void (*sort_func)(int *, int), int *array, int size) {
    clock_t start, end;
    start = clock();
    sort_func(array, size);
    end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC; // Return time in seconds
}

int main() {
    int *array1 = (int *)malloc(ARRAY_SIZE * sizeof(int));
    int *array2 = (int *)malloc(ARRAY_SIZE * sizeof(int));
    
    if (array1 == NULL || array2 == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    srand(time(0)); // Seed the random number generator
    
    fill_array(array1, ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array2[i] = array1[i]; // Copy the array for fair benchmarking
    }

    printf("Benchmarking Bubble Sort...\n");
    double bubble_time = benchmark_sort(bubble_sort, array1, ARRAY_SIZE);
    printf("Bubble Sort took %f seconds.\n", bubble_time);

    printf("Benchmarking Insertion Sort...\n");
    double insertion_time = benchmark_sort(insertion_sort, array2, ARRAY_SIZE);
    printf("Insertion Sort took %f seconds.\n", insertion_time);

    free(array1);
    free(array2);

    return 0;
}