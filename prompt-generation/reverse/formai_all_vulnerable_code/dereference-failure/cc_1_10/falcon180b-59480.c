//Falcon-180B DATASET v1.0 Category: Sorting ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 1000

typedef struct {
    int *data;
    int size;
} Array;

void initArray(Array *array, int size) {
    array->data = (int *) malloc(sizeof(int) * size);
    array->size = size;
}

void printArray(Array array) {
    for (int i = 0; i < array.size; i++) {
        printf("%d ", array.data[i]);
    }
    printf("\n");
}

int partition(Array array, int low, int high) {
    int pivot = array.data[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (array.data[j] <= pivot) {
            i++;
            int temp = array.data[i];
            array.data[i] = array.data[j];
            array.data[j] = temp;
        }
    }
    int temp = array.data[i + 1];
    array.data[i + 1] = array.data[high];
    array.data[high] = temp;
    return i + 1;
}

void quickSort(Array array, int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

void sortArray(Array array) {
    srand(time(0));
    quickSort(array, 0, array.size - 1);
}

int main() {
    Array arr;
    initArray(&arr, SIZE);

    for (int i = 0; i < SIZE; i++) {
        arr.data[i] = rand() % 1000;
    }

    printf("Unsorted Array:\n");
    printArray(arr);

    sortArray(arr);

    printf("\nSorted Array:\n");
    printArray(arr);

    return 0;
}