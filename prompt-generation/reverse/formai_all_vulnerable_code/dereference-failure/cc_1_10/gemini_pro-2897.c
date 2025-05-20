//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Create a bucket
typedef struct Bucket {
    int *data;
    int capacity;
    int size;
} Bucket;

// Create a bucket sort
typedef struct BucketSort {
    Bucket *buckets;
    int num_buckets;
} BucketSort;

// Initialize a bucket
static Bucket *bucket_init(int capacity) {
    Bucket *bucket = (Bucket *)malloc(sizeof(Bucket));
    bucket->data = (int *)malloc(sizeof(int) * capacity);
    bucket->capacity = capacity;
    bucket->size = 0;
    return bucket;
}

// Initialize a bucket sort
static BucketSort *bucket_sort_init(int num_buckets) {
    BucketSort *bucket_sort = (BucketSort *)malloc(sizeof(BucketSort));
    bucket_sort->buckets = (Bucket *)malloc(sizeof(Bucket) * num_buckets);
    bucket_sort->num_buckets = num_buckets;
    for (int i = 0; i < num_buckets; i++) {
        bucket_sort->buckets[i] = *bucket_init(10);
    }
    return bucket_sort;
}

// Insert an element into a bucket
static void bucket_sort_insert(BucketSort *bucket_sort, int element) {
    int bucket_index = element / bucket_sort->num_buckets;
    Bucket *bucket = &bucket_sort->buckets[bucket_index];

    // If the bucket is full, double its capacity
    if (bucket->size == bucket->capacity) {
        bucket->capacity *= 2;
        bucket->data = (int *)realloc(bucket->data, sizeof(int) * bucket->capacity);
    }

    // Insert the element into the bucket
    bucket->data[bucket->size++] = element;
}

// Sort the elements in a bucket
static void bucket_sort_sort_bucket(Bucket *bucket) {
    // Sort the elements in the bucket using insertion sort
    for (int i = 1; i < bucket->size; i++) {
        int key = bucket->data[i];
        int j = i - 1;
        while (j >= 0 && bucket->data[j] > key) {
            bucket->data[j + 1] = bucket->data[j];
            j--;
        }
        bucket->data[j + 1] = key;
    }
}

// Sort the elements in the bucket sort
static void bucket_sort_sort(BucketSort *bucket_sort) {
    // Sort the elements in each bucket
    for (int i = 0; i < bucket_sort->num_buckets; i++) {
        bucket_sort_sort_bucket(&bucket_sort->buckets[i]);
    }

    // Concatenate the sorted elements from each bucket
    int *sorted_data = (int *)malloc(sizeof(int) * bucket_sort->num_buckets);
    int sorted_index = 0;
    for (int i = 0; i < bucket_sort->num_buckets; i++) {
        Bucket *bucket = &bucket_sort->buckets[i];
        for (int j = 0; j < bucket->size; j++) {
            sorted_data[sorted_index++] = bucket->data[j];
        }
    }

    // Copy the sorted data back into the original array
    for (int i = 0; i < sorted_index; i++) {
        bucket_sort->buckets[i].data[i] = sorted_data[i];
    }

    free(sorted_data);
}

// Free the memory allocated for a bucket
static void bucket_free(Bucket *bucket) {
    free(bucket->data);
    free(bucket);
}

// Free the memory allocated for a bucket sort
static void bucket_sort_free(BucketSort *bucket_sort) {
    for (int i = 0; i < bucket_sort->num_buckets; i++) {
        bucket_free(&bucket_sort->buckets[i]);
    }
    free(bucket_sort->buckets);
    free(bucket_sort);
}

// Function to generate a random array of integers
int *generate_random_array(int size, int min, int max) {
    int *array = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        array[i] = (rand() % (max - min + 1)) + min;
    }
    return array;
}

// Function to print the contents of an array
void print_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    // Generate a random array of integers
    int *array = generate_random_array(1000, 0, 1000);

    // Create a bucket sort
    BucketSort *bucket_sort = bucket_sort_init(10);

    // Insert the elements into the bucket sort
    for (int i = 0; i < 1000; i++) {
        bucket_sort_insert(bucket_sort, array[i]);
    }

    // Sort the elements in the bucket sort
    bucket_sort_sort(bucket_sort);

    // Print the sorted array
    print_array(array, 1000);

    // Free the memory allocated for the bucket sort
    bucket_sort_free(bucket_sort);

    // Free the memory allocated for the array
    free(array);

    return 0;
}