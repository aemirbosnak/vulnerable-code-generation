//Falcon-180B DATASET v1.0 Category: Memory management ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct {
    int *data;
    int capacity;
    int length;
} Array;

void initArray(Array *array) {
    array->data = (int *)malloc(SIZE * sizeof(int));
    array->capacity = SIZE;
    array->length = 0;
}

void resizeArray(Array *array) {
    int *newData = (int *)realloc(array->data, array->capacity * 2 * sizeof(int));
    if (newData!= NULL) {
        array->data = newData;
        array->capacity *= 2;
    }
}

void addElement(Array *array, int element) {
    if (array->length == array->capacity) {
        resizeArray(array);
    }
    array->data[array->length++] = element;
}

void printArray(Array *array) {
    printf("[");
    for (int i = 0; i < array->length; i++) {
        printf("%d", array->data[i]);
        if (i!= array->length - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    Array array;
    initArray(&array);

    addElement(&array, 1);
    addElement(&array, 2);
    addElement(&array, 3);
    addElement(&array, 4);
    addElement(&array, 5);
    addElement(&array, 6);
    addElement(&array, 7);
    addElement(&array, 8);
    addElement(&array, 9);
    addElement(&array, 10);

    printArray(&array);

    return 0;
}