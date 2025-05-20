//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int *arr;
    int size;
} Bucket;

void init_bucket(Bucket *b, int size) {
    b->arr = (int *)malloc(size * sizeof(int));
    b->size = size;
}

void free_bucket(Bucket *b) {
    free(b->arr);
}

void insert_into_bucket(Bucket *b, int val) {
    int i = 0;
    while (i < b->size && val >= b->arr[i]) {
        i++;
    }
    for (int j = b->size - 1; j >= i; j--) {
        b->arr[j] = b->arr[j - 1];
    }
    b->arr[i] = val;
}

void sort_bucket(Bucket *b) {
    for (int i = 0; i < b->size - 1; i++) {
        for (int j = 0; j < b->size - i - 1; j++) {
            if (b->arr[j] > b->arr[j + 1]) {
                int temp = b->arr[j];
                b->arr[j] = b->arr[j + 1];
                b->arr[j + 1] = temp;
            }
        }
    }
}

void bucket_sort(int *arr, int size) {
    int max_val = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    int bucket_size = max_val / size;
    Bucket *buckets = (Bucket *)malloc(bucket_size * sizeof(Bucket));

    for (int i = 0; i < bucket_size; i++) {
        init_bucket(&buckets[i], size);
    }

    for (int i = 0; i < size; i++) {
        insert_into_bucket(&buckets[arr[i] / bucket_size], arr[i]);
    }

    for (int i = 0; i < bucket_size; i++) {
        sort_bucket(&buckets[i]);
    }

    int index = 0;
    for (int i = 0; i < bucket_size; i++) {
        for (int j = 0; j < buckets[i].size; j++) {
            arr[index++] = buckets[i].arr[j];
        }
    }

    for (int i = 0; i < bucket_size; i++) {
        free_bucket(&buckets[i]);
    }
    free(buckets);
}

int main() {
    int arr[] = { 5, 7, 2, 9, 1, 8, 4, 6, 3 };
    int size = sizeof(arr) / sizeof(arr[0]);

    bucket_sort(arr, size);

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}