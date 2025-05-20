//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
#define BUCKET_COUNT 10

// Structure to represent a bucket
typedef struct Bucket {
    int *items;
    int count;
} Bucket;

// Function to initialize buckets
Bucket* init_buckets(int size) {
    Bucket* buckets = (Bucket*)malloc(size * sizeof(Bucket));
    for (int i = 0; i < size; i++) {
        buckets[i].items = (int*)malloc(MAX * sizeof(int));
        buckets[i].count = 0;
    }
    return buckets;
}

// Function to free the allocated buckets
void free_buckets(Bucket* buckets, int size) {
    for (int i = 0; i < size; i++) {
        free(buckets[i].items);
    }
    free(buckets);
}

// Function for insertion sort
void insertion_sort(int* arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to perform bucket sort
void bucket_sort(int* arr, int n) {
    if (n <= 0) return;
    
    Bucket* buckets = init_buckets(BUCKET_COUNT);
    
    // Find the maximum value in the array
    int max_value = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
    }

    // Assign values to buckets
    for (int i = 0; i < n; i++) {
        int bucket_index = (arr[i] * BUCKET_COUNT) / (max_value + 1);
        buckets[bucket_index].items[buckets[bucket_index].count++] = arr[i];
    }

    // Sort the individual buckets and concatenate
    int index = 0;
    for (int i = 0; i < BUCKET_COUNT; i++) {
        if (buckets[i].count > 0) {
            insertion_sort(buckets[i].items, buckets[i].count);
            for (int j = 0; j < buckets[i].count; j++) {
                arr[index++] = buckets[i].items[j];
            }
        }
    }

    // Free the allocated buckets
    free_buckets(buckets, BUCKET_COUNT);
}

// Function to print the array
void print_array(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    print_array(arr, n);
    
    bucket_sort(arr, n);
    
    printf("Sorted array: ");
    print_array(arr, n);
    
    return 0;
}