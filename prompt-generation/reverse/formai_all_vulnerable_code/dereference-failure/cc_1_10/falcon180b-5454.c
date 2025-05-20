//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: brave
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int capacity;
    int size;
} Vector;

Vector *vector_create(int capacity) {
    Vector *v = malloc(sizeof(Vector));
    v->data = malloc(capacity * sizeof(int));
    v->capacity = capacity;
    v->size = 0;
    return v;
}

void vector_destroy(Vector *v) {
    free(v->data);
    free(v);
}

void vector_push_back(Vector *v, int value) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = realloc(v->data, v->capacity * sizeof(int));
    }
    v->data[v->size++] = value;
}

int vector_size(Vector *v) {
    return v->size;
}

int vector_capacity(Vector *v) {
    return v->capacity;
}

int vector_at(Vector *v, int index) {
    if (index >= v->size) {
        printf("Index out of bounds\n");
        exit(1);
    }
    return v->data[index];
}

void vector_resize(Vector *v, int new_size) {
    if (new_size > v->size) {
        v->capacity = v->size * 2;
        v->data = realloc(v->data, v->capacity * sizeof(int));
        for (int i = v->size; i < new_size; i++) {
            v->data[i] = 0;
        }
        v->size = new_size;
    } else if (new_size < v->size) {
        v->size = new_size;
    }
}

void vector_clear(Vector *v) {
    v->size = 0;
}

void vector_print(Vector *v) {
    for (int i = 0; i < v->size; i++) {
        printf("%d ", v->data[i]);
    }
    printf("\n");
}

int main() {
    Vector *v = vector_create(10);
    vector_push_back(v, 1);
    vector_push_back(v, 2);
    vector_push_back(v, 3);
    vector_print(v);
    vector_resize(v, 5);
    vector_push_back(v, 4);
    vector_push_back(v, 5);
    vector_print(v);
    vector_destroy(v);
    return 0;
}