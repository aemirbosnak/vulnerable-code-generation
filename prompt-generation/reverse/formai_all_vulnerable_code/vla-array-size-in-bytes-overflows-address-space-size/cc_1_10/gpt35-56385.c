//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Defining the bucket size as a macro
#define BUCKET_SIZE 10

void bucketSort(int arr[], int n) {
    // Creating an array of buckets
    int buckets[BUCKET_SIZE][n+1];
    
    // Initializing the bucket sizes as 0
    for(int i=0; i<BUCKET_SIZE; i++) {
        buckets[i][n] = 0;
    }
    
    // Assigning the array elements to buckets
    for(int i=0; i<n; i++) {
        int bucketIndex = arr[i] / BUCKET_SIZE;
        buckets[bucketIndex][buckets[bucketIndex][n]++] = arr[i];
    }
    
    // Sorting the individual buckets using insertion sort
    for(int i=0; i<BUCKET_SIZE; i++) {
        for(int j=0; j<buckets[i][n]; j++) {
            int k = j-1, temp = buckets[i][j];
            while(k >= 0 && buckets[i][k] > temp) {
                buckets[i][k+1] = buckets[i][k];
                k--;
            }
            buckets[i][k+1] = temp;
        }
    }
    
    // Merging the sorted buckets to obtain the sorted array
    int index = 0;
    for(int i=0; i<BUCKET_SIZE; i++) {
        for(int j=0; j<buckets[i][n]; j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    // Taking the array input from the user
    int arr[n];
    printf("Enter the elements of the array: ");
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Sorting the array using bucket sort
    bucketSort(arr, n);
    
    // Printing the sorted array
    printf("The sorted array is: ");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}