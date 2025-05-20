//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Create a bucket of a given size
int* create_bucket(int size) {
    int* bucket = (int*)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        bucket[i] = 0;
    }
    return bucket;
}

// Insert an element into the bucket
void insert_into_bucket(int* bucket, int element) {
    bucket[element]++;
}

// Sort the elements in the bucket
void sort_bucket(int* bucket, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < bucket[i]; j++) {
            printf("%d ", i);
        }
    }
}

// Perform bucket sort on the given array
void bucket_sort(int* arr, int size) {
    // Determine the maximum element in the array
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Create a bucket of size max+1
    int* bucket = create_bucket(max + 1);

    // Insert each element into the bucket
    for (int i = 0; i < size; i++) {
        insert_into_bucket(bucket, arr[i]);
    }

    // Sort the elements in the bucket
    sort_bucket(bucket, max + 1);

    // Free the memory allocated for the bucket
    free(bucket);
}

int main() {
    // The array to be sorted
    int arr[] = {3, 1, 4, 2, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Perform bucket sort on the array
    bucket_sort(arr, size);

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}