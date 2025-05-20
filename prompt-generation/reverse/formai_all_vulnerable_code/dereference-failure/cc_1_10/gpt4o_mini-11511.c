//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUCKET_SIZE 10 // Number of buckets

// Structure for a bucket
typedef struct Bucket {
    int *array;        // Array for bucket elements
    int count;        // Number of elements in the bucket
    int capacity;     // Capacity of the bucket
} Bucket;

// Function to create a new bucket
Bucket create_bucket() {
    Bucket b;
    b.count = 0;
    b.capacity = 10; // Initial capacity
    b.array = (int *)malloc(b.capacity * sizeof(int));
    return b;
}

// Function to insert an element into a bucket
void insert_bucket(Bucket *b, int value) {
    if (b->count >= b->capacity) {
        b->capacity *= 2;
        b->array = (int *)realloc(b->array, b->capacity * sizeof(int));
    }
    b->array[b->count++] = value;
}

// Function to sort a bucket (using insertion sort)
void sort_bucket(Bucket *b) {
    for (int i = 1; i < b->count; i++) {
        int key = b->array[i];
        int j = i - 1;

        // Move elements larger than key to one position ahead
        while (j >= 0 && b->array[j] > key) {
            b->array[j + 1] = b->array[j];
            j--;
        }
        b->array[j + 1] = key;
    }
}

// Function to perform bucket sort
void bucket_sort(int *array, int n) {
    // Create buckets
    Bucket *buckets = (Bucket *)malloc(BUCKET_SIZE * sizeof(Bucket));
    for (int i = 0; i < BUCKET_SIZE; i++) {
        buckets[i] = create_bucket();
    }

    // Distributing elements into buckets
    for (int i = 0; i < n; i++) {
        int index = array[i] * BUCKET_SIZE / (n + 1);
        insert_bucket(&buckets[index], array[i]);
    }

    // Sorting each bucket
    for (int i = 0; i < BUCKET_SIZE; i++) {
        sort_bucket(&buckets[i]);
    }

    // Concatenating buckets back into the array
    int index = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        for (int j = 0; j < buckets[i].count; j++) {
            array[index++] = buckets[i].array[j];
        }
        free(buckets[i].array); // Free memory of each bucket's array
    }

    free(buckets); // Free the array of buckets
}

// Function to print an array
void print_array(int *array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int array[] = {29, 25, 3, 49, 9, 37, 21, 43};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Unsorted array:\n");
    print_array(array, n);

    bucket_sort(array, n);

    printf("Sorted array:\n");
    print_array(array, n);
    
    return 0;
}