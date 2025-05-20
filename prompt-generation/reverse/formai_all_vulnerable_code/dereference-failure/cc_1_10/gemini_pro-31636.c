//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

typedef struct bucket {
    int min;
    int max;
    int count;
    int *array;
} bucket;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert_into_bucket(bucket *buckets, int num, int num_buckets) {
    int bucket_index = num / num_buckets;
    if (buckets[bucket_index].count == 0) {
        buckets[bucket_index].min = num;
        buckets[bucket_index].max = num;
    } else {
        if (num < buckets[bucket_index].min) {
            buckets[bucket_index].min = num;
        } else if (num > buckets[bucket_index].max) {
            buckets[bucket_index].max = num;
        }
    }
    buckets[bucket_index].array[buckets[bucket_index].count] = num;
    buckets[bucket_index].count++;
}

void sort_bucket(bucket *bucket) {
    for (int i = 0; i < bucket->count - 1; i++) {
        for (int j = 0; j < bucket->count - i - 1; j++) {
            if (bucket->array[j] > bucket->array[j + 1]) {
                swap(&bucket->array[j], &bucket->array[j + 1]);
            }
        }
    }
}

void bucket_sort(int *array, int size, int num_buckets) {
    bucket *buckets = malloc(sizeof(bucket) * num_buckets);
    for (int i = 0; i < num_buckets; i++) {
        buckets[i].min = 0;
        buckets[i].max = 0;
        buckets[i].count = 0;
        buckets[i].array = malloc(sizeof(int) * size);
    }
    for (int i = 0; i < size; i++) {
        insert_into_bucket(buckets, array[i], num_buckets);
    }
    for (int i = 0; i < num_buckets; i++) {
        sort_bucket(&buckets[i]);
    }
    int index = 0;
    for (int i = 0; i < num_buckets; i++) {
        for (int j = 0; j < buckets[i].count; j++) {
            array[index] = buckets[i].array[j];
            index++;
        }
    }
    for (int i = 0; i < num_buckets; i++) {
        free(buckets[i].array);
    }
    free(buckets);
}

int main() {
    int array[] = {5, 3, 1, 7, 4, 1, 2, 8, 6};
    int size = sizeof(array) / sizeof(array[0]);
    int num_buckets = 5;
    bucket_sort(array, size, num_buckets);
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}