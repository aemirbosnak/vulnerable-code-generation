//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    // Create an array of n buckets, where each bucket contains an array of size 1
    int **buckets = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        buckets[i] = (int *)malloc(1 * sizeof(int));
    }
    
    // Populate each bucket with elements from arr
    for (int i = 0; i < n; i++) {
        int key = arr[i];
        int bucket = 0;
        while (bucket < n && arr[bucket] < key) {
            bucket++;
        }
        buckets[bucket][0] = key;
    }
    
    // Merge the elements in each bucket into arr
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int *temp = buckets[i];
            buckets[i] = buckets[j];
            buckets[j] = temp;
        }
    }
    
    // Free memory
    for (int i = 0; i < n; i++) {
        free(buckets[i]);
    }
    free(buckets);
}

int main() {
    // Generate random array
    srand(time(NULL));
    int n = 10;
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    
    // Perform bucket sort
    bucketSort(arr, n);
    
    // Print sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Free memory
    free(arr);
    
    return 0;
}