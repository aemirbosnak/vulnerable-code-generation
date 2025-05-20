//Falcon-180B DATASET v1.0 Category: Memory management ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARRAY_SIZE 100

typedef struct {
    int *data;
    int capacity;
    int size;
} Array;

Array *array_create() {
    Array *array = (Array *)malloc(sizeof(Array));
    array->data = (int *)malloc(MAX_ARRAY_SIZE * sizeof(int));
    array->capacity = MAX_ARRAY_SIZE;
    array->size = 0;
    return array;
}

void array_destroy(Array *array) {
    free(array->data);
    free(array);
}

void array_add(Array *array, int value) {
    if (array->size >= array->capacity) {
        array->capacity *= 2;
        array->data = realloc(array->data, array->capacity * sizeof(int));
    }
    array->data[array->size++] = value;
}

void array_print(Array *array) {
    for (int i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

int main() {
    Array *array = array_create();

    array_add(array, 1);
    array_add(array, 2);
    array_add(array, 3);

    array_print(array);

    array_destroy(array);

    return 0;
}