//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define INITIAL_CAPACITY 10

typedef struct {
    char *data;
    int capacity;
    int size;
} DynamicArray;

DynamicArray *createDynamicArray() {
    DynamicArray *array = (DynamicArray *)malloc(sizeof(DynamicArray));
    if (array!= NULL) {
        array->data = (char *)malloc(INITIAL_CAPACITY * sizeof(char));
        if (array->data!= NULL) {
            array->capacity = INITIAL_CAPACITY;
            array->size = 0;
        } else {
            free(array);
            array = NULL;
        }
    }
    return array;
}

void destroyDynamicArray(DynamicArray *array) {
    if (array!= NULL) {
        free(array->data);
        free(array);
    }
}

void resizeDynamicArray(DynamicArray *array, int newCapacity) {
    char *newData = (char *)malloc(newCapacity * sizeof(char));
    if (newData!= NULL) {
        memcpy(newData, array->data, array->size * sizeof(char));
        free(array->data);
        array->data = newData;
        array->capacity = newCapacity;
    }
}

void appendDynamicArray(DynamicArray *array, char *value) {
    if (array->size == array->capacity) {
        resizeDynamicArray(array, array->capacity * 2);
    }
    strcat(array->data, value);
    array->size++;
}

void printDynamicArray(DynamicArray *array) {
    printf("Dynamic Array: %s\n", array->data);
}

int main() {
    DynamicArray *array = createDynamicArray();

    appendDynamicArray(array, "Hello");
    appendDynamicArray(array, " World!");

    printDynamicArray(array);

    destroyDynamicArray(array);

    return 0;
}