//Falcon-180B DATASET v1.0 Category: Sorting ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int *arr;
    int size;
    int capacity;
} Vector;

Vector* vector_create() {
    Vector *v = (Vector*)malloc(sizeof(Vector));
    v->arr = (int*)malloc(MAX_SIZE * sizeof(int));
    v->size = 0;
    v->capacity = MAX_SIZE;
    return v;
}

void vector_destroy(Vector *v) {
    free(v->arr);
    free(v);
}

void vector_push_back(Vector *v, int x) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->arr = (int*)realloc(v->arr, v->capacity * sizeof(int));
    }
    v->arr[v->size++] = x;
}

void vector_sort(Vector *v) {
    for (int i = 0; i < v->size - 1; i++) {
        for (int j = i + 1; j < v->size; j++) {
            if (v->arr[i] > v->arr[j]) {
                int temp = v->arr[i];
                v->arr[i] = v->arr[j];
                v->arr[j] = temp;
            }
        }
    }
}

void vector_print(Vector *v) {
    for (int i = 0; i < v->size; i++) {
        printf("%d ", v->arr[i]);
    }
    printf("\n");
}

int main() {
    Vector *v = vector_create();
    vector_push_back(v, 3);
    vector_push_back(v, 1);
    vector_push_back(v, 4);
    vector_push_back(v, 2);
    vector_push_back(v, 5);

    printf("Before sorting:\n");
    vector_print(v);

    vector_sort(v);

    printf("After sorting:\n");
    vector_print(v);

    vector_destroy(v);
    return 0;
}