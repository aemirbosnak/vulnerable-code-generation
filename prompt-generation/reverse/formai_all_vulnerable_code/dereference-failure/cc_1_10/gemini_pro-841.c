//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: standalone
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>

typedef struct {
    int *arr;
    int *count;
    int size;
} bucket;

void init_bucket(bucket *b, int n) {
    b->arr = (int *)malloc(n * sizeof(int));
    b->count = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        b->count[i] = 0;
    }
    b->size = n;
}

void free_bucket(bucket *b) {
    free(b->arr);
    free(b->count);
}

void bucket_sort(int *arr, int n, int max_val) {
    // Create a bucket for each possible value
    int num_buckets = (int)ceil((double)max_val / (double)n);
    bucket *buckets = (bucket *)malloc(num_buckets * sizeof(bucket));
    for (int i = 0; i < num_buckets; i++) {
        init_bucket(&buckets[i], n);
    }

    // Count the occurrences of each value
    for (int i = 0; i < n; i++) {
        int bucket_index = arr[i] / num_buckets;
        buckets[bucket_index].count[arr[i] % num_buckets]++;
    }

    // Store the occurrences in the array
    int index = 0;
    for (int i = 0; i < num_buckets; i++) {
        for (int j = 0; j < buckets[i].size; j++) {
            for (int k = 0; k < buckets[i].count[j]; k++) {
                arr[index++] = i * num_buckets + j;
            }
        }
        free_bucket(&buckets[i]);
    }
    free(buckets);
}

int main() {
    // Generate a random array
    int n = 100;
    int max_val = 1000;
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % max_val;
    }

    // Sort the array using bucket sort
    bucket_sort(arr, n, max_val);

    // Check if the array is sorted
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            printf("The array is not sorted!\n");
            return 1;
        }
    }

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}