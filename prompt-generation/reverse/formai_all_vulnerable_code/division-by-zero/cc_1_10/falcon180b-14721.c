//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: configurable
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int *arr;
    int size;
} Bucket;

// Function to create a new bucket with given size
Bucket* createBucket(int size) {
    Bucket *newBucket = (Bucket*)malloc(sizeof(Bucket));
    newBucket->arr = (int*)malloc(size * sizeof(int));
    newBucket->size = size;
    return newBucket;
}

// Function to insert element in the corresponding bucket
void insertElement(Bucket *bucket, int element) {
    int index = element % bucket->size;
    bucket->arr[index] = element;
}

// Function to sort the array using bucket sort algorithm
void bucketSort(int *arr, int size) {
    int maxElement = arr[0];
    for(int i=1; i<size; i++) {
        if(arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }
    int bucketSize = maxElement / size + 1;
    Bucket **buckets = (Bucket**)malloc(bucketSize * sizeof(Bucket*));
    for(int i=0; i<bucketSize; i++) {
        buckets[i] = createBucket(size);
    }
    for(int i=0; i<size; i++) {
        int index = arr[i] / size;
        insertElement(buckets[index], arr[i]);
    }
    int j = 0;
    for(int i=0; i<bucketSize; i++) {
        Bucket *bucket = buckets[i];
        for(int k=0; k<bucket->size; k++) {
            arr[j++] = bucket->arr[k];
        }
    }
    free(buckets);
}

// Main function to test the bucket sort algorithm
int main() {
    int arr[] = {9, 3, 8, 1, 6, 2, 7, 5, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, size);
    printf("Sorted array: ");
    for(int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}