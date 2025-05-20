//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

void fillArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 1000;  // Fill the array with random numbers [0-999]
    }
}

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

void quickSort(int *array, int low, int high) {
    if (low < high) {
        int pivot = array[high]; // pivot
        int i = (low - 1); // Index of smaller element
        for (int j = low; j < high; j++) {
            // If current element is smaller than the pivot
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
        int pi = i + 1;

        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

void measureExecutionTime(void (*sortFunc)(int *, int), int *array, int size, const char *sortName) {
    clock_t start, end;
    double cpu_time_used;
    
    start = clock();
    sortFunc(array, size);
    end = clock();
    
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Execution time of %s: %f seconds\n", sortName, cpu_time_used);
}

int main() {
    int *array1 = malloc(ARRAY_SIZE * sizeof(int));
    int *array2 = malloc(ARRAY_SIZE * sizeof(int));
    
    if (array1 == NULL || array2 == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    srand(time(NULL));  // Seed the random number generator
    fillArray(array1, ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array2[i] = array1[i]; // Copy for second sort
    }

    measureExecutionTime(bubbleSort, array1, ARRAY_SIZE, "Bubble Sort");

    measureExecutionTime(quickSort, array2, 0, ARRAY_SIZE - 1);
    
    free(array1);
    free(array2);

    return 0;
}