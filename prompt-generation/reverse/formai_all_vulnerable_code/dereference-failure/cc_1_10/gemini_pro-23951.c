//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: peaceful
// C program for bucket sort
#include <stdio.h>
#include <stdlib.h>

// A bucket
struct Bucket {
    int count;
    int* values;
};

// Create a new bucket
struct Bucket* create_bucket() {
    struct Bucket* bucket = (struct Bucket*)malloc(sizeof(struct Bucket));
    bucket->count = 0;
    bucket->values = (int*)malloc(sizeof(int) * 10);
    return bucket;
}

// Insert a value into a bucket
void insert_into_bucket(struct Bucket* bucket, int value) {
    if (bucket->count == 10) {
        bucket->values = (int*)realloc(bucket->values, sizeof(int) * (bucket->count + 1));
    }
    bucket->values[bucket->count++] = value;
}

// Sort a bucket
void sort_bucket(struct Bucket* bucket) {
    for (int i = 0; i < bucket->count - 1; i++) {
        for (int j = i + 1; j < bucket->count; j++) {
            if (bucket->values[i] > bucket->values[j]) {
                int temp = bucket->values[i];
                bucket->values[i] = bucket->values[j];
                bucket->values[j] = temp;
            }
        }
    }
}

// Bucket sort
void bucket_sort(int* arr, int n) {
    // Create n empty buckets
    struct Bucket** buckets = (struct Bucket**)malloc(sizeof(struct Bucket*) * n);
    for (int i = 0; i < n; i++) {
        buckets[i] = create_bucket();
    }

    // Insert each value into its respective bucket
    for (int i = 0; i < n; i++) {
        insert_into_bucket(buckets[arr[i]], arr[i]);
    }

    // Sort each bucket
    for (int i = 0; i < n; i++) {
        sort_bucket(buckets[i]);
    }

    // Concatenate the sorted buckets into the original array
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i]->count; j++) {
            arr[index++] = buckets[i]->values[j];
        }
    }

    // Free the buckets
    for (int i = 0; i < n; i++) {
        free(buckets[i]->values);
        free(buckets[i]);
    }
    free(buckets);
}

// Print an array
void print_array(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Driver code
int main() {
    int arr[] = { 5, 3, 1, 7, 4, 1, 2, 8, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    bucket_sort(arr, n);

    print_array(arr, n);

    return 0;
}