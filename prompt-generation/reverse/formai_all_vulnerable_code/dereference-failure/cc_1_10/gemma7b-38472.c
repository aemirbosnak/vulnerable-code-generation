//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUCKETS 10

typedef struct Bucket {
    int *arr;
    int size;
    struct Bucket *next;
} Bucket;

void insert(Bucket **buckets, int data) {
    Bucket *new_bucket = malloc(sizeof(Bucket));
    new_bucket->arr = malloc(MAX_BUCKETS * sizeof(int));
    new_bucket->size = 0;
    new_bucket->next = NULL;

    for (Bucket *bucket = *buckets; bucket; bucket = bucket->next) {
        if (bucket->size >= MAX_BUCKETS) {
            break;
        }

        if (data <= bucket->arr[bucket->size]) {
            bucket->arr[bucket->size] = data;
            bucket->size++;
            break;
        }
    }

    if (new_bucket->size == 0) {
        *buckets = new_bucket;
    } else {
        new_bucket->next = *buckets;
        *buckets = new_bucket;
    }
}

void sort(Bucket *buckets) {
    for (Bucket *bucket = buckets; bucket; bucket = bucket->next) {
        int i = 0;
        for (int data = 0; data < bucket->size; data++) {
            printf("%d ", bucket->arr[i]);
            i++;
        }
        printf("\n");
    }
}

int main() {
    Bucket *buckets = NULL;
    insert(&buckets, 5);
    insert(&buckets, 3);
    insert(&buckets, 8);
    insert(&buckets, 2);
    insert(&buckets, 4);
    insert(&buckets, 7);

    sort(buckets);

    return 0;
}