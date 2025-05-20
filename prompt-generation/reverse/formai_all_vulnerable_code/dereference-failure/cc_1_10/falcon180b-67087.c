//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

typedef struct {
    int *data;
    int size;
    int capacity;
} DynamicArray;

void initDynamicArray(DynamicArray *array) {
    array->data = NULL;
    array->size = 0;
    array->capacity = MAX_SIZE;
}

void freeDynamicArray(DynamicArray *array) {
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = MAX_SIZE;
}

void resizeDynamicArray(DynamicArray *array) {
    array->capacity *= 2;
    array->data = realloc(array->data, array->capacity * sizeof(int));
}

void pushDynamicArray(DynamicArray *array, int value) {
    if (array->size == array->capacity) {
        resizeDynamicArray(array);
    }
    array->data[array->size++] = value;
}

int popDynamicArray(DynamicArray *array) {
    if (array->size == 0) {
        return -1;
    }
    return array->data[--array->size];
}

void printDynamicArray(DynamicArray *array) {
    for (int i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

int main() {
    DynamicArray array;
    initDynamicArray(&array);
    pushDynamicArray(&array, 1);
    pushDynamicArray(&array, 2);
    pushDynamicArray(&array, 3);
    pushDynamicArray(&array, 4);
    pushDynamicArray(&array, 5);
    printDynamicArray(&array);
    int value = popDynamicArray(&array);
    printf("Popped value: %d\n", value);
    printDynamicArray(&array);
    freeDynamicArray(&array);
    return 0;
}