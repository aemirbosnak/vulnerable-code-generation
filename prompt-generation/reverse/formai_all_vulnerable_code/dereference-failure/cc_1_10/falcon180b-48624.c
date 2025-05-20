//Falcon-180B DATASET v1.0 Category: Educational ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} Array;

Array create_array() {
    Array arr = {
       .data = NULL,
       .size = 0,
       .capacity = MAX_SIZE
    };
    arr.data = malloc(arr.capacity * sizeof(int));
    return arr;
}

void destroy_array(Array *arr) {
    if (arr->data!= NULL) {
        free(arr->data);
        arr->data = NULL;
    }
    arr->size = 0;
    arr->capacity = MAX_SIZE;
}

void push_back(Array *arr, int value) {
    if (arr->size == arr->capacity) {
        arr->capacity *= 2;
        arr->data = realloc(arr->data, arr->capacity * sizeof(int));
    }
    arr->data[arr->size++] = value;
}

int pop_back(Array *arr) {
    if (arr->size == 0) {
        return -1;
    }
    int value = arr->data[arr->size - 1];
    arr->size--;
    return value;
}

void print_array(Array arr) {
    for (size_t i = 0; i < arr.size; i++) {
        printf("%d ", arr.data[i]);
    }
    printf("\n");
}

int main() {
    Array arr = create_array();

    push_back(&arr, 1);
    push_back(&arr, 2);
    push_back(&arr, 3);
    push_back(&arr, 4);
    push_back(&arr, 5);

    print_array(arr);

    int value = pop_back(&arr);
    printf("Popped value: %d\n", value);

    print_array(arr);

    destroy_array(&arr);

    return 0;
}