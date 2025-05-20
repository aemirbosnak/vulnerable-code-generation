//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    int *data;
    int size;
} IntArray;

void init_array(IntArray *array, int size) {
    array->data = malloc(size * sizeof(int));
    array->size = size;
}

void free_array(IntArray *array) {
    free(array->data);
}

void push_back(IntArray *array, int value) {
    if (array->size == MAX_SIZE) {
        printf("Error: Array is full.\n");
        return;
    }
    array->data[array->size++] = value;
}

int pop_back(IntArray *array) {
    if (array->size == 0) {
        printf("Error: Array is empty.\n");
        return -1;
    }
    return array->data[--array->size];
}

int main() {
    IntArray array;
    init_array(&array, 10);

    for (int i = 0; i < 20; i++) {
        push_back(&array, i);
    }

    for (int i = 0; i < 20; i++) {
        printf("%d ", pop_back(&array));
    }

    free_array(&array);

    return 0;
}