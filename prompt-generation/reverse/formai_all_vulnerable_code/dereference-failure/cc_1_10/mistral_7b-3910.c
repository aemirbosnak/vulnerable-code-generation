//MISTRAL-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define BUCKET_SIZE 10
#define MAX_ELEMENTS 100
#define ELEM_SIZE sizeof(int)

// Custom malloc function to handle bucket memory allocation
void *my_malloc(size_t size) {
    void *ptr;
    ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

// Custom free function to handle bucket memory deallocation
void my_free(void *ptr) {
    free(ptr);
}

// Bucket sort function
void bucketSort(int *arr, int n) {
    int i;
    int *bucket[BUCKET_SIZE];
    int count[BUCKET_SIZE] = {0};
    int *indices;

    // Allocate memory for buckets and indices
    bucket[0] = (int *)my_malloc(BUCKET_SIZE * sizeof(int *));
    indices = (int *)my_malloc(n * sizeof(int));

    // Initialize buckets and indices
    for (i = 0; i < BUCKET_SIZE; i++) {
        bucket[i] = (int *)my_malloc(MAX_ELEMENTS * ELEM_SIZE);
        memset(bucket[i], 0, MAX_ELEMENTS * ELEM_SIZE);
    }

    // Sorting
    for (i = 0; i < n; i++) {
        int index = (arr[i] / (int)(pow(10, log10(n)) / BUCKET_SIZE)) % BUCKET_SIZE;
        bucket[index][count[index]++] = arr[i];
    }

    int j = 0;
    for (i = 0; i < BUCKET_SIZE; i++) {
        int k = 0;
        while (k < count[i]) {
            indices[j++] = i * MAX_ELEMENTS + k++;
        }
    }

    // Copy sorted elements back to original array
    for (i = 0; i < n; i++) {
        arr[i] = *(int *)(&bucket[i / (int)(pow(10, log10(n)) / BUCKET_SIZE)][i % (MAX_ELEMENTS / BUCKET_SIZE)]);
    }

    // Deallocate memory
    for (i = 0; i < BUCKET_SIZE; i++) {
        my_free(bucket[i]);
    }
    my_free(bucket);
    my_free(indices);
}

// Function to print an array
void printArray(int *arr, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Driver code
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 111, 78, 125, 4, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);
    printArray(arr, n);

    return 0;
}