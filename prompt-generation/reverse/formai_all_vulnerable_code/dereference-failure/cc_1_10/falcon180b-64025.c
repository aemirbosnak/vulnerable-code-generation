//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1000

// Function to calculate the index of the bucket
int getBucketIndex(float arr[], float max, float min, int size) {
    float range = max - min;
    float bucketSize = range / size;
    return (int)((arr[0] - min) / bucketSize);
}

// Function to perform bucket sort
void bucketSort(float arr[], int size) {
    float min = arr[0];
    float max = arr[0];

    for(int i=1; i<size; i++) {
        if(arr[i] < min)
            min = arr[i];
        else if(arr[i] > max)
            max = arr[i];
    }

    int bucketCount = (int)ceil((max - min) / (max - min) * 0.1);
    float *buckets[bucketCount];

    for(int i=0; i<bucketCount; i++)
        buckets[i] = (float *)malloc(sizeof(float) * size);

    for(int i=0; i<size; i++) {
        int bucketIndex = getBucketIndex(arr, max, min, bucketCount);
        buckets[bucketIndex][i] = arr[i];
    }

    for(int i=0; i<size; i++)
        arr[i] = buckets[getBucketIndex(arr, max, min, bucketCount)][i];

    for(int i=0; i<bucketCount; i++)
        free(buckets[i]);
}

int main() {
    float arr[] = {1.2, 3.4, 2.1, 5.6, 4.7, 6.8};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting: ");
    for(int i=0; i<size; i++)
        printf("%.2f ", arr[i]);

    bucketSort(arr, size);

    printf("\nAfter sorting: ");
    for(int i=0; i<size; i++)
        printf("%.2f ", arr[i]);

    return 0;
}