//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum element in an array
int findMax(int arr[], int n) {
    int max = arr[0];
    for(int i=1; i<n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int max = findMax(arr, n);
    int bucketSize = max/n;
    int* buckets = (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++) {
        buckets[i] = 0;
    }
    for(int i=0; i<n; i++) {
        int index = arr[i]/bucketSize;
        buckets[index]++;
    }
    for(int i=0; i<n; i++) {
        int index = arr[i]/bucketSize;
        for(int j=0; j<buckets[index]; j++) {
            printf("%d ", arr[i]);
        }
    }
}

int main() {
    int arr[] = {5, 3, 8, 4, 2, 7, 1, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Array before sorting: ");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    bucketSort(arr, n);
    printf("\nArray after sorting: ");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}