//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

void fill_array(int* arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        arr[i] = rand() % 1000; // fill with random numbers 0-999
    }
}

void bubble_sort(int* arr, size_t size) {
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap the elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selection_sort(int* arr, size_t size) {
    for (size_t i = 0; i < size - 1; i++) {
        size_t min_idx = i;
        for (size_t j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void print_duration(const char* sort_name, clock_t start, clock_t end) {
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("%s took %f seconds\n", sort_name, time_taken);
}

int main() {
    int* arr1 = (int*)malloc(ARRAY_SIZE * sizeof(int));
    int* arr2 = (int*)malloc(ARRAY_SIZE * sizeof(int));

    if (!arr1 || !arr2) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    srand((unsigned int)time(NULL)); // Seed for randomness
    fill_array(arr1, ARRAY_SIZE);
    for (size_t i = 0; i < ARRAY_SIZE; i++) arr2[i] = arr1[i]; // Copy for second sort
    
    clock_t start, end;

    // Benchmark Bubble Sort
    start = clock();
    bubble_sort(arr1, ARRAY_SIZE);
    end = clock();
    print_duration("Bubble Sort", start, end);

    // Benchmark Selection Sort
    start = clock();
    selection_sort(arr2, ARRAY_SIZE);
    end = clock();
    print_duration("Selection Sort", start, end);

    free(arr1);
    free(arr2);
    return EXIT_SUCCESS;
}