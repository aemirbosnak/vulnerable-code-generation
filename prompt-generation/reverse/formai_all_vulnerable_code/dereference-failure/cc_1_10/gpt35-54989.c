//FormAI DATASET v1.0 Category: Benchmarking ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[minIndex] > arr[j])
                minIndex = j;
        }
        if (minIndex != i)
            swap(&arr[i], &arr[minIndex]);
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    printf("Welcome to Benchmarking program!\n");
    printf("Preparing array of %u random integers...\n", ARRAY_SIZE);

    // Generate array of random integers
    int* arr = (int*) malloc(ARRAY_SIZE * sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++)
        arr[i] = rand();

    printf("Array preparation completed!\n");
    printf("Starting benchmark for sorting algorithms...\n");

    // Bubble Sort Benchmarking
    clock_t start = clock();
    bubbleSort(arr, ARRAY_SIZE);
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Bubble Sort took %f seconds to complete.\n", seconds);

    // Selection Sort Benchmarking
    start = clock();
    selectionSort(arr, ARRAY_SIZE);
    end = clock();
    seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Selection Sort took %f seconds to complete.\n", seconds);

    // Insertion Sort Benchmarking
    start = clock();
    insertionSort(arr, ARRAY_SIZE);
    end = clock();
    seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Insertion Sort took %f seconds to complete.\n", seconds);

    printf("Benchmark completed!\n");

    return 0;
}