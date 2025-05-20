//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct {
    int *data;
    int size;
} Vector;

void vector_init(Vector *v, int size) {
    v->data = malloc(size * sizeof(int));
    v->size = size;
    for (int i = 0; i < size; i++) {
        v->data[i] = rand() % 100;
    }
}

void vector_add(Vector *v1, Vector *v2) {
    for (int i = 0; i < v1->size; i++) {
        v1->data[i] += v2->data[i];
    }
}

void vector_print(Vector *v) {
    for (int i = 0; i < v->size; i++) {
        printf("%d ", v->data[i]);
    }
    printf("\n");
}

void vector_free(Vector *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
}

int main() {
    int size = 1000000;
    Vector v1, v2;
    vector_init(&v1, size);
    vector_init(&v2, size);

    clock_t start = clock();
    for (int i = 0; i < 100; i++) {
        vector_add(&v1, &v2);
    }
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time spent: %lf seconds\n", time_spent);

    vector_print(&v1);
    vector_free(&v1);
    vector_free(&v2);

    return 0;
}