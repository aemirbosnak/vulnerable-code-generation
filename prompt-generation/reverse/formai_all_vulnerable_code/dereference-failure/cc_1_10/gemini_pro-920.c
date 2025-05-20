//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int *arr;
    int size;
    int capacity;
} vector;

vector *vector_create(int capacity) {
    vector *v = malloc(sizeof(vector));
    v->arr = malloc(sizeof(int) * capacity);
    v->size = 0;
    v->capacity = capacity;
    return v;
}

void vector_destroy(vector *v) {
    free(v->arr);
    free(v);
}

void vector_push_back(vector *v, int value) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->arr = realloc(v->arr, sizeof(int) * v->capacity);
    }
    v->arr[v->size++] = value;
}

int vector_get(vector *v, int index) {
    if (index < 0 || index >= v->size) {
        fprintf(stderr, "Error: Index out of bounds.\n");
        exit(1);
    }
    return v->arr[index];
}

void vector_set(vector *v, int index, int value) {
    if (index < 0 || index >= v->size) {
        fprintf(stderr, "Error: Index out of bounds.\n");
        exit(1);
    }
    v->arr[index] = value;
}

void vector_print(vector *v) {
    printf("[");
    for (int i = 0; i < v->size; i++) {
        printf("%d, ", v->arr[i]);
    }
    printf("]\n");
}

int main() {
    vector *v = vector_create(10);
    for (int i = 0; i < 10; i++) {
        vector_push_back(v, i);
    }
    vector_print(v);
    vector_set(v, 5, 10);
    vector_print(v);
    int x = vector_get(v, 5);
    printf("x = %d\n", x);
    vector_destroy(v);
    return 0;
}