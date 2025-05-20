//Falcon-180B DATASET v1.0 Category: Memory management ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int *data;
    int size;
    int capacity;
} Array;

void init_array(Array *array) {
    array->data = (int *)malloc(MAX_SIZE * sizeof(int));
    array->size = 0;
    array->capacity = MAX_SIZE;
}

void free_array(Array *array) {
    free(array->data);
}

void resize_array(Array *array) {
    int *new_data = (int *)realloc(array->data, array->capacity * sizeof(int));
    if (new_data == NULL) {
        printf("Error: Failed to resize array.\n");
        exit(1);
    }
    array->data = new_data;
    array->capacity *= 2;
}

void push_back(Array *array, int value) {
    if (array->size == array->capacity) {
        resize_array(array);
    }
    array->data[array->size] = value;
    array->size++;
}

void pop_back(Array *array) {
    if (array->size == 0) {
        printf("Error: Array is empty.\n");
        exit(1);
    }
    array->size--;
}

void print_array(Array *array) {
    for (int i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

int main() {
    Array array;
    init_array(&array);

    push_back(&array, 1);
    push_back(&array, 2);
    push_back(&array, 3);
    push_back(&array, 4);
    push_back(&array, 5);

    print_array(&array);

    pop_back(&array);

    print_array(&array);

    free_array(&array);

    return 0;
}