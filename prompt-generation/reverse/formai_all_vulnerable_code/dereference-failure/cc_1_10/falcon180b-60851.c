//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} DynamicArray;

DynamicArray *createArray(int capacity) {
    DynamicArray *array = (DynamicArray *)malloc(sizeof(DynamicArray));
    array->data = (int *)malloc(capacity * sizeof(int));
    array->size = 0;
    array->capacity = capacity;
    return array;
}

void destroyArray(DynamicArray *array) {
    free(array->data);
    free(array);
}

void pushBack(DynamicArray *array, int value) {
    if (array->size >= array->capacity) {
        array->capacity *= 2;
        array->data = (int *)realloc(array->data, array->capacity * sizeof(int));
    }
    array->data[array->size++] = value;
}

int popBack(DynamicArray *array) {
    if (array->size == 0) {
        return -1;
    }
    return array->data[--array->size];
}

int main() {
    srand(time(NULL));
    DynamicArray *array = createArray(10);

    for (int i = 0; i < 100000; i++) {
        int choice = rand() % 3;
        switch (choice) {
            case 0:
                pushBack(array, rand() % 100);
                break;
            case 1:
                printf("%d\n", popBack(array));
                break;
            case 2:
                printf("%d\n", array->data[rand() % array->size]);
                break;
            default:
                break;
        }
    }

    destroyArray(array);
    return 0;
}