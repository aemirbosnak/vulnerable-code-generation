//Falcon-180B DATASET v1.0 Category: Memory management ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int *data;
    int size;
} DynamicArray;

void init(DynamicArray *array) {
    array->data = NULL;
    array->size = 0;
}

void push(DynamicArray *array, int value) {
    if (array->size >= MAX_SIZE) {
        printf("Error: Array is full.\n");
        return;
    }
    int *newData = (int *)realloc(array->data, (array->size + 1) * sizeof(int));
    if (newData == NULL) {
        printf("Error: Memory allocation failed.\n");
        return;
    }
    array->data = newData;
    array->data[array->size++] = value;
}

void pop(DynamicArray *array) {
    if (array->size == 0) {
        printf("Error: Array is empty.\n");
        return;
    }
    int *newData = (int *)realloc(array->data, (array->size - 1) * sizeof(int));
    if (newData == NULL) {
        printf("Error: Memory allocation failed.\n");
        return;
    }
    array->data = newData;
    array->size--;
}

void print(DynamicArray *array) {
    for (int i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

int main() {
    DynamicArray array;
    init(&array);

    push(&array, 1);
    push(&array, 2);
    push(&array, 3);
    push(&array, 4);
    push(&array, 5);

    print(&array);

    pop(&array);
    pop(&array);

    print(&array);

    return 0;
}