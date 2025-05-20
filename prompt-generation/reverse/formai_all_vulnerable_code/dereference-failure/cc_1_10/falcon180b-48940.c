//Falcon-180B DATASET v1.0 Category: Memory management ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int *arr;
    int size;
    int capacity;
} Array;

Array* createArray() {
    Array* newArray = (Array*)malloc(sizeof(Array));
    if (newArray == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    newArray->arr = (int*)malloc(sizeof(int) * MAX_SIZE);
    if (newArray->arr == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    newArray->size = 0;
    newArray->capacity = MAX_SIZE;
    return newArray;
}

void destroyArray(Array* arr) {
    free(arr->arr);
    free(arr);
}

void resizeArray(Array* arr) {
    int* newArr = (int*)realloc(arr->arr, sizeof(int) * arr->capacity * 2);
    if (newArr == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    arr->arr = newArr;
    arr->capacity *= 2;
}

void push(Array* arr, int value) {
    if (arr->size == arr->capacity) {
        resizeArray(arr);
    }
    arr->arr[arr->size++] = value;
}

int pop(Array* arr) {
    if (arr->size == 0) {
        printf("Stack is empty\n");
        exit(1);
    }
    return arr->arr[--arr->size];
}

int peek(Array* arr, int index) {
    if (index < 0 || index >= arr->size) {
        printf("Invalid index\n");
        exit(1);
    }
    return arr->arr[index];
}

void printArray(Array* arr) {
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->arr[i]);
    }
    printf("\n");
}

int main() {
    Array* stack = createArray();
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    push(stack, 50);

    printArray(stack);

    printf("Top element: %d\n", peek(stack, 4));

    pop(stack);
    pop(stack);

    printArray(stack);

    destroyArray(stack);
    return 0;
}