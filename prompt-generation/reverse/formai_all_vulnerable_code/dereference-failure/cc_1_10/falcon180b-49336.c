//Falcon-180B DATASET v1.0 Category: Educational ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define INIT_SIZE 10

typedef struct {
    int *array;
    int size;
    int capacity;
} DynamicArray;

DynamicArray *createDynamicArray() {
    DynamicArray *array = (DynamicArray *)malloc(sizeof(DynamicArray));
    array->array = (int *)malloc(INIT_SIZE * sizeof(int));
    array->size = 0;
    array->capacity = INIT_SIZE;
    return array;
}

void destroyDynamicArray(DynamicArray *array) {
    free(array->array);
    free(array);
}

void resizeDynamicArray(DynamicArray *array) {
    array->capacity *= 2;
    array->array = (int *)realloc(array->array, array->capacity * sizeof(int));
}

void pushBackDynamicArray(DynamicArray *array, int value) {
    if (array->size == array->capacity) {
        resizeDynamicArray(array);
    }
    array->array[array->size++] = value;
}

int popBackDynamicArray(DynamicArray *array) {
    if (array->size == 0) {
        return -1;
    }
    return array->array[--array->size];
}

int main() {
    srand(time(NULL));

    DynamicArray *array = createDynamicArray();

    for (int i = 0; i < MAX_SIZE; i++) {
        int value = rand() % 100;
        pushBackDynamicArray(array, value);
        printf("Pushed value %d\n", value);
    }

    for (int i = 0; i < MAX_SIZE; i++) {
        int value = popBackDynamicArray(array);
        printf("Popped value %d\n", value);
    }

    destroyDynamicArray(array);

    return 0;
}