//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: minimalist
#include <stdio.h>

// Function to calculate the number of buckets required for a given array
int calculateBuckets(int arr[], int size) {
    int buckets = 1;
    while (buckets < size)
        buckets *= 2;
    return buckets;
}

// Function to perform bucket sort
void bucketSort(int arr[], int size) {
    int buckets = calculateBuckets(arr, size);
    int *bucketsArray = (int *)malloc(buckets * sizeof(int));
    int *tempArray = (int *)malloc(size * sizeof(int));
    int i, j, k;

    // Creating bucketsArray with initial values
    for (i = 0; i < buckets; i++)
        bucketsArray[i] = 0;

    // Copying elements to tempArray and placing them in appropriate buckets
    for (i = 0; i < size; i++) {
        j = (arr[i] - (i % buckets)) / (i / buckets);
        tempArray[bucketsArray[j]++] = arr[i];
    }

    // Copying elements back to arr from tempArray and placing them in appropriate buckets
    for (i = 0; i < size; i++) {
        j = (tempArray[i] - (i % buckets)) / (i / buckets);
        arr[i] = tempArray[j];
    }

    // Freeing memory
    free(bucketsArray);
    free(tempArray);
}

// Main function
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Before Sorting: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    bucketSort(arr, size);

    printf("\nAfter Sorting: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    return 0;
}