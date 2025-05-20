//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// Function to sort an array using bucket sort
void bucketSort(int arr[], int n, int maxElem) {
    int i, j;
    int *buckets = (int*)malloc(maxElem*sizeof(int));
 
    // Initialize all buckets to 0
    for(i = 0; i < maxElem; i++) {
        buckets[i] = 0;
    }
 
    // Count the number of elements in each bucket
    for(i = 0; i < n; i++) {
        buckets[arr[i]]++;
    }
 
    // Sort each bucket using insertion sort
    for(i = 0, j = 0; i < maxElem; i++) {
        while(buckets[i] > 0) {
            arr[j++] = i;
            buckets[i]--;
        }
    }
 
    free(buckets);
}

// Utility function to print an array
void printArray(int arr[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Driver code
int main() {
    int n, maxElem, i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Finding the maximum element in the array
    maxElem = arr[0];
    for(i = 1; i < n; i++) {
        if(maxElem < arr[i]) {
            maxElem = arr[i];
        }
    }

    // Calling the bucket sort function
    bucketSort(arr, n, maxElem+1);

    printf("\nSorted array is: ");
    printArray(arr, n);
    return 0;
}