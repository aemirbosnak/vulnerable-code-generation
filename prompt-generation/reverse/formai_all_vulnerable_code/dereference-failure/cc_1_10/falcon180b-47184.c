//Falcon-180B DATASET v1.0 Category: Memory management ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} Vector;

Vector *vector_create(int capacity);
void vector_destroy(Vector *vector);
void vector_push(Vector *vector, int data);
int vector_pop(Vector *vector);
int vector_size(Vector *vector);
int vector_capacity(Vector *vector);

Vector *vector_create(int capacity) {
    Vector *vector = malloc(sizeof(Vector));
    vector->data = NULL;
    vector->size = 0;
    vector->capacity = capacity;
    vector->data = malloc(vector->capacity * sizeof(int));
    return vector;
}

void vector_destroy(Vector *vector) {
    free(vector->data);
    free(vector);
}

void vector_push(Vector *vector, int data) {
    if (vector->size == vector->capacity) {
        vector->capacity *= 2;
        vector->data = realloc(vector->data, vector->capacity * sizeof(int));
    }
    vector->data[vector->size++] = data;
}

int vector_pop(Vector *vector) {
    if (vector->size == 0) {
        return -1;
    }
    return vector->data[--vector->size];
}

int vector_size(Vector *vector) {
    return vector->size;
}

int vector_capacity(Vector *vector) {
    return vector->capacity;
}

int main() {
    Vector *vector = vector_create(10);
    int i;

    for (i = 0; i < 20; ++i) {
        vector_push(vector, i);
        printf("Size: %d, Capacity: %d\n", vector_size(vector), vector_capacity(vector));
    }

    for (i = 0; i < 20; ++i) {
        printf("%d ", vector_pop(vector));
    }

    vector_destroy(vector);

    return 0;
}