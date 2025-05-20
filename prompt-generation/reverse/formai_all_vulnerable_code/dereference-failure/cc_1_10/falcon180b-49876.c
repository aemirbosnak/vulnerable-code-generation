//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define INITIAL_CAPACITY 10

typedef struct {
    int *data;
    int capacity;
    int size;
} Array;

void init(Array *array) {
    array->data = (int *)malloc(INITIAL_CAPACITY * sizeof(int));
    array->capacity = INITIAL_CAPACITY;
    array->size = 0;
}

void resize(Array *array) {
    array->capacity *= 2;
    int *new_data = (int *)malloc(array->capacity * sizeof(int));
    memcpy(new_data, array->data, array->size * sizeof(int));
    free(array->data);
    array->data = new_data;
}

void push(Array *array, int value) {
    if (array->size == array->capacity) {
        resize(array);
    }
    array->data[array->size++] = value;
}

int pop(Array *array) {
    if (array->size == 0) {
        printf("Stack is empty\n");
        return -1;
    }
    return array->data[--array->size];
}

int peek(Array *array) {
    if (array->size == 0) {
        printf("Stack is empty\n");
        return -1;
    }
    return array->data[array->size - 1];
}

int main() {
    Array stack;
    init(&stack);
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    printf("Top element is: %d\n", peek(&stack));
    pop(&stack);
    printf("Top element is: %d\n", peek(&stack));
    pop(&stack);
    printf("Top element is: %d\n", peek(&stack));
    pop(&stack);
    pop(&stack); // This won't cause any errors since the stack is already empty
    return 0;
}