//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000

void generate_random_array(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Random integers between 0 and 99
    }
}

void bubble_sort(int *arr, int size) {
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

void selection_sort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

void insertion_sort(int *arr, int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void print_array(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void benchmark_sorting_algorithms() {
    int *arr1 = (int *)malloc(ARRAY_SIZE * sizeof(int));
    int *arr2 = (int *)malloc(ARRAY_SIZE * sizeof(int));
    int *arr3 = (int *)malloc(ARRAY_SIZE * sizeof(int));
    
    generate_random_array(arr1, ARRAY_SIZE);
    for(int i = 0; i < ARRAY_SIZE; i++) {
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }
    
    clock_t start, end;
    double cpu_time_used;

    // Benchmark Bubble Sort
    start = clock();
    bubble_sort(arr1, ARRAY_SIZE);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort took %f seconds\n", cpu_time_used);

    // Benchmark Selection Sort
    start = clock();
    selection_sort(arr2, ARRAY_SIZE);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Selection Sort took %f seconds\n", cpu_time_used);

    // Benchmark Insertion Sort
    start = clock();
    insertion_sort(arr3, ARRAY_SIZE);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Insertion Sort took %f seconds\n", cpu_time_used);

    free(arr1);
    free(arr2);
    free(arr3);
}

int main() {
    srand(time(0)); // Seed for random number generation
    benchmark_sorting_algorithms();
    return 0;
}