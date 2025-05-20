//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>

typedef struct bucket {
    int* elements;
    int capacity;
    int size;
} Bucket;

Bucket* create_bucket(int bucket_size) {
    Bucket* new_bucket = (Bucket*) malloc(sizeof(Bucket));
    new_bucket->capacity = 0;
    new_bucket->size = 0;
    new_bucket->elements = (int*) malloc(bucket_size * sizeof(int));
    return new_bucket;
}

void insert(Bucket* bucket, int element) {
    int i;
    i = bucket->capacity * bucket->size + (element % bucket->size);
    if (i < bucket->capacity) {
        bucket->elements[i] = element;
        bucket->size++;
    } else {
        Bucket* new_bucket = create_bucket(bucket->size);
        for (i = 0; i < bucket->capacity; i++) {
            new_bucket->elements[i] = bucket->elements[i];
        }
        for (i = bucket->capacity; i < bucket->size; i++) {
            new_bucket->elements[i] = element;
        }
        new_bucket->size = bucket->size;
        free(bucket->elements);
        bucket->elements = new_bucket->elements;
        bucket->capacity = new_bucket->capacity;
        bucket->size = new_bucket->size;
    }
}

Bucket* merge(Bucket* a, Bucket* b) {
    Bucket* new_bucket = create_bucket(a->capacity + b->capacity);
    new_bucket->size = a->size + b->size;
    for (int i = 0; i < a->capacity; i++) {
        new_bucket->elements[i] = a->elements[i];
    }
    for (int i = 0; i < b->capacity; i++) {
        new_bucket->elements[i + a->capacity] = b->elements[i];
    }
    free(a->elements);
    free(b->elements);
    a->elements = new_bucket->elements;
    a->capacity = new_bucket->capacity;
    a->size = new_bucket->size;
    b->elements = NULL;
    b->capacity = 0;
    b->size = 0;
    return a;
}

void print_bucket(Bucket* bucket) {
    printf("[");
    for (int i = 0; i < bucket->size; i++) {
        printf("%d", bucket->elements[i]);
        if (i!= bucket->size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void bucket_sort(int* array, int array_size, int bucket_size) {
    Bucket* buckets[32];
    for (int i = 0; i < 32; i++) {
        buckets[i] = create_bucket(bucket_size);
    }
    for (int i = 0; i < array_size; i++) {
        insert(buckets[array[i] % 32], array[i]);
    }
    for (int i = 0; i < 32; i++) {
        merge(buckets[i], buckets[i + 1]);
    }
    for (int i = 0; i < 32; i++) {
        print_bucket(buckets[i]);
    }
}

int main() {
    int array[] = {4, 1, 3, 2, 5, 6, 7, 8, 9, 10};
    int array_size = sizeof(array) / sizeof(array[0]);
    bucket_sort(array, array_size, 4);
    return 0;
}