//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100000

// Function declarations
void fillArray(int *arr, int size);
void bubbleSort(int *arr, int size);
void quickSort(int *arr, int low, int high);
int partition(int *arr, int low, int high);
double measureTime(void (*sortFunction)(int *, int), int *arr, int size);

int main() {
    int *arr1 = (int *)malloc(ARRAY_SIZE * sizeof(int));
    int *arr2 = (int *)malloc(ARRAY_SIZE * sizeof(int));

    if (arr1 == NULL || arr2 == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1; // Exit if memory allocation fails
    }

    srand(time(NULL)); // Seed random number generator 
    fillArray(arr1, ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr2[i] = arr1[i]; // copy to another array for fair comparison
    }

    // Measure and print time for bubble sort
    double bubbleSortTime = measureTime(bubbleSort, arr1, ARRAY_SIZE);
    printf("Bubble Sort Time: %f seconds\n", bubbleSortTime);

    // Measure and print time for quick sort
    double quickSortTime = measureTime(quickSort, arr2, ARRAY_SIZE);
    printf("Quick Sort Time: %f seconds\n", quickSortTime);

    free(arr1);
    free(arr2);

    return 0;
}

// Function to fill an array with random integers
void fillArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000; // Random numbers between 0 and 999
    }
}

// Function for bubble sort algorithm
void bubbleSort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function for quick sort algorithm
void quickSort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to partition the array for quick sort
int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1); // Index of smaller element
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++; // Increment index of smaller element
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    
    return (i + 1);
}

// Function to measure the execution time of a sorting algorithm
double measureTime(void (*sortFunction)(int *, int), int *arr, int size) {
    clock_t start, end;
    start = clock(); // Start the clock
    sortFunction(arr, size); // Call the sorting function
    end = clock(); // End the clock

    return ((double)(end - start)) / CLOCKS_PER_SEC; // Return elapsed time in seconds
}