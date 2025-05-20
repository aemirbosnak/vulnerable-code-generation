//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    int value;
} bucket_t;

void create_bucket(bucket_t *bucket, int size) {
    bucket->key = malloc(size * sizeof(char));
    bucket->value = 0;
}

void destroy_bucket(bucket_t *bucket) {
    free(bucket->key);
}

void insert_bucket(bucket_t *bucket, int value) {
    bucket->value = value;
}

int compare_bucket(bucket_t *a, bucket_t *b) {
    return strcmp(a->key, b->key);
}

void sort_bucket(bucket_t *bucket, int num_buckets) {
    int i, j;
    bucket_t temp;

    for (i = 0; i < num_buckets - 1; i++) {
        for (j = i + 1; j < num_buckets; j++) {
            if (compare_bucket(bucket + i, bucket + j) > 0) {
                temp = bucket[i];
                bucket[i] = bucket[j];
                bucket[j] = temp;
            }
        }
    }
}

int main() {
    int num_buckets = 10;
    bucket_t *bucket = malloc(num_buckets * sizeof(bucket_t));

    int i;
    for (i = 0; i < num_buckets; i++) {
        create_bucket(bucket + i, 10);
    }

    int num_elements = 100;
    int values[num_elements];

    for (i = 0; i < num_elements; i++) {
        values[i] = rand() % num_buckets;
    }

    for (i = 0; i < num_elements; i++) {
        insert_bucket(bucket + values[i], i);
    }

    sort_bucket(bucket, num_buckets);

    for (i = 0; i < num_buckets; i++) {
        printf("Bucket %d: %s\n", i, bucket[i].key);
    }

    for (i = 0; i < num_elements; i++) {
        printf("Element %d: %d\n", i, values[i]);
    }

    for (i = 0; i < num_buckets; i++) {
        destroy_bucket(bucket + i);
    }

    free(bucket);

    return 0;
}