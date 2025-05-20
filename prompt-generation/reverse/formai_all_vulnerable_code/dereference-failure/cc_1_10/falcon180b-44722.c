//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} Vector;

void vector_init(Vector *vec) {
    vec->data = NULL;
    vec->size = 0;
    vec->capacity = 0;
}

void vector_push(Vector *vec, int value) {
    if (vec->size == vec->capacity) {
        vec->capacity *= 2;
        vec->data = realloc(vec->data, vec->capacity * sizeof(int));
    }
    vec->data[vec->size++] = value;
}

int vector_pop(Vector *vec) {
    if (vec->size == 0) {
        return -1;
    }
    int value = vec->data[--vec->size];
    if (vec->size < vec->capacity / 4) {
        vec->capacity /= 2;
        vec->data = realloc(vec->data, vec->capacity * sizeof(int));
    }
    return value;
}

int vector_get(Vector *vec, int index) {
    if (index < 0 || index >= vec->size) {
        return -1;
    }
    return vec->data[index];
}

void vector_free(Vector *vec) {
    if (vec->data!= NULL) {
        free(vec->data);
        vec->data = NULL;
        vec->size = 0;
        vec->capacity = 0;
    }
}

int main() {
    Vector vec;
    vector_init(&vec);

    for (int i = 0; i < 10; i++) {
        vector_push(&vec, i * 2);
    }

    for (int i = 0; i < 5; i++) {
        printf("%d ", vector_get(&vec, i));
    }

    for (int i = 0; i < 5; i++) {
        printf("%d ", vector_pop(&vec));
    }

    vector_free(&vec);

    return 0;
}