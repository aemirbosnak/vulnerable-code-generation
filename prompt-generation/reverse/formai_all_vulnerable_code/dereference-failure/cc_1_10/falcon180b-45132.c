//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000
#define INIT_SIZE 10

typedef struct {
    int *data;
    int capacity;
    int size;
} Vector;

Vector create_vector() {
    Vector v = {
       .data = (int *)malloc(INIT_SIZE * sizeof(int)),
       .capacity = INIT_SIZE,
       .size = 0
    };
    return v;
}

void destroy_vector(Vector *v) {
    free(v->data);
    v->data = NULL;
    v->capacity = 0;
    v->size = 0;
}

void vector_push(Vector *v, int x) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = (int *)realloc(v->data, v->capacity * sizeof(int));
    }
    v->data[v->size++] = x;
}

int vector_pop(Vector *v) {
    if (v->size == 0) {
        printf("Vector is empty!\n");
        return -1;
    }
    return v->data[--v->size];
}

int vector_peek(Vector *v) {
    if (v->size == 0) {
        printf("Vector is empty!\n");
        return -1;
    }
    return v->data[v->size - 1];
}

int vector_size(Vector *v) {
    return v->size;
}

int vector_capacity(Vector *v) {
    return v->capacity;
}

int main() {
    Vector v = create_vector();

    for (int i = 0; i < 20; i++) {
        vector_push(&v, i);
    }

    printf("Size: %d\n", vector_size(&v));
    printf("Capacity: %d\n", vector_capacity(&v));

    for (int i = 0; i < 10; i++) {
        printf("%d ", vector_peek(&v));
    }
    printf("\n");

    for (int i = 0; i < 20; i++) {
        printf("%d ", vector_pop(&v));
    }
    printf("\n");

    destroy_vector(&v);
    return 0;
}