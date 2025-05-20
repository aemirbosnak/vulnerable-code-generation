//Falcon-180B DATASET v1.0 Category: Error handling ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int* data;
    int capacity;
    int size;
} Vector;

Vector* create_vector(int capacity) {
    Vector* v = (Vector*)malloc(sizeof(Vector));
    v->data = (int*)malloc(capacity * sizeof(int));
    v->capacity = capacity;
    v->size = 0;
    return v;
}

void destroy_vector(Vector* v) {
    free(v->data);
    free(v);
}

void push_back(Vector* v, int value) {
    if (v->size >= v->capacity) {
        printf("Error: Vector is full.\n");
        exit(1);
    }
    v->data[v->size++] = value;
}

int pop_back(Vector* v) {
    if (v->size == 0) {
        printf("Error: Vector is empty.\n");
        exit(1);
    }
    return v->data[--v->size];
}

int main() {
    Vector* v = create_vector(MAX_SIZE);

    for (int i = 0; i < MAX_SIZE; i++) {
        push_back(v, i);
    }

    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%d ", pop_back(v));
    }

    destroy_vector(v);

    return 0;
}