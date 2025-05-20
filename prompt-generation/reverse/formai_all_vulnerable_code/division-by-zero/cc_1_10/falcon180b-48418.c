//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100
#define MAX_RANGE 1000

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to find the minimum value in an array
int findMin(int arr[], int size) {
    int min = arr[0];
    for(int i=1; i<size; i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// Function to find the maximum value in an array
int findMax(int arr[], int size) {
    int max = arr[0];
    for(int i=1; i<size; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to create a random array of integers
void createArray(int arr[], int size) {
    srand(time(NULL));
    for(int i=0; i<size; i++) {
        arr[i] = rand() % MAX_RANGE;
    }
}

// Function to print an array of integers
void printArray(int arr[], int size) {
    for(int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform bucket sort
void bucketSort(int arr[], int size, int numBuckets) {
    int min = findMin(arr, size);
    int max = findMax(arr, size);
    int range = max - min + 1;
    int bucketSize = range / numBuckets;
    int* buckets[numBuckets];
    for(int i=0; i<numBuckets; i++) {
        buckets[i] = (int*)malloc(sizeof(int)*size);
    }
    for(int i=0; i<size; i++) {
        int bucketIndex = (arr[i] - min) / bucketSize;
        int* currentBucket = buckets[bucketIndex];
        if(currentBucket == NULL) {
            currentBucket = (int*)malloc(sizeof(int)*size);
            buckets[bucketIndex] = currentBucket;
        }
        int* currentBucketPointer = currentBucket;
        while(*currentBucketPointer!= -1) {
            currentBucketPointer++;
        }
        *currentBucketPointer = arr[i];
    }
    int index = 0;
    for(int i=0; i<numBuckets; i++) {
        int* currentBucket = buckets[i];
        while(*currentBucket!= -1) {
            arr[index++] = *currentBucket;
            currentBucket++;
        }
    }
    for(int i=0; i<numBuckets; i++) {
        free(buckets[i]);
    }
}

// Main function
int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[MAX_SIZE];
    createArray(arr, size);
    int numBuckets;
    printf("Enter the number of buckets: ");
    scanf("%d", &numBuckets);
    printf("Original array:\n");
    printArray(arr, size);
    bucketSort(arr, size, numBuckets);
    printf("Sorted array:\n");
    printArray(arr, size);
    return 0;
}