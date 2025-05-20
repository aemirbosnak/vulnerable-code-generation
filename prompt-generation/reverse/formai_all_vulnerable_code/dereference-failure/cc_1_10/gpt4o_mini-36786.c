//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000

typedef struct {
    int size;
    int *elements;
} Array;

void initializeArray(Array *array, int size) {
    array->size = size;
    array->elements = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        array->elements[i] = rand() % 1000;  // Fill with random values
    }
}

void freeArray(Array *array) {
    free(array->elements);
}

void bubbleSort(Array *array) {
    for (int i = 0; i < array->size - 1; i++) {
        for (int j = 0; j < array->size - i - 1; j++) {
            if (array->elements[j] > array->elements[j + 1]) {
                // Swap the elements
                int temp = array->elements[j];
                array->elements[j] = array->elements[j + 1];
                array->elements[j + 1] = temp;
            }
        }
    }
}

void insertionSort(Array *array) {
    for (int i = 1; i < array->size; i++) {
        int key = array->elements[i];
        int j = i - 1;

        while (j >= 0 && array->elements[j] > key) {
            array->elements[j + 1] = array->elements[j];
            j--;
        }
        array->elements[j + 1] = key;
    }
}

void selectionSort(Array *array) {
    for (int i = 0; i < array->size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < array->size; j++) {
            if (array->elements[j] < array->elements[min_idx])
                min_idx = j;
        }
        // Swap the found minimum element with the first element
        if (min_idx != i) {
            int temp = array->elements[min_idx];
            array->elements[min_idx] = array->elements[i];
            array->elements[i] = temp;
        }
    }
}

void printArray(const Array *array) {
    for (int i = 0; i < array->size; i++) {
        printf("%d ", array->elements[i]);
    }
    printf("\n");
}

double benchmarkSort(void (*sortFunc)(Array *), Array *array) {
    clock_t start, end;

    start = clock();
    sortFunc(array);
    end = clock();

    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

int main() {
    srand(time(NULL));
    
    Array array;
    initializeArray(&array, MAX_SIZE);

    printf("Original array:\n");
    printArray(&array);

    // Benchmark Bubble Sort
    Array bubbleArray = array; // Make a copy for bubble sort
    double bubbleTime = benchmarkSort(bubbleSort, &bubbleArray);
    printf("Bubble Sort took: %f seconds\n", bubbleTime);

    // Benchmark Insertion Sort
    Array insertionArray = array; // Make a copy for insertion sort
    double insertionTime = benchmarkSort(insertionSort, &insertionArray);
    printf("Insertion Sort took: %f seconds\n", insertionTime);

    // Benchmark Selection Sort
    Array selectionArray = array; // Make a copy for selection sort
    double selectionTime = benchmarkSort(selectionSort, &selectionArray);
    printf("Selection Sort took: %f seconds\n", selectionTime);

    freeArray(&array);
    return 0;
}