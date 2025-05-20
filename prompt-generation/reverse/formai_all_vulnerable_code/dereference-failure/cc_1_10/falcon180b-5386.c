//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUCKET_SIZE 10
#define MAX_VALUE 100

typedef struct {
    int *data;
    int size;
    int capacity;
} Bucket;

void init_bucket(Bucket *b) {
    b->data = (int *)malloc(BUCKET_SIZE * sizeof(int));
    b->size = 0;
    b->capacity = BUCKET_SIZE;
}

void free_bucket(Bucket *b) {
    free(b->data);
}

void resize_bucket(Bucket *b) {
    b->capacity *= 2;
    b->data = (int *)realloc(b->data, b->capacity * sizeof(int));
}

void insert_bucket(Bucket *b, int value) {
    if (b->size == b->capacity) {
        resize_bucket(b);
    }

    b->data[b->size++] = value;
}

void sort_bucket(Bucket *b, int (*compare)(const void *, const void *)) {
    qsort(b->data, b->size, sizeof(int), compare);
}

int cmp_int(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    srand(time(NULL));

    int num_elements = rand() % MAX_VALUE + 1;
    int *data = (int *)malloc(num_elements * sizeof(int));

    for (int i = 0; i < num_elements; i++) {
        data[i] = rand() % MAX_VALUE;
    }

    printf("Original data:\n");
    for (int i = 0; i < num_elements; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    Bucket bucket;
    init_bucket(&bucket);

    for (int i = 0; i < num_elements; i++) {
        insert_bucket(&bucket, data[i]);
    }

    printf("Data in bucket:\n");
    for (int i = 0; i < bucket.size; i++) {
        printf("%d ", bucket.data[i]);
    }
    printf("\n");

    sort_bucket(&bucket, cmp_int);

    printf("Sorted data:\n");
    for (int i = 0; i < bucket.size; i++) {
        printf("%d ", bucket.data[i]);
    }
    printf("\n");

    free_bucket(&bucket);
    free(data);

    return 0;
}