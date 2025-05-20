//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// Function to get the maximum value from an array
int getMax(int arr[], int n) {
    int max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform a bucket sort
void bucketSort(int arr[], int n) {
    int max = getMax(arr, n);
    int *bucket = (int *)malloc(max * sizeof(int));
    for(int i = 0; i < max; i++) {
        bucket[i] = 0;
    }
    for(int i = 0; i < n; i++) {
        bucket[arr[i]]++;
    }
    int j = 0;
    for(int i = 0; i < max; i++) {
        while(bucket[i] > 0) {
            arr[j++] = i;
            bucket[i]--;
        }
    }
}

// Main function
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    bucketSort(arr, n);
    printf("Sorted array:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}