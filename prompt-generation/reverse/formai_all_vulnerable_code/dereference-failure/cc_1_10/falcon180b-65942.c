//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct {
    int *data;
    int size;
    int capacity;
} Vector;

Vector *create_vector() {
    Vector *v = (Vector *)malloc(sizeof(Vector));
    v->data = (int *)malloc(MAX_SIZE * sizeof(int));
    v->size = 0;
    v->capacity = MAX_SIZE;
    return v;
}

void destroy_vector(Vector *v) {
    free(v->data);
    free(v);
}

void push_back(Vector *v, int x) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = (int *)realloc(v->data, v->capacity * sizeof(int));
    }
    v->data[v->size++] = x;
}

int pop_back(Vector *v) {
    if (v->size == 0) {
        return -1;
    }
    return v->data[--v->size];
}

int main() {
    srand(time(NULL));

    Vector *v = create_vector();

    for (int i = 0; i < 10; i++) {
        push_back(v, rand() % 100);
    }

    printf("Vector: ");
    for (int i = 0; i < v->size; i++) {
        printf("%d ", v->data[i]);
    }
    printf("\n");

    for (int i = 0; i < 5; i++) {
        int x = pop_back(v);
        printf("Popped: %d\n", x);
    }

    destroy_vector(v);

    return 0;
}