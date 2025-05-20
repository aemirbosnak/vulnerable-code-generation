//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: safe
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 100

typedef struct bucket {
    int *array;
    int size;
    int capacity;
} bucket_t;

typedef struct bucket_list {
    bucket_t *buckets;
    int num_buckets;
} bucket_list_t;

bucket_t *create_bucket(int capacity) {
    bucket_t *bucket = (bucket_t *)malloc(sizeof(bucket_t));
    bucket->array = (int *)malloc(sizeof(int) * capacity);
    bucket->size = 0;
    bucket->capacity = capacity;
    return bucket;
}

void destroy_bucket(bucket_t *bucket) {
    free(bucket->array);
    free(bucket);
}

bucket_list_t *create_bucket_list(int num_buckets) {
    bucket_list_t *bucket_list = (bucket_list_t *)malloc(sizeof(bucket_list_t));
    bucket_list->buckets = (bucket_t *)malloc(sizeof(bucket_t) * num_buckets);
    bucket_list->num_buckets = num_buckets;
    for (int i = 0; i < num_buckets; i++) {
        bucket_list->buckets[i] = *create_bucket(MAX_SIZE);
    }
    return bucket_list;
}

void destroy_bucket_list(bucket_list_t *bucket_list) {
    for (int i = 0; i < bucket_list->num_buckets; i++) {
        destroy_bucket(&bucket_list->buckets[i]);
    }
    free(bucket_list->buckets);
    free(bucket_list);
}

void insert_into_bucket(bucket_list_t *bucket_list, int value) {
    int bucket_index = value / bucket_list->num_buckets;
    bucket_t *bucket = &bucket_list->buckets[bucket_index];
    if (bucket->size >= bucket->capacity) {
        bucket->array = (int *)realloc(bucket->array, sizeof(int) * bucket->capacity * 2);
        bucket->capacity *= 2;
    }
    bucket->array[bucket->size++] = value;
}

void sort_bucket(bucket_t *bucket) {
    for (int i = 0; i < bucket->size - 1; i++) {
        for (int j = 0; j < bucket->size - i - 1; j++) {
            if (bucket->array[j] > bucket->array[j + 1]) {
                int temp = bucket->array[j];
                bucket->array[j] = bucket->array[j + 1];
                bucket->array[j + 1] = temp;
            }
        }
    }
}

void sort_bucket_list(bucket_list_t *bucket_list) {
    for (int i = 0; i < bucket_list->num_buckets; i++) {
        sort_bucket(&bucket_list->buckets[i]);
    }
}

void merge_buckets(int *array, bucket_list_t *bucket_list) {
    int index = 0;
    for (int i = 0; i < bucket_list->num_buckets; i++) {
        bucket_t *bucket = &bucket_list->buckets[i];
        for (int j = 0; j < bucket->size; j++) {
            array[index++] = bucket->array[j];
        }
    }
}

void bucket_sort(int *array, int size, int num_buckets) {
    bucket_list_t *bucket_list = create_bucket_list(num_buckets);
    for (int i = 0; i < size; i++) {
        insert_into_bucket(bucket_list, array[i]);
    }
    sort_bucket_list(bucket_list);
    merge_buckets(array, bucket_list);
    destroy_bucket_list(bucket_list);
}

int main() {
    int array[] = {5, 3, 1, 7, 4, 1, 2, 8, 6};
    int size = sizeof(array) / sizeof(array[0]);
    int num_buckets = 3;
    bucket_sort(array, size, num_buckets);
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}