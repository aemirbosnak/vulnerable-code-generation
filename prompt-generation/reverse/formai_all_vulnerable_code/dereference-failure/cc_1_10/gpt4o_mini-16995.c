//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random array
void generateRandomArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 10000; // Random numbers from 0 to 9999
    }
}

// Function to print the array (for debugging purposes)
void printArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Quick Sort function
void quickSort(int *array, int low, int high) {
    if (low < high) {
        int pivot = array[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (array[j] < pivot) {
                i++;
                // Swap array[i] and array[j]
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        // Swap array[i + 1] and array[high] (or pivot)
        int temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;

        int partitionIndex = i + 1;
        quickSort(array, low, partitionIndex - 1);
        quickSort(array, partitionIndex + 1, high);
    }
}

// Bubble Sort function
void bubbleSort(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                // Swap array[j] and array[j + 1]
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Function to time a sorting algorithm
double timeSortingFunction(void (*sortFunction)(int *, int), int *array, int size) {
    clock_t start = clock();
    sortFunction(array, size);
    clock_t end = clock();
    return ((double)(end - start) / CLOCKS_PER_SEC) * 1000; // milliseconds
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    
    int size = 10000; // Size of the array
    int *array1 = malloc(size * sizeof(int));
    int *array2 = malloc(size * sizeof(int));

    if (array1 == NULL || array2 == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    generateRandomArray(array1, size);
    for (int i = 0; i < size; i++) {
        array2[i] = array1[i]; // Copy to a second array for fair comparison
    }

    printf("Benchmarking Quick Sort...\n");
    double quickSortTime = timeSortingFunction(quickSort, array1, size);
    printf("Quick Sort took: %.3f milliseconds\n", quickSortTime);

    printf("Benchmarking Bubble Sort...\n");
    double bubbleSortTime = timeSortingFunction(bubbleSort, array2, size);
    printf("Bubble Sort took: %.3f milliseconds\n", bubbleSortTime);

    // Free allocated memory
    free(array1);
    free(array2);

    return 0;
}