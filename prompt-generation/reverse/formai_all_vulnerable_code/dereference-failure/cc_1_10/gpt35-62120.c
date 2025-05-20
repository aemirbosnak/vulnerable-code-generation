//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: romantic
#include <stdio.h>

// Define the number of buckets
#define NUM_BUCKETS 10

// Define the size of the array to sort
#define ARRAY_SIZE 10

// Define the range of values in the input array
#define RANGE 100

// Create a bucket data structure
typedef struct {
    int count;
    int* value;
} Bucket;

// Define the sorting algorithm to use for the buckets
void insertion_sort(int* a, int n) {
    int i, j, k;
    for (i = 1; i < n; i++) {
        k = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > k) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = k;
    }
}

int main() {
    // Initialize the input array
    int arr[ARRAY_SIZE] = {31, 32, 90, 23, 84, 17, 12, 64, 52, 33};

    // Create the array of buckets
    Bucket buckets[NUM_BUCKETS] = {0};

    // Calculate the size of each bucket
    int bucket_size = RANGE / NUM_BUCKETS;

    // Distribute the input array into the buckets
    for (int i = 0; i < ARRAY_SIZE; i++) {
        int bucket_index = arr[i] / bucket_size;
        if (bucket_index >= NUM_BUCKETS) {
            bucket_index = NUM_BUCKETS - 1;
        }
        buckets[bucket_index].value[buckets[bucket_index].count++] = arr[i];
    }

    // Sort the buckets
    for (int i = 0; i < NUM_BUCKETS; i++) {
        insertion_sort(buckets[i].value, buckets[i].count);
    }

    // Concatenate the sorted buckets into the final sorted array
    int index = 0;
    for (int i = 0; i < NUM_BUCKETS; i++) {
        for (int j = 0; j < buckets[i].count; j++) {
            arr[index++] = buckets[i].value[j];
        }
    }

    // Print the final sorted array
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}