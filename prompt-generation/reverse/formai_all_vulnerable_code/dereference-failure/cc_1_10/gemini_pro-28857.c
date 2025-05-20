//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: safe
#include <stdlib.h>
#include <stdio.h>

#define BUCKET_SIZE 5

// Function to insert an element into a bucket
void insert_into_bucket(int* bucket, int element) {
    // Find the first empty slot in the bucket
    int i;
    for (i = 0; i < BUCKET_SIZE; i++) {
        if (bucket[i] == 0) {
            break;
        }
    }

    // If there is no empty slot, create a new bucket
    if (i == BUCKET_SIZE) {
        bucket = realloc(bucket, (BUCKET_SIZE + 1) * sizeof(int));
        bucket[BUCKET_SIZE] = 0;
    }

    // Insert the element into the bucket
    bucket[i] = element;
}

// Function to sort a bucket
void sort_bucket(int* bucket) {
    // Sort the bucket using a simple insertion sort
    int i, j;
    for (i = 1; i < BUCKET_SIZE; i++) {
        int key = bucket[i];
        j = i - 1;

        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }

        bucket[j + 1] = key;
    }
}

// Function to distribute elements into buckets
void distribute_into_buckets(int* array, int size, int** buckets) {
    // Create the buckets
    int i;
    for (i = 0; i < size; i++) {
        buckets[i] = malloc(BUCKET_SIZE * sizeof(int));
    }

    // Distribute the elements into the buckets
    for (i = 0; i < size; i++) {
        int bucket_index = array[i] / BUCKET_SIZE;
        insert_into_bucket(buckets[bucket_index], array[i]);
    }
}

// Function to merge the buckets into a single sorted array
void merge_buckets(int** buckets, int size, int* sorted_array) {
    // Create a pointer to the current element in the sorted array
    int* current_element = sorted_array;

    // Merge the buckets into the sorted array
    int i;
    for (i = 0; i < size; i++) {
        // Sort the bucket
        sort_bucket(buckets[i]);

        // Copy the sorted bucket into the sorted array
        int j;
        for (j = 0; j < BUCKET_SIZE; j++) {
            if (buckets[i][j] != 0) {
                *current_element = buckets[i][j];
                current_element++;
            }
        }
    }
}

// Function to print an array
void print_array(int* array, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    // Create an array of unsorted integers
    int array[] = {10, 5, 15, 2, 7, 12, 9, 14, 4, 11, 13, 6, 8, 1};
    int size = sizeof(array) / sizeof(array[0]);

    // Create an array of buckets
    int** buckets = malloc(size * sizeof(int*));

    // Distribute the elements into the buckets
    distribute_into_buckets(array, size, buckets);

    // Merge the buckets into a single sorted array
    int* sorted_array = malloc(size * sizeof(int));
    merge_buckets(buckets, size, sorted_array);

    // Print the sorted array
    print_array(sorted_array, size);

    // Free the allocated memory
    free(buckets);
    free(sorted_array);

    return 0;
}