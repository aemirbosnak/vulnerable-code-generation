//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int *data;
    int size;
    int capacity;
} DynamicArray;

DynamicArray *createDynamicArray(int capacity) {
    DynamicArray *array = (DynamicArray *) malloc(sizeof(DynamicArray));
    if (array == NULL) {
        printf("Error: Out of memory.\n");
        exit(1);
    }
    array->data = (int *) malloc(capacity * sizeof(int));
    if (array->data == NULL) {
        printf("Error: Out of memory.\n");
        exit(1);
    }
    array->size = 0;
    array->capacity = capacity;
    return array;
}

void destroyDynamicArray(DynamicArray *array) {
    if (array == NULL) {
        return;
    }
    free(array->data);
    free(array);
}

void resizeDynamicArray(DynamicArray *array, int newCapacity) {
    int *newData = (int *) malloc(newCapacity * sizeof(int));
    if (newData == NULL) {
        printf("Error: Out of memory.\n");
        exit(1);
    }
    int i;
    for (i = 0; i < array->size; i++) {
        newData[i] = array->data[i];
    }
    free(array->data);
    array->data = newData;
    array->capacity = newCapacity;
}

void pushDynamicArray(DynamicArray *array, int value) {
    if (array->size == array->capacity) {
        resizeDynamicArray(array, array->capacity * 2);
    }
    array->data[array->size++] = value;
}

int popDynamicArray(DynamicArray *array) {
    if (array->size == 0) {
        printf("Error: Array is empty.\n");
        exit(1);
    }
    return array->data[--array->size];
}

void printDynamicArray(DynamicArray *array) {
    int i;
    for (i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

int main() {
    DynamicArray *array = createDynamicArray(MAX_SIZE);
    pushDynamicArray(array, 1);
    pushDynamicArray(array, 2);
    pushDynamicArray(array, 3);
    pushDynamicArray(array, 4);
    pushDynamicArray(array, 5);
    printDynamicArray(array);
    int value = popDynamicArray(array);
    printf("Popped value: %d\n", value);
    printDynamicArray(array);
    destroyDynamicArray(array);
    return 0;
}