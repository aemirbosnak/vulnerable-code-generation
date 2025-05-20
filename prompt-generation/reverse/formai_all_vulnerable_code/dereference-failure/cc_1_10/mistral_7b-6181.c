//MISTRAL-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Bucket {
    int top;
    int capacity;
    int* array;
} Bucket;

void bucket_init(Bucket* buckets, int size, int bucket_size) {
    buckets->capacity = size;
    buckets->top = -1;
    buckets->array = (int*)calloc(bucket_size, sizeof(int));
}

int get_bucket_index(int value, int bucket_size) {
    return value % bucket_size;
}

void bucket_push(Bucket* bucket, int value) {
    if (bucket->top >= bucket->capacity) {
        printf("Error: Bucket is full.\n");
        return;
    }
    bucket->array[++(bucket->top)] = value;
}

void bucket_sort(int arr[], int size, int bucket_size) {
    Bucket* buckets = (Bucket*)calloc(bucket_size, sizeof(Bucket));

    for (int i = 0; i < bucket_size; i++) {
        bucket_init(&buckets[i], bucket_size, bucket_size);
    }

    for (int i = 0; i < size; i++) {
        int index = get_bucket_index(arr[i], bucket_size);
        bucket_push(&buckets[index], arr[i]);
    }

    int index = 0;
    for (int i = 0; i < bucket_size; i++) {
        while (buckets[i].top != -1) {
            arr[index++] = buckets[i].array[buckets[i].top--];
        }
    }

    free(buckets);
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    int bucket_size = 3;

    printf("Before Sorting: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucket_sort(arr, size, bucket_size);

    printf("After Sorting: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}