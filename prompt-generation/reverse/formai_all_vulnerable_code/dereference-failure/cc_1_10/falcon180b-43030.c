//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Function to find the index of the smallest element in the bucket
int findMinIndex(int arr[], int n) {
    int minIndex = 0;
    for(int i=1; i<n; i++) {
        if(arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int max = arr[0];
    int min = arr[0];

    // Find the maximum and minimum elements in the array
    for(int i=1; i<n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
        if(arr[i] < min) {
            min = arr[i];
        }
    }

    // Calculate the range of the array
    int range = max - min + 1;

    // Create an array of empty buckets
    int buckets[range];

    // Place each element in its corresponding bucket
    for(int i=0; i<n; i++) {
        buckets[arr[i] - min]++;
    }

    // Modify the array of buckets to store the cumulative count of elements
    for(int i=1; i<range; i++) {
        buckets[i] += buckets[i-1];
    }

    // Place the elements in the final sorted array
    int j = n - 1;
    for(int i=range - 1; i>=0; i--) {
        while(buckets[i] > 0) {
            arr[j] = i + min;
            j--;
            buckets[i]--;
        }
    }
}

int main() {
    int n;

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Get the elements of the array from the user
    int arr[n];
    printf("Enter the elements of the array:\n");
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    // Perform bucket sort
    bucketSort(arr, n);

    // Print the sorted array
    printf("Sorted array:\n");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}