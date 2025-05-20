//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// Each bucket has a list of elements
typedef struct bucket {
    int *elements;
    int size;
    int capacity;
} bucket;

// Create a new bucket with the given capacity
bucket *create_bucket(int capacity) {
    bucket *b = (bucket *)malloc(sizeof(bucket));
    b->elements = (int *)malloc(sizeof(int) * capacity);
    b->size = 0;
    b->capacity = capacity;
    return b;
}

// Insert an element into the bucket
void insert_into_bucket(bucket *b, int element) {
    if (b->size == b->capacity) {  // if the bucket is full
        b->capacity *= 2;  // double the capacity
        b->elements = (int *)realloc(b->elements, sizeof(int) * b->capacity);
    }
    b->elements[b->size++] = element;
}

// Sort the elements in a bucket using insertion sort
void insertion_sort_bucket(bucket *b) {
    int i, j, key;
    for (i = 1; i < b->size; i++) {
        key = b->elements[i];
        j = i - 1;
        while (j >= 0 && b->elements[j] > key) {
            b->elements[j + 1] = b->elements[j];
            j--;
        }
        b->elements[j + 1] = key;
    }
}

// Sort the given array using bucket sort
void bucket_sort(int *arr, int n) {
    // Create buckets for each digit
    bucket *buckets[10];
    for (int i = 0; i < 10; i++) {
        buckets[i] = create_bucket(n);
    }

    // Insert each element into the appropriate bucket
    for (int i = 0; i < n; i++) {
        insert_into_bucket(buckets[arr[i]], arr[i]);
    }

    // Sort the elements in each bucket
    for (int i = 0; i < 10; i++) {
        insertion_sort_bucket(buckets[i]);
    }

    // Concatenate the sorted elements from all buckets
    int index = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < buckets[i]->size; j++) {
            arr[index++] = buckets[i]->elements[j];
        }
    }

    // Free the memory allocated for buckets
    for (int i = 0; i < 10; i++) {
        free(buckets[i]->elements);
        free(buckets[i]);
    }
}

// Print the array
void print_array(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {5, 3, 1, 7, 4, 1, 2, 8, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucket_sort(arr, n);

    print_array(arr, n);

    return 0;
}