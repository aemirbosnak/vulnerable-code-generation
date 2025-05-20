//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: beginner-friendly
#include <stdlib.h>
#include <stdio.h>

// Initialize an empty bucket
struct bucket {
    int count;
    int* elements;
};

// Initialize a bucket array with n empty buckets
struct bucket* init_buckets(int n) {
    struct bucket* buckets = malloc(sizeof(struct bucket) * n);
    for (int i = 0; i < n; i++) {
        buckets[i].count = 0;
        buckets[i].elements = NULL;
    }
    return buckets;
}

// Insert an element into a bucket
void insert_element(struct bucket* bucket, int element) {
    bucket->elements = realloc(bucket->elements, sizeof(int) * (bucket->count + 1));
    bucket->elements[bucket->count++] = element;
}

// Perform bucket sort on an array of n elements
void bucket_sort(int* arr, int n) {
    // Find the maximum and minimum values in the array
    int max = arr[0];
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    // Create n buckets
    struct bucket* buckets = init_buckets(n);

    // Distribute the elements into the buckets
    for (int i = 0; i < n; i++) {
        int bucket_index = (arr[i] - min) * (n - 1) / (max - min);
        insert_element(&buckets[bucket_index], arr[i]);
    }

    // Sort the elements in each bucket using insertion sort
    for (int i = 0; i < n; i++) {
        int* elements = buckets[i].elements;
        int count = buckets[i].count;
        for (int j = 1; j < count; j++) {
            int key = elements[j];
            int k = j - 1;
            while (k >= 0 && elements[k] > key) {
                elements[k + 1] = elements[k];
                k--;
            }
            elements[k + 1] = key;
        }
    }

    // Concatenate the sorted elements from the buckets
    int index = 0;
    for (int i = 0; i < n; i++) {
        int* elements = buckets[i].elements;
        int count = buckets[i].count;
        for (int j = 0; j < count; j++) {
            arr[index++] = elements[j];
        }
    }

    // Free the memory allocated for the buckets
    for (int i = 0; i < n; i++) {
        free(buckets[i].elements);
    }
    free(buckets);
}

int main() {
    int arr[] = {4, 2, 1, 7, 5, 3, 6, 9, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucket_sort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}