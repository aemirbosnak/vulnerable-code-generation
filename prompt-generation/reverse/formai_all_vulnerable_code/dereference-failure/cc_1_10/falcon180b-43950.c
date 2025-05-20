//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

int bucket_sort(int arr[], int size) {
    int i, j, max_val, min_val, range, bucket_size, num_buckets;
    int *buckets[MAX_SIZE];

    max_val = arr[0];
    min_val = arr[0];

    for (i = 1; i < size; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }

    range = max_val - min_val + 1;
    bucket_size = range / size;
    num_buckets = size;

    for (i = 0; i < num_buckets; i++) {
        buckets[i] = (int *) malloc(bucket_size * sizeof(int));
    }

    for (i = 0; i < size; i++) {
        j = (arr[i] - min_val) / bucket_size;
        buckets[j][(arr[i] - min_val) % bucket_size] = arr[i];
    }

    for (i = 0; i < size; i++) {
        arr[i] = buckets[i % num_buckets][i];
    }

    for (i = 0; i < num_buckets; i++) {
        free(buckets[i]);
    }

    return 0;
}

int main() {
    int size, i, j, sum;

    srand(time(NULL));
    size = rand() % MAX_SIZE + 1;

    int arr[MAX_SIZE];

    for (i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }

    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucket_sort(arr, size);

    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    sum = 0;
    for (i = 0; i < size; i++) {
        sum += arr[i];
    }

    printf("Sum: %d\n", sum);

    return 0;
}