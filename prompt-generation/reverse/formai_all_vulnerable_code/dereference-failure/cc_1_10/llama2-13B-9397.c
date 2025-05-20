//LLAMA2-13B DATASET v1.0 Category: Benchmarking ; Style: careful
#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define N 100000
#define M 1000

struct point {
    int x;
    int y;
};

struct vector {
    int size;
    int capacity;
    struct point *data;
};

void init_vector(struct vector *v) {
    v->size = 0;
    v->capacity = M;
    v->data = malloc(M * sizeof(struct point));
}

void push_back_vector(struct vector *v, int x, int y) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = realloc(v->data, v->capacity * sizeof(struct point));
    }
    v->data[v->size++] = (struct point) {x, y};
}

void print_vector(struct vector *v) {
    printf("Vector: ");
    for (int i = 0; i < v->size; i++) {
        printf("%d, %d ", v->data[i].x, v->data[i].y);
    }
    printf("\n");
}

void benchmark_vector(struct vector *v) {
    for (int i = 0; i < N; i++) {
        push_back_vector(v, i % 10, i / 10);
    }
    print_vector(v);
}

int main() {
    struct vector v;
    init_vector(&v);

    benchmark_vector(&v);

    return 0;
}