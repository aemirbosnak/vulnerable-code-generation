//Falcon-180B DATASET v1.0 Category: Educational ; Style: Claude Shannon
#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    int *data;
    int size;
    int capacity;
} Vector;

Vector *create_vector(int capacity) {
    Vector *v = (Vector *)malloc(sizeof(Vector));
    v->data = (int *)malloc(capacity * sizeof(int));
    v->size = 0;
    v->capacity = capacity;
    return v;
}

void destroy_vector(Vector *v) {
    free(v->data);
    free(v);
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

int main() {
    Vector *v = create_vector(10);
    push_back(v, 1);
    push_back(v, 2);
    push_back(v, 3);
    push_back(v, 4);
    push_back(v, 5);
    push_back(v, 6);
    push_back(v, 7);
    push_back(v, 8);
    push_back(v, 9);
    push_back(v, 10);

    int sum = 0;
    for (int i = 0; i < v->size; i++) {
        sum += v->data[i];
    }

    printf("Sum: %d\n", sum);

    destroy_vector(v);
    return 0;
}