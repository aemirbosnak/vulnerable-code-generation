//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} DynamicArray;

DynamicArray *createDynamicArray(int capacity) {
    DynamicArray *array = (DynamicArray *)malloc(sizeof(DynamicArray));
    array->data = (int *)malloc(sizeof(int) * capacity);
    array->size = 0;
    array->capacity = capacity;
    return array;
}

void destroyDynamicArray(DynamicArray *array) {
    free(array->data);
    free(array);
}

void addElementToDynamicArray(DynamicArray *array, int element) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->data = (int *)realloc(array->data, sizeof(int) * array->capacity);
    }
    array->data[array->size++] = element;
}

int binarySearch(DynamicArray *array, int target) {
    int left = 0;
    int right = array->size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (array->data[mid] == target) {
            return mid;
        } else if (array->data[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

void printDynamicArray(DynamicArray *array) {
    int i;
    for (i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    DynamicArray *array = createDynamicArray(10);

    int i;
    for (i = 0; i < 20; i++) {
        int element = rand() % 100;
        addElementToDynamicArray(array, element);
        printf("Added element %d\n", element);
    }

    printDynamicArray(array);

    int target = rand() % 100;
    int index = binarySearch(array, target);

    if (index == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at index %d\n", index);
    }

    destroyDynamicArray(array);

    return 0;
}