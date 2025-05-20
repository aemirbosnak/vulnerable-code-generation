//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000000

typedef struct {
    int* data;
    int size;
    int capacity;
} Array;

Array* create_array(int size) {
    Array* arr = (Array*) malloc(sizeof(Array));
    if (arr == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    arr->data = (int*) malloc(sizeof(int) * size);
    if (arr->data == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    arr->size = 0;
    arr->capacity = size;
    return arr;
}

void destroy_array(Array* arr) {
    free(arr->data);
    free(arr);
}

void push_back(Array* arr, int value) {
    if (arr->size >= arr->capacity) {
        arr->capacity *= 2;
        arr->data = (int*) realloc(arr->data, sizeof(int) * arr->capacity);
    }
    arr->data[arr->size++] = value;
}

int pop_back(Array* arr) {
    if (arr->size == 0) {
        printf("Array is empty\n");
        exit(1);
    }
    return arr->data[--arr->size];
}

int get_size(Array* arr) {
    return arr->size;
}

int main() {
    Array* arr = create_array(MAX_SIZE);
    int i;
    for (i = 0; i < MAX_SIZE; i++) {
        push_back(arr, i);
    }
    for (i = 0; i < MAX_SIZE; i++) {
        printf("%d ", pop_back(arr));
    }
    printf("\n");
    destroy_array(arr);
    return 0;
}