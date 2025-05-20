//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 10000
#define RANGE 1000000

void generate_array(int *arr, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % RANGE;
    }
}

void bucket_sort(int *arr, int size) {
    int *bucket = malloc(MAX_SIZE * sizeof(int));
    int num_buckets = RANGE / (RANGE / MAX_SIZE);

    for (int i = 0; i < num_buckets; i++) {
        bucket[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        int bucket_idx = arr[i] / (RANGE / MAX_SIZE);
        bucket[bucket_idx]++;
    }

    for (int i = 1; i < num_buckets; i++) {
        bucket[i] += bucket[i - 1];
    }

    int *sorted_arr = malloc(size * sizeof(int));
    int sorted_idx = 0;

    for (int i = size - 1; i >= 0; i--) {
        int bucket_idx = arr[i] / (RANGE / MAX_SIZE);
        sorted_arr[sorted_idx++] = arr[--bucket[bucket_idx]];
    }

    free(bucket);
    memcpy(arr, sorted_arr, size * sizeof(int));
    free(sorted_arr);
}

int main() {
    int size = MAX_SIZE;
    int *arr = malloc(size * sizeof(int));

    generate_array(arr, size);

    printf("Before Sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    bucket_sort(arr, size);

    printf("\nAfter Sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}