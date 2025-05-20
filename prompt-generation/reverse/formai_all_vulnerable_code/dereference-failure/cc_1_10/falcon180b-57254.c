//Falcon-180B DATASET v1.0 Category: Sorting ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

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
    Element pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].data < pivot.data) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort(Element* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void printArray(Element* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i].data);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    Element* arr = malloc(MAX_SIZE * sizeof(Element));

    int size = 0;

    while (size < MAX_SIZE) {
        int data = rand() % 1000000;
        int index = rand() % MAX_SIZE;

        if (index >= size) {
            arr[index].data = data;
            arr[index].index = index;
            size++;
        }
    }

    printf("Before sorting:\n");
    printArray(arr, size);

    quicksort(arr, 0, size - 1);

    printf("After sorting:\n");
    printArray(arr, size);

    free(arr);

    return 0;
}