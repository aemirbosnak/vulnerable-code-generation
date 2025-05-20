//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define ARRAY_SIZE 100000

// Function to fill an array with random numbers
void fillArray(int *array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        array[i] = rand() % 1000; // Random numbers between 0 and 999
    }
}

// Function to perform bubble sort on an array
void bubbleSort(int *array, size_t size) {
    int temp;
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Function to perform quick sort on an array
void quickSort(int *array, int low, int high) {
    if (low < high) {
        int pivot = array[high];
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++) {
            if (array[j] < pivot) {
                i++;
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        int temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;
        int partitionIndex = i + 1;

        quickSort(array, low, partitionIndex - 1);
        quickSort(array, partitionIndex + 1, high);
    }
}

// Function to measure execution time of sorting algorithms
void benchmarkSortingAlgorithms() {
    int *array1 = malloc(ARRAY_SIZE * sizeof(int));
    int *array2 = malloc(ARRAY_SIZE * sizeof(int));

    // Fill and copy arrays
    fillArray(array1, ARRAY_SIZE);
    for (size_t i = 0; i < ARRAY_SIZE; i++) {
        array2[i] = array1[i];
    }

    // Benchmark bubble sort
    clock_t start = clock();
    bubbleSort(array1, ARRAY_SIZE);
    clock_t end = clock();
    double bubbleSortTime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Bubble Sort took: %.4f seconds\n", bubbleSortTime);

    // Benchmark quick sort
    start = clock();
    quickSort(array2, 0, ARRAY_SIZE - 1);
    end = clock();
    double quickSortTime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Quick Sort took: %.4f seconds\n", quickSortTime);

    // Clean up
    free(array1);
    free(array2);
}

// Main function
int main() {
    srand(time(NULL)); // Seed for random number generation
    printf("Starting Benchmarking of Sorting Algorithms...\n");
    benchmarkSortingAlgorithms();
    printf("Benchmarking complete.\n");
    return 0;
}