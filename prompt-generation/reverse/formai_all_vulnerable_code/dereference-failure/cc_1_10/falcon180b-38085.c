//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int *data;
    int capacity;
    int size;
} Vector;

void vector_init(Vector *vec, int capacity) {
    vec->data = malloc(capacity * sizeof(int));
    vec->capacity = capacity;
    vec->size = 0;
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
    return vec->data[--vec->size];
}

void vector_free(Vector *vec) {
    free(vec->data);
}

int main() {
    srand(time(0));

    Vector vec;
    vector_init(&vec, 10);

    for (int i = 0; i < 1000000; i++) {
        int choice = rand() % 3;
        if (choice == 0) {
            int value = rand() % 100;
            vector_push(&vec, value);
        } else if (choice == 1) {
            int value = vector_pop(&vec);
            if (value!= -1) {
                printf("%d\n", value);
            }
        } else {
            int value = rand() % vec.size;
            int pos = rand() % vec.size;
            vector_push(&vec, vector_pop(&vec));
            vector_push(&vec, value);
            vector_push(&vec, vector_pop(&vec));
            vector_push(&vec, vector_pop(&vec));
            vector_push(&vec, value);
            vector_push(&vec, vector_pop(&vec));
        }
    }

    vector_free(&vec);

    return 0;
}