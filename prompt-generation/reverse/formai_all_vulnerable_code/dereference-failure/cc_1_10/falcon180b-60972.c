//Falcon-180B DATASET v1.0 Category: Sorting ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define MAX_VAL 1000

typedef struct {
    int *arr;
    int size;
    int capacity;
} Vector;

void vector_init(Vector *v) {
    v->arr = (int *)malloc(MAX_SIZE * sizeof(int));
    v->size = 0;
    v->capacity = MAX_SIZE;
}

void vector_free(Vector *v) {
    free(v->arr);
}

void vector_resize(Vector *v) {
    v->capacity *= 2;
    v->arr = (int *)realloc(v->arr, v->capacity * sizeof(int));
}

void vector_push(Vector *v, int val) {
    if (v->size == v->capacity) {
        vector_resize(v);
    }
    v->arr[v->size++] = val;
}

int vector_pop(Vector *v) {
    if (v->size == 0) {
        return -1;
    }
    return v->arr[--v->size];
}

void vector_sort(Vector *v, int (*cmp)(const void *, const void *)) {
    qsort(v->arr, v->size, sizeof(int), cmp);
}

int cmp_int(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    srand(time(NULL));
    Vector v;
    vector_init(&v);

    for (int i = 0; i < MAX_SIZE; i++) {
        int val = rand() % MAX_VAL;
        vector_push(&v, val);
    }

    printf("Before sorting:\n");
    for (int i = 0; i < v.size; i++) {
        printf("%d ", v.arr[i]);
    }
    printf("\n");

    vector_sort(&v, cmp_int);

    printf("After sorting:\n");
    for (int i = 0; i < v.size; i++) {
        printf("%d ", v.arr[i]);
    }
    printf("\n");

    vector_free(&v);
    return 0;
}