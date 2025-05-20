//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 10000
#define MIN_SIZE 100

typedef struct {
    int size;
    int *arr;
} Vector;

Vector *create_vector(int size) {
    Vector *v = (Vector *)malloc(sizeof(Vector));
    v->size = size;
    v->arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        v->arr[i] = rand() % 100;
    }
    return v;
}

void print_vector(Vector *v) {
    for (int i = 0; i < v->size; i++) {
        printf("%d ", v->arr[i]);
    }
    printf("\n");
}

void destroy_vector(Vector *v) {
    free(v->arr);
    free(v);
}

int main() {
    srand(time(NULL));
    Vector *v1 = create_vector(MAX_SIZE);
    Vector *v2 = create_vector(MIN_SIZE);
    print_vector(v1);
    print_vector(v2);
    int sum = 0;
    for (int i = 0; i < MIN_SIZE; i++) {
        sum += v1->arr[i] + v2->arr[i];
    }
    printf("Sum: %d\n", sum);
    destroy_vector(v1);
    destroy_vector(v2);
    return 0;
}