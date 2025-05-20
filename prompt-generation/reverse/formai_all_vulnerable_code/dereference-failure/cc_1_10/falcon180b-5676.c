//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct {
    int *data;
    int size;
} IntArray;

void initArray(IntArray *array) {
    array->data = (int *) malloc(MAX_SIZE * sizeof(int));
    array->size = 0;
}

void freeArray(IntArray *array) {
    free(array->data);
}

void push(IntArray *array, int value) {
    if (array->size >= MAX_SIZE) {
        printf("Error: array is full\n");
        return;
    }
    array->data[array->size++] = value;
}

int pop(IntArray *array) {
    if (array->size == 0) {
        printf("Error: array is empty\n");
        return -1;
    }
    return array->data[--array->size];
}

void printArray(IntArray *array) {
    if (array->size == 0) {
        printf("Empty array\n");
        return;
    }
    printf("Array: ");
    for (int i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

int main() {
    IntArray arr;
    initArray(&arr);

    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        int value = rand() % 100;
        push(&arr, value);
        printf("Pushed: %d\n", value);
    }

    printArray(&arr);

    for (int i = 0; i < 5; i++) {
        int value = pop(&arr);
        printf("Popped: %d\n", value);
    }

    printArray(&arr);

    freeArray(&arr);
    return 0;
}