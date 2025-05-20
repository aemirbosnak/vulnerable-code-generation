//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdint.h>

#define MAX_SIZE 1000000

typedef struct {
    int *data;
    int size;
    int capacity;
} Vector;

Vector create_vector(int size) {
    Vector v;
    v.data = (int *)malloc(size * sizeof(int));
    v.size = 0;
    v.capacity = size;
    return v;
}

void destroy_vector(Vector *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

void push_back(Vector *v, int value) {
    if (v->size >= v->capacity) {
        v->capacity *= 2;
        v->data = (int *)realloc(v->data, v->capacity * sizeof(int));
    }
    v->data[v->size++] = value;
}

int pop_back(Vector *v) {
    if (v->size == 0) {
        return -1;
    }
    return v->data[--v->size];
}

void print_vector(Vector v) {
    for (int i = 0; i < v.size; i++) {
        printf("%d ", v.data[i]);
    }
    printf("\n");
}

int main() {
    Vector v1 = create_vector(MAX_SIZE);
    Vector v2 = create_vector(MAX_SIZE);

    srand(time(NULL));

    for (int i = 0; i < MAX_SIZE; i++) {
        int value = rand() % 100;
        push_back(&v1, value);
        push_back(&v2, value);
    }

    printf("Vector 1:\n");
    print_vector(v1);

    printf("Vector 2:\n");
    print_vector(v2);

    int index = rand() % v1.size;
    int value = pop_back(&v1);

    printf("Popped value from Vector 1: %d\n", value);

    for (int i = 0; i < v1.size; i++) {
        v1.data[i] = v1.data[i] * 2;
    }

    printf("Multiplied Vector 1 by 2:\n");
    print_vector(v1);

    destroy_vector(&v1);
    destroy_vector(&v2);

    return 0;
}