//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 10
#define ELEMENT_SIZE 50

typedef struct CircularNestedArray {
    int size;
    int capacity;
    int *data;
    int top;
} CircularNestedArray;

CircularNestedArray *createCircularNestedArray() {
    CircularNestedArray *cna = (CircularNestedArray *) malloc(sizeof(CircularNestedArray));

    cna->size = 0;
    cna->capacity = 1;
    cna->data = (int *) calloc(cna->capacity, sizeof(int) * MAX_ELEMENTS);
    cna->top = -1;

    return cna;
}

void push(CircularNestedArray *cna, int index, int value) {
    if (cna->size == cna->capacity) {
        cna->capacity *= 2;
        cna->data = (int *) realloc(cna->data, cna->capacity * sizeof(int) * MAX_ELEMENTS);
    }

    int offset = index % cna->capacity;
    int pos = (cna->top + 1) % cna->capacity;

    while (cna->data[pos] != -1 && pos != offset) {
        pos = (pos + 1) % cna->capacity;
    }

    cna->data[pos] = value;
    cna->top = pos;
    cna->size++;
}

int pop(CircularNestedArray *cna, int *index) {
    if (cna->size == 0) {
        return -1;
    }

    int value = cna->data[cna->top];
    *index = cna->top;

    cna->top = (cna->top + 1) % cna->capacity;
    cna->size--;

    return value;
}

void printCircularNestedArray(CircularNestedArray *cna) {
    if (cna->size == 0) {
        printf("CircularNestedArray is empty.\n");
        return;
    }

    printf("CircularNestedArray:\n");
    for (int i = 0; i < cna->capacity; i++) {
        printf("[%d]: ", i);
        if (cna->data[i] == -1) {
            printf("EMPTY\n");
            continue;
        }
        printf("%d\n", cna->data[i]);
    }
    printf("\n");
}

int main() {
    CircularNestedArray *cna = createCircularNestedArray();

    for (int i = 0; i < 5; i++) {
        push(cna, i, i * 5);
    }

    printCircularNestedArray(cna);

    int index;
    for (int i = 0; i < 5; i++) {
        int value = pop(cna, &index);
        printf("Popped value: %d, index: %d\n", value, index);
    }

    printCircularNestedArray(cna);

    return 0;
}