//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000

typedef struct {
    int *data;
    int size;
    int capacity;
} Vector;

Vector *vector_create() {
    Vector *v = (Vector *)malloc(sizeof(Vector));
    v->data = (int *)malloc(MAX_SIZE * sizeof(int));
    v->size = 0;
    v->capacity = MAX_SIZE;
    return v;
}

void vector_destroy(Vector *v) {
    free(v->data);
    free(v);
}

void vector_push(Vector *v, int value) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = (int *)realloc(v->data, v->capacity * sizeof(int));
    }
    v->data[v->size++] = value;
}

int vector_pop(Vector *v) {
    if (v->size == 0) {
        return -1;
    }
    return v->data[--v->size];
}

int vector_peek(Vector *v) {
    if (v->size == 0) {
        return -1;
    }
    return v->data[v->size - 1];
}

int vector_size(Vector *v) {
    return v->size;
}

int main() {
    Vector *v = vector_create();
    vector_push(v, 10);
    vector_push(v, 20);
    vector_push(v, 30);
    vector_push(v, 40);
    vector_push(v, 50);
    printf("Size: %d\n", vector_size(v));
    printf("Peek: %d\n", vector_peek(v));
    printf("Pop: %d\n", vector_pop(v));
    printf("Peek: %d\n", vector_peek(v));
    printf("Size: %d\n", vector_size(v));
    vector_destroy(v);
    return 0;
}