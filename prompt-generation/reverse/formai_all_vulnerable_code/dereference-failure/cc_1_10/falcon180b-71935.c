//Falcon-180B DATASET v1.0 Category: Memory management ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int *data;
    int size;
    int capacity;
} Vector;

Vector* create_vector() {
    Vector *v = (Vector*) malloc(sizeof(Vector));
    v->data = (int*) malloc(MAX_SIZE * sizeof(int));
    v->size = 0;
    v->capacity = MAX_SIZE;
    return v;
}

void resize_vector(Vector *v) {
    v->capacity *= 2;
    v->data = (int*) realloc(v->data, v->capacity * sizeof(int));
}

void push_back(Vector *v, int value) {
    if (v->size >= v->capacity) {
        resize_vector(v);
    }
    v->data[v->size++] = value;
}

int pop_back(Vector *v) {
    if (v->size == 0) {
        return -1;
    }
    return v->data[--v->size];
}

int main() {
    Vector *v = create_vector();

    push_back(v, 1);
    push_back(v, 2);
    push_back(v, 3);

    printf("Size: %d\n", v->size);

    int value = pop_back(v);
    printf("Popped value: %d\n", value);

    printf("Size: %d\n", v->size);

    free(v->data);
    free(v);

    return 0;
}