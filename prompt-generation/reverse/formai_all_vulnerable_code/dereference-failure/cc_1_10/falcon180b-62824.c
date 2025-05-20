//Falcon-180B DATASET v1.0 Category: Memory management ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 10000

typedef struct {
    int *data;
    int size;
    int capacity;
} DynamicArray;

void initArray(DynamicArray *array) {
    array->data = (int *)malloc(MAX_SIZE * sizeof(int));
    array->size = 0;
    array->capacity = MAX_SIZE;
}

void resizeArray(DynamicArray *array) {
    array->capacity *= 2;
    array->data = (int *)realloc(array->data, array->capacity * sizeof(int));
}

void pushBack(DynamicArray *array, int value) {
    if (array->size == array->capacity) {
        resizeArray(array);
    }
    array->data[array->size++] = value;
}

int main() {
    DynamicArray array;
    initArray(&array);

    srand(time(NULL));
    for (int i = 0; i < 100000; i++) {
        int value = rand() % 1000;
        pushBack(&array, value);
    }

    for (int i = 0; i < array.size; i++) {
        printf("%d ", array.data[i]);
    }

    free(array.data);
    return 0;
}