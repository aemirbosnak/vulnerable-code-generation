//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} Vector;

Vector *vector_create() {
    Vector *v = (Vector *) malloc(sizeof(Vector));
    if (v == NULL) {
        printf("Error: Memory could not be allocated.\n");
        exit(1);
    }
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
    return v;
}

void vector_destroy(Vector *v) {
    if (v->data!= NULL) {
        free(v->data);
        v->data = NULL;
    }
    v->size = 0;
    v->capacity = 0;
}

void vector_push(Vector *v, int value) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = (int *) realloc(v->data, v->capacity * sizeof(int));
        if (v->data == NULL) {
            printf("Error: Memory could not be allocated.\n");
            exit(1);
        }
    }
    v->data[v->size++] = value;
}

int vector_pop(Vector *v) {
    if (v->size == 0) {
        printf("Error: Vector is empty.\n");
        exit(1);
    }
    return v->data[--v->size];
}

int vector_peek(Vector *v, int index) {
    if (index >= v->size || index < 0) {
        printf("Error: Index out of bounds.\n");
        exit(1);
    }
    return v->data[index];
}

int vector_size(Vector *v) {
    return v->size;
}

int main() {
    Vector *v = vector_create();
    vector_push(v, 10);
    vector_push(v, 20);
    vector_push(v, 30);
    printf("Size of vector: %d\n", vector_size(v));
    printf("Value at index 0: %d\n", vector_peek(v, 0));
    printf("Value at index -1: %d\n", vector_peek(v, -1));
    printf("Value at index 2: %d\n", vector_peek(v, 2));
    vector_pop(v);
    printf("Size of vector after pop: %d\n", vector_size(v));
    vector_destroy(v);
    return 0;
}