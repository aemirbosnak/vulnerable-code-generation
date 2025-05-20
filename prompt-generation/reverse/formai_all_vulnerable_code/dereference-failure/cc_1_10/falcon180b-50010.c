//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000

typedef struct {
    int *arr;
    int size;
} Array;

void init_array(Array *a) {
    a->arr = (int *)malloc(MAX_SIZE * sizeof(int));
    a->size = 0;
}

void push_back(Array *a, int n) {
    if (a->size >= MAX_SIZE) {
        printf("Error: Array is full\n");
        return;
    }
    a->arr[a->size++] = n;
}

void pop_back(Array *a) {
    if (a->size == 0) {
        printf("Error: Array is empty\n");
        return;
    }
    a->size--;
}

int get_size(Array *a) {
    return a->size;
}

int get_element(Array *a, int index) {
    if (index >= a->size) {
        printf("Error: Index out of bounds\n");
        return -1;
    }
    return a->arr[index];
}

int main() {
    Array a;
    init_array(&a);

    push_back(&a, 1);
    push_back(&a, 2);
    push_back(&a, 3);

    printf("Size: %d\n", get_size(&a));
    printf("Element at index 1: %d\n", get_element(&a, 1));

    pop_back(&a);
    push_back(&a, 4);

    printf("Size: %d\n", get_size(&a));
    printf("Element at index 2: %d\n", get_element(&a, 2));

    return 0;
}