//Falcon-180B DATASET v1.0 Category: Memory management ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int *data;
    int size;
    int capacity;
} Vector;

void vector_init(Vector *v) {
    v->data = (int *)malloc(MAX_SIZE * sizeof(int));
    v->size = 0;
    v->capacity = MAX_SIZE;
}

void vector_push(Vector *v, int val) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = (int *)realloc(v->data, v->capacity * sizeof(int));
    }
    v->data[v->size++] = val;
}

int vector_pop(Vector *v) {
    if (v->size == 0) {
        return -1;
    }
    int val = v->data[--v->size];
    if (v->size < v->capacity / 4) {
        v->capacity /= 2;
        v->data = (int *)realloc(v->data, v->capacity * sizeof(int));
    }
    return val;
}

void vector_destroy(Vector *v) {
    free(v->data);
}

int main() {
    Vector v;
    vector_init(&v);

    for (int i = 0; i < 100; i++) {
        vector_push(&v, i);
    }

    for (int i = 0; i < 50; i++) {
        int val = vector_pop(&v);
        printf("%d ", val);
    }

    vector_destroy(&v);

    return 0;
}