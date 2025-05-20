//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} Vector;

void vector_init(Vector *vec) {
    vec->data = NULL;
    vec->size = 0;
    vec->capacity = 0;
}

void vector_destroy(Vector *vec) {
    if (vec->data) {
        free(vec->data);
        vec->data = NULL;
    }
    vec->size = 0;
    vec->capacity = 0;
}

void vector_push_back(Vector *vec, int val) {
    if (vec->size == vec->capacity) {
        vec->capacity *= 2;
        vec->data = realloc(vec->data, sizeof(int) * vec->capacity);
    }
    vec->data[vec->size++] = val;
}

void vector_pop_back(Vector *vec) {
    if (vec->size > 0) {
        vec->size--;
    }
}

void vector_print(Vector *vec) {
    for (size_t i = 0; i < vec->size; i++) {
        printf("%d ", vec->data[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    Vector vec;
    vector_init(&vec);

    for (int i = 0; i < 100000; i++) {
        int val = rand() % 100;
        vector_push_back(&vec, val);
    }

    for (int i = 0; i < 100000; i++) {
        vector_pop_back(&vec);
    }

    vector_print(&vec);

    vector_destroy(&vec);

    return 0;
}