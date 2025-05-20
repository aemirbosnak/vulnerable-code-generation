//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int *array;
    int size;
} Bucket;

void create_bucket(Bucket *bucket, int size) {
    bucket->array = (int *)malloc(size * sizeof(int));
    bucket->size = size;
}

void destroy_bucket(Bucket *bucket) {
    free(bucket->array);
}

void insert_element(Bucket *bucket, int element) {
    if (bucket->size == 0) {
        create_bucket(bucket, 1);
    } else if (bucket->size == MAX_SIZE) {
        printf("Bucket is full!\n");
        exit(1);
    } else {
        bucket->array[bucket->size] = element;
        bucket->size++;
    }
}

void sort_bucket(Bucket *bucket) {
    int i, j;
    int temp;

    for (i = 0; i < bucket->size - 1; i++) {
        for (j = 0; j < bucket->size - i - 1; j++) {
            if (bucket->array[j] > bucket->array[j + 1]) {
                temp = bucket->array[j];
                bucket->array[j] = bucket->array[j + 1];
                bucket->array[j + 1] = temp;
            }
        }
    }
}

void print_bucket(Bucket *bucket) {
    int i;

    for (i = 0; i < bucket->size; i++) {
        printf("%d ", bucket->array[i]);
    }
}

int main() {
    Bucket bucket;
    int element, i;

    create_bucket(&bucket, 0);

    for (i = 0; i < 10; i++) {
        element = rand() % 100;
        insert_element(&bucket, element);
    }

    sort_bucket(&bucket);

    printf("Sorted bucket: ");
    print_bucket(&bucket);

    destroy_bucket(&bucket);

    return 0;
}