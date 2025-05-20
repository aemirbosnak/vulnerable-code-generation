//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: genius
#include <stdio.h>
#include <stdlib.h>

#define NUM_BUCKETS 10

// Create an array of empty buckets
int* create_buckets(int num_buckets) {
    int* buckets = (int*)malloc(sizeof(int) * num_buckets);
    for (int i = 0; i < num_buckets; i++) {
        buckets[i] = 0;
    }
    return buckets;
}

// Insert an element into a bucket
void insert_into_bucket(int* buckets, int element) {
    buckets[element]++;
}

// Sort the elements in the buckets
void sort_buckets(int* buckets, int num_buckets) {
    for (int i = 0; i < num_buckets; i++) {
        for (int j = 0; j < buckets[i]; j++) {
            printf("%d ", i);
        }
    }
}

// Free the memory allocated for the buckets
void free_buckets(int* buckets) {
    free(buckets);
}

int main() {
    // Get the input array
    int arr[] = {3, 1, 4, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Create the buckets
    int* buckets = create_buckets(NUM_BUCKETS);

    // Insert the elements into the buckets
    for (int i = 0; i < n; i++) {
        insert_into_bucket(buckets, arr[i]);
    }

    // Sort the elements in the buckets
    sort_buckets(buckets, NUM_BUCKETS);

    // Free the memory allocated for the buckets
    free_buckets(buckets);

    return 0;
}