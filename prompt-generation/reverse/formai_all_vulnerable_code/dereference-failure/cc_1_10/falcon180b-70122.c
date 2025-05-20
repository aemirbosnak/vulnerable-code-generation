//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int *data;
    int size;
    int capacity;
} Vector;

void vector_init(Vector *v, int capacity) {
    v->data = (int *)malloc(capacity * sizeof(int));
    v->size = 0;
    v->capacity = capacity;
}

void vector_push(Vector *v, int value) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = (int *)realloc(v->data, v->capacity * sizeof(int));
    }
    v->data[v->size++] = value;
}

void vector_destroy(Vector *v) {
    free(v->data);
}

void bucket_sort(Vector *v) {
    int i, j, n = v->size;
    Vector *buckets = (Vector *)malloc(n * sizeof(Vector));
    for (i = 0; i < n; i++) {
        vector_init(&buckets[i], 1);
    }
    for (i = 0; i < n; i++) {
        int value = v->data[i];
        int bucket_index = value * n / MAX_SIZE;
        vector_push(&buckets[bucket_index], value);
    }
    i = 0;
    for (j = 0; j < n; j++) {
        while (buckets[j].size > 0) {
            v->data[i++] = buckets[j].data[--buckets[j].size];
        }
    }
    for (j = 0; j < n; j++) {
        vector_destroy(&buckets[j]);
    }
    free(buckets);
}

int main() {
    Vector v;
    int i, n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    vector_init(&v, n);
    for (i = 0; i < n; i++) {
        int value;
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        vector_push(&v, value);
    }
    bucket_sort(&v);
    printf("Sorted array: ");
    for (i = 0; i < v.size; i++) {
        printf("%d ", v.data[i]);
    }
    printf("\n");
    vector_destroy(&v);
    return 0;
}