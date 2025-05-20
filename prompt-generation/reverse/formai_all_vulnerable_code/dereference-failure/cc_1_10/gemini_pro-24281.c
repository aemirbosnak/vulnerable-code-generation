//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

struct Bucket {
    int count;
    int *values;
};

void bucket_sort(int *arr, int len) {
    int max_value = arr[0];
    for (int i = 1; i < len; i++) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
    }

    int num_buckets = max_value + 1;
    struct Bucket *buckets = malloc(sizeof(struct Bucket) * num_buckets);

    for (int i = 0; i < num_buckets; i++) {
        buckets[i].count = 0;
        buckets[i].values = malloc(sizeof(int) * len);
    }

    for (int i = 0; i < len; i++) {
        int bucket_index = arr[i];
        buckets[bucket_index].values[buckets[bucket_index].count] = arr[i];
        buckets[bucket_index].count++;
    }

    int sorted_index = 0;
    for (int i = 0; i < num_buckets; i++) {
        for (int j = 0; j < buckets[i].count; j++) {
            arr[sorted_index] = buckets[i].values[j];
            sorted_index++;
        }
    }

    for (int i = 0; i < num_buckets; i++) {
        free(buckets[i].values);
    }
    free(buckets);
}

int main() {
    int arr[] = {5, 3, 1, 7, 4, 1, 2, 8, 6};
    int len = sizeof(arr) / sizeof(arr[0]);

    bucket_sort(arr, len);

    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}