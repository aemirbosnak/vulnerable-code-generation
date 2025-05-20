//Falcon-180B DATASET v1.0 Category: Error handling ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *ptr;
    int size;
} Array;

void initArray(Array *arr, int size) {
    arr->ptr = malloc(size * sizeof(int));
    if (arr->ptr == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }
    arr->size = size;
}

void resizeArray(Array *arr, int newSize) {
    int *newPtr = realloc(arr->ptr, newSize * sizeof(int));
    if (newPtr == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }
    arr->ptr = newPtr;
    arr->size = newSize;
}

void freeArray(Array *arr) {
    free(arr->ptr);
    arr->ptr = NULL;
    arr->size = 0;
}

void push(Array *arr, int value) {
    if (arr->size == 0) {
        initArray(arr, 1);
    } else if (arr->size == arr->ptr[0]) {
        resizeArray(arr, arr->size * 2);
    }
    arr->ptr[arr->size++] = value;
}

int pop(Array *arr) {
    if (arr->size == 0) {
        printf("Error: Stack is empty!\n");
        exit(1);
    }
    return arr->ptr[--arr->size];
}

int peek(Array *arr) {
    if (arr->size == 0) {
        printf("Error: Stack is empty!\n");
        exit(1);
    }
    return arr->ptr[arr->size - 1];
}

int isEmpty(Array *arr) {
    return arr->size == 0;
}

int main() {
    Array stack;
    initArray(&stack, 1);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element: %d\n", peek(&stack));

    pop(&stack);
    pop(&stack);

    printf("Top element after popping twice: %d\n", peek(&stack));

    freeArray(&stack);

    return 0;
}