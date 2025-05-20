//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 100

typedef struct {
    int *data;
    int size;
    int capacity;
} Array;

void init(Array *arr) {
    arr->data = (int *)malloc(MAX_SIZE * sizeof(int));
    arr->size = 0;
    arr->capacity = MAX_SIZE;
}

void push(Array *arr, int value) {
    if (arr->size == arr->capacity) {
        arr->capacity *= 2;
        int *new_data = (int *)realloc(arr->data, arr->capacity * sizeof(int));
        if (new_data == NULL) {
            printf("Memory error\n");
            exit(1);
        }
        arr->data = new_data;
    }
    arr->data[arr->size++] = value;
}

int pop(Array *arr) {
    if (arr->size == 0) {
        printf("Stack is empty\n");
        exit(1);
    }
    return arr->data[--arr->size];
}

bool is_empty(Array *arr) {
    return arr->size == 0;
}

void print_array(Array *arr) {
    if (is_empty(arr)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

int main() {
    Array stack;
    init(&stack);
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    print_array(&stack);
    printf("Popped element: %d\n", pop(&stack));
    print_array(&stack);
    printf("Popped element: %d\n", pop(&stack));
    print_array(&stack);
    printf("Popped element: %d\n", pop(&stack));
    print_array(&stack);
    printf("Popped element: %d\n", pop(&stack));
    print_array(&stack);
    printf("Popped element: %d\n", pop(&stack));
    print_array(&stack);
    return 0;
}