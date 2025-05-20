//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE 100 // maximum value of array elements
#define BUCKET_SIZE 5 // size of each bucket

// function to print the array
void printArray(int *arr, int size) {
    printf("Array:");
    for(int i=0; i<size; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");
}

// bucket sort function
void bucketSort(int *arr, int size) {
    // create buckets
    int bucketCount = (MAX_VALUE/BUCKET_SIZE) + 1;
    int **buckets = (int **)malloc(sizeof(int *) * bucketCount);
    for(int i=0; i<bucketCount; i++) {
        int bucketSize = (i == bucketCount-1) ? (MAX_VALUE%BUCKET_SIZE+1) : BUCKET_SIZE;
        buckets[i] = (int *)malloc(sizeof(int) * bucketSize);
    }
    
    // insert elements into buckets
    for(int i=0; i<size; i++) {
        int bucketIndex = arr[i] / BUCKET_SIZE;
        int bucketSize = (bucketIndex == bucketCount-1) ? (MAX_VALUE%BUCKET_SIZE+1) : BUCKET_SIZE;
        int *bucket = buckets[bucketIndex];
        int insertIndex = 0;
        while(insertIndex < bucketSize && bucket[insertIndex] != 0 && bucket[insertIndex] < arr[i]) {
            insertIndex++;
        }
        for(int j=bucketSize-1; j>insertIndex; j--) {
            bucket[j] = bucket[j-1];
        }
        bucket[insertIndex] = arr[i];
    }
    
    // combine buckets
    int index = 0;
    for(int i=0; i<bucketCount; i++) {
        int bucketSize = (i == bucketCount-1) ? (MAX_VALUE%BUCKET_SIZE+1) : BUCKET_SIZE;
        int *bucket = buckets[i];
        for(int j=0; j<bucketSize; j++) {
            if(bucket[j] != 0) {
                arr[index++] = bucket[j];
            }
        }
    }
}

// main function
int main() {
    int arr[] = {64, 34, 25, 23, 12, 22, 11, 90, 65, 44};
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("Input:\n");
    printArray(arr, size);

    bucketSort(arr, size);

    printf("Output:\n");
    printArray(arr, size);

    return 0;
}