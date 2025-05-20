//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    int size;
    int capacity;
    int *data;
} IntArray;

void init(IntArray *array, int capacity) {
    array->size = 0;
    array->capacity = capacity;
    array->data = (int *) malloc(capacity * sizeof(int));
}

void append(IntArray *array, int value) {
    if (array->size >= array->capacity) {
        array->capacity *= 2;
        array->data = (int *) realloc(array->data, array->capacity * sizeof(int));
    }
    array->data[array->size++] = value;
}

void print(IntArray *array) {
    for (int i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

int main() {
    IntArray arr1, arr2;
    init(&arr1, MAX_SIZE);
    init(&arr2, MAX_SIZE);

    for (int i = 0; i < MAX_SIZE; i++) {
        append(&arr1, i);
    }

    printf("Original array:\n");
    print(&arr1);

    int *data1 = arr1.data;
    int *data2 = arr2.data;
    int size1 = arr1.size;
    int size2 = 0;

    while (size1 > 0 && size2 < MAX_SIZE) {
        if (data1[size1 - 1] % 2 == 0) {
            append(&arr2, data1[--size1]);
            size2++;
        } else {
            size1--;
        }
    }

    printf("Filtered array:\n");
    print(&arr2);

    return 0;
}