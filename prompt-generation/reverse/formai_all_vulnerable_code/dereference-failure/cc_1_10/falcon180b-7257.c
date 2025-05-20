//Falcon-180B DATASET v1.0 Category: Memory management ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int capacity;
    int size;
} Vector;

Vector *create_vector(int capacity) {
    Vector *vector = malloc(sizeof(Vector));
    vector->data = malloc(capacity * sizeof(int));
    vector->capacity = capacity;
    vector->size = 0;
    return vector;
}

void destroy_vector(Vector *vector) {
    free(vector->data);
    free(vector);
}

void push_back(Vector *vector, int value) {
    if (vector->size == vector->capacity) {
        vector->capacity *= 2;
        vector->data = realloc(vector->data, vector->capacity * sizeof(int));
    }
    vector->data[vector->size++] = value;
}

int main() {
    Vector *vector = create_vector(10);
    push_back(vector, 1);
    push_back(vector, 2);
    push_back(vector, 3);
    push_back(vector, 4);
    push_back(vector, 5);
    push_back(vector, 6);
    push_back(vector, 7);
    push_back(vector, 8);
    push_back(vector, 9);
    push_back(vector, 10);
    push_back(vector, 11); // This should cause a reallocation and double the capacity

    for (int i = 0; i < vector->size; i++) {
        printf("%d ", vector->data[i]);
    }

    destroy_vector(vector);
    return 0;
}