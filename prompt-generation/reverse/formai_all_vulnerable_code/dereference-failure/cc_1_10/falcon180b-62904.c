//Falcon-180B DATASET v1.0 Category: Sorting ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

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

void vector_push_back(Vector *v, int value) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = (int *)realloc(v->data, v->capacity * sizeof(int));
    }
    v->data[v->size++] = value;
}

int vector_pop_back(Vector *v) {
    if (v->size == 0) {
        return -1;
    }
    return v->data[--v->size];
}

void vector_sort(Vector *v, int (*compare)(const void *, const void *)) {
    qsort(v->data, v->size, sizeof(int), compare);
}

int compare_int(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void print_vector(Vector *v) {
    for (int i = 0; i < v->size; i++) {
        printf("%d ", v->data[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    Vector *v = create_vector(MAX_SIZE);

    for (int i = 0; i < 100; i++) {
        int value = rand() % 1000;
        vector_push_back(v, value);
    }

    printf("Before sorting:\n");
    print_vector(v);

    vector_sort(v, compare_int);

    printf("After sorting:\n");
    print_vector(v);

    destroy_vector(v);

    return 0;
}