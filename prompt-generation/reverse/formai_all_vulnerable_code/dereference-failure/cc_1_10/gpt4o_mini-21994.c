//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of bucket
typedef struct Bucket {
    int *arr;
    int count;
    int capacity;
} Bucket;

// Function prototypes
Bucket* createBucket(int capacity);
void insertToBucket(Bucket* bucket, int value);
void bucketSort(int *array, int n, int maxValue);
void printArray(int *array, int n);
void freeBuckets(Bucket* buckets, int numBuckets);

int main() {
    int n, maxValue;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int *array = (int *)malloc(n * sizeof(int));
    if (!array) {
        perror("Memory allocation failed");
        return EXIT_FAILURE;
    }

    printf("Enter the elements: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    printf("Enter the maximum value in the array: ");
    scanf("%d", &maxValue);

    printf("Original array: ");
    printArray(array, n);

    bucketSort(array, n, maxValue);

    printf("Sorted array: ");
    printArray(array, n);

    free(array);
    return 0;
}

// Create a bucket and return pointer to it
Bucket* createBucket(int capacity) {
    Bucket* bucket = (Bucket *)malloc(sizeof(Bucket));
    bucket->arr = (int *)malloc(capacity * sizeof(int));
    bucket->count = 0;
    bucket->capacity = capacity;
    return bucket;
}

// Insert value into the bucket
void insertToBucket(Bucket* bucket, int value) {
    // If bucket capacity is reached, resize it
    if (bucket->count >= bucket->capacity) {
        bucket->capacity *= 2;
        bucket->arr = realloc(bucket->arr, bucket->capacity * sizeof(int));
    }
    bucket->arr[bucket->count++] = value;
}

// The core function that implements bucket sort
void bucketSort(int *array, int n, int maxValue) {
    int numBuckets = (maxValue / 10) + 1; // Number of buckets
    Bucket* buckets = (Bucket*)malloc(numBuckets * sizeof(Bucket));

    // Initialize the buckets
    for (int i = 0; i < numBuckets; i++) {
        buckets[i] = *createBucket(10); // Initial capacity of 10
    }

    // Scatter the elements into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = array[i] / 10; // Determine which bucket to use
        insertToBucket(&buckets[bucketIndex], array[i]);
    }

    // Sort each bucket and gather the results
    int arrayIndex = 0;
    for (int i = 0; i < numBuckets; i++) {
        if (buckets[i].count > 0) {
            // Simple insertion sort for each bucket
            for (int j = 1; j < buckets[i].count; j++) {
                int key = buckets[i].arr[j];
                int k = j - 1;
                while (k >= 0 && buckets[i].arr[k] > key) {
                    buckets[i].arr[k + 1] = buckets[i].arr[k];
                    k--;
                }
                buckets[i].arr[k + 1] = key;
            }
            // Gather sorted values back into the array
            for (int j = 0; j < buckets[i].count; j++) {
                array[arrayIndex++] = buckets[i].arr[j];
            }
        }
    }

    // Free bucket resources
    freeBuckets(buckets, numBuckets);
    free(buckets);
}

// Print the array
void printArray(int *array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Free the resources allocated for buckets
void freeBuckets(Bucket* buckets, int numBuckets) {
    for (int i = 0; i < numBuckets; i++) {
        free(buckets[i].arr);
    }
}