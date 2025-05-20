//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void initializeArray(int *array, int size);
void printArray(int *array, int size);
void bubbleSort(int *array, int size);
void quickSort(int *array, int left, int right);
double benchmarkSorting(void (*sortFunc)(int *, int), int *array, int size);
void swap(int *a, int *b);
int partition(int *array, int left, int right);

int main() {
    const int ARRAY_SIZE = 10000; // Size of the array
    int *array1 = malloc(ARRAY_SIZE * sizeof(int));
    int *array2 = malloc(ARRAY_SIZE * sizeof(int));

    if (array1 == NULL || array2 == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return EXIT_FAILURE;
    }

    // Initialize arrays with random values
    initializeArray(array1, ARRAY_SIZE);
    initializeArray(array2, ARRAY_SIZE);

    // Benchmark bubble sort
    double bubbleTime = benchmarkSorting(bubbleSort, array1, ARRAY_SIZE);
    printf("Bubble Sort: Time taken = %.5f seconds\n", bubbleTime);

    // Initialize second array again for quicksort
    initializeArray(array2, ARRAY_SIZE);

    // Benchmark quick sort
    double quickTime = benchmarkSorting(quickSort, array2, ARRAY_SIZE);
    printf("Quick Sort: Time taken = %.5f seconds\n", quickTime);

    // Cleanup
    free(array1);
    free(array2);

    return EXIT_SUCCESS;
}

// Function to initialize the array with random integers
void initializeArray(int *array, int size) {
    srand(time(NULL)); // Seed for random number generator
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100000; // Random values between 0 and 99999
    }
}

// Function to print an array (for debugging, if needed)
void printArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Function to implement bubble sort
void bubbleSort(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

// Function to implement quick sort
void quickSort(int *array, int left, int right) {
    if (left < right) {
        int pivotIndex = partition(array, left, right);
        quickSort(array, left, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, right);
    }
}

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for quicksort
int partition(int *array, int left, int right) {
    int pivot = array[right]; // use the rightmost element as the pivot
    int i = (left - 1);
    for (int j = left; j < right; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[right]);
    return (i + 1);
}

// Function to benchmark sorting functions
double benchmarkSorting(void (*sortFunc)(int *, int), int *array, int size) {
    clock_t start, end;
    start = clock(); // Start time
    sortFunc(array, size);
    end = clock(); // End time
    return ((double)(end - start)) / CLOCKS_PER_SEC; // Return time in seconds
}