//Falcon-180B DATASET v1.0 Category: Sorting ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000

typedef struct {
    int data;
    int index;
} Element;

void swap(Element* a, Element* b) {
    Element temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Element* arr, int low, int high) {
    int pivot = arr[(low + high) / 2].data;
    Element pivotElement = arr[(low + high) / 2];

    swap(&pivotElement, &arr[high]);

    int storeIndex = low;

    for (int i = low; i < high; i++) {
        if (arr[i].data < pivot) {
            swap(&arr[i], &arr[storeIndex]);
            storeIndex++;
        }
    }

    swap(&arr[storeIndex], &arr[high]);
    return storeIndex;
}

void quickSort(Element* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(Element* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i].data);
    }
    printf("\n");
}

int main() {
    srand(time(0));

    Element* arr = (Element*) malloc(sizeof(Element) * SIZE);

    for (int i = 0; i < SIZE; i++) {
        arr[i].data = rand() % 100;
        arr[i].index = i;
    }

    quickSort(arr, 0, SIZE - 1);

    printArray(arr, SIZE);

    free(arr);

    return 0;
}