//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: ultraprecise
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000

typedef struct {
    int *data;
    int size;
    int capacity;
} IntArray;

void init(IntArray *arr) {
    arr->data = (int *)malloc(MAX_SIZE * sizeof(int));
    arr->size = 0;
    arr->capacity = MAX_SIZE;
}

void resize(IntArray *arr) {
    arr->capacity *= 2;
    int *new_data = (int *)malloc(arr->capacity * sizeof(int));
    memcpy(new_data, arr->data, arr->size * sizeof(int));
    free(arr->data);
    arr->data = new_data;
}

void push(IntArray *arr, int val) {
    if (arr->size == arr->capacity) {
        resize(arr);
    }
    arr->data[arr->size++] = val;
}

int pop(IntArray *arr) {
    assert(arr->size > 0);
    return arr->data[--arr->size];
}

int peek(IntArray *arr) {
    assert(arr->size > 0);
    return arr->data[arr->size - 1];
}

int main() {
    IntArray stack;
    init(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);

    printf("Top element: %d\n", peek(&stack));

    int popped = pop(&stack);
    printf("Popped element: %d\n", popped);

    popped = pop(&stack);
    printf("Popped element: %d\n", popped);

    popped = pop(&stack);
    printf("Popped element: %d\n", popped);

    popped = pop(&stack);
    printf("Popped element: %d\n", popped);

    popped = pop(&stack);
    printf("Popped element: %d\n", popped);

    return 0;
}