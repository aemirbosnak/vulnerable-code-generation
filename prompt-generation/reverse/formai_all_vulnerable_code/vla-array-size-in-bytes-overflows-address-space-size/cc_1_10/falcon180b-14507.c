//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
} Bucket;

// Function to create a new bucket
Bucket* createBucket(int size) {
    Bucket *newBucket = (Bucket*)malloc(sizeof(Bucket));
    newBucket->data = (int*)malloc(sizeof(int) * size);
    newBucket->size = size;
    return newBucket;
}

// Function to initialize the bucket with zeros
void initBucket(Bucket *bucket) {
    for (int i = 0; i < bucket->size; i++) {
        bucket->data[i] = 0;
    }
}

// Function to insert element into bucket
void insertBucket(Bucket *bucket, int element) {
    int index = element / bucket->size;
    bucket->data[index]++;
}

// Function to sort the array using bucket sort
void bucketSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    int bucketSize = max / n;
    Bucket **buckets = (Bucket**)malloc(sizeof(Bucket*) * bucketSize);
    for (int i = 0; i < bucketSize; i++) {
        buckets[i] = createBucket(n);
        initBucket(buckets[i]);
    }
    for (int i = 0; i < n; i++) {
        int index = arr[i] / bucketSize;
        insertBucket(buckets[index], arr[i]);
    }
    int j = 0;
    for (int i = 0; i < bucketSize; i++) {
        Bucket *bucket = buckets[i];
        for (int k = 0; k < bucket->size; k++) {
            if (bucket->data[k] > 0) {
                arr[j] = k * bucketSize + i * bucketSize;
                bucket->data[k]--;
                j++;
            }
        }
    }
    free(buckets);
}

// Function to print the sorted array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    bucketSort(arr, n);
    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}