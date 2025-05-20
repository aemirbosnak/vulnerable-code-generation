//Falcon2-11B DATASET v1.0 Category: Benchmarking ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a structure to hold the input array and its size
struct Input {
    int size;
    int* array;
};

// Define a function to initialize an array with random values
void initializeArray(struct Input* input) {
    input->size = 100;
    input->array = (int*)malloc(input->size * sizeof(int));
    for (int i = 0; i < input->size; i++) {
        input->array[i] = rand() % 100;
    }
}

// Define a function to sort an array using quicksort
void quicksort(struct Input* input) {
    struct Input temp = {input->size, input->array};
    quicksort(&temp);
    free(input->array);
    input->array = temp.array;
}

// Define a function to sort an array using merge sort
void mergeSort(struct Input* input) {
    struct Input temp = {input->size, input->array};
    mergeSort(&temp);
    free(input->array);
    input->array = temp.array;
}

// Define a function to sort an array using insertion sort
void insertionSort(struct Input* input) {
    struct Input temp = {input->size, input->array};
    insertionSort(&temp);
    free(input->array);
    input->array = temp.array;
}

// Define a function to measure the time it takes to sort an array
double measureTime(struct Input* input, void (*sortFunction)(struct Input*)) {
    double startTime = clock();
    sortFunction(input);
    double endTime = clock();
    return (endTime - startTime) / CLOCKS_PER_SEC;
}

// Define a function to print an array
void printArray(struct Input* input) {
    printf("[");
    for (int i = 0; i < input->size; i++) {
        printf("%d, ", input->array[i]);
    }
    printf("]\n");
}

// Main function
int main() {
    struct Input input;
    initializeArray(&input);

    double quicksortTime = measureTime(&input, quicksort);
    double mergeSortTime = measureTime(&input, mergeSort);
    double insertionSortTime = measureTime(&input, insertionSort);

    printf("Quicksort: %f\n", quicksortTime);
    printf("Merge sort: %f\n", mergeSortTime);
    printf("Insertion sort: %f\n", insertionSortTime);

    printArray(&input);

    return 0;
}