//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Function to create a bucket
struct Bucket {
    int* arr;
    int size;
    int capacity;
};

// Function to create a bucket
struct Bucket* create_bucket(int capacity) {
    struct Bucket* bucket = (struct Bucket*)malloc(sizeof(struct Bucket));
    bucket->arr = (int*)malloc(sizeof(int) * capacity);
    bucket->size = 0;
    bucket->capacity = capacity;
    return bucket;
}

// Function to insert an element into a bucket
void insert_into_bucket(struct Bucket* bucket, int element) {
    if (bucket->size == bucket->capacity) {
        bucket->capacity *= 2;
        bucket->arr = (int*)realloc(bucket->arr, sizeof(int) * bucket->capacity);
    }
    bucket->arr[bucket->size++] = element;
}

// Function to sort a bucket
void sort_bucket(struct Bucket* bucket) {
    for (int i = 0; i < bucket->size - 1; i++) {
        for (int j = i + 1; j < bucket->size; j++) {
            if (bucket->arr[i] > bucket->arr[j]) {
                int temp = bucket->arr[i];
                bucket->arr[i] = bucket->arr[j];
                bucket->arr[j] = temp;
            }
        }
    }
}

// Function to perform bucket sort
void bucket_sort(int* arr, int size) {
    // Create an array of buckets
    struct Bucket** buckets = (struct Bucket**)malloc(sizeof(struct Bucket*) * size);

    // Initialize all buckets
    for (int i = 0; i < size; i++) {
        buckets[i] = create_bucket(size);
    }

    // Insert elements into buckets
    for (int i = 0; i < size; i++) {
        insert_into_bucket(buckets[arr[i]], arr[i]);
    }

    // Sort each bucket
    for (int i = 0; i < size; i++) {
        sort_bucket(buckets[i]);
    }

    // Concatenate all buckets into the original array
    int index = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < buckets[i]->size; j++) {
            arr[index++] = buckets[i]->arr[j];
        }
        free(buckets[i]->arr);
        free(buckets[i]);
    }
    free(buckets);
}

// Function to print an array
void print_array(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Driver code
int main() {
    // Unsorted array
    int arr[] = {5, 3, 1, 7, 4, 1, 2, 8, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Sort the array using bucket sort
    bucket_sort(arr, size);

    // Print the sorted array
    print_array(arr, size);

    return 0;
}