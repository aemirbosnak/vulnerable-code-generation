//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort an array using bucket sort
void bucketSort(int arr[], int n) {
    int i, j, max, min, range;
    int bucket[MAX_SIZE]; // Initialize all buckets to empty
    
    // Find the range of the array
    max = arr[0];
    min = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }
    range = max - min + 1; // +1 for inclusive
    
    // Create buckets
    for (i = 0; i < range; i++) {
        bucket[i] = 0;
    }
    
    // Put elements in appropriate buckets
    for (i = 0; i < n; i++) {
        bucket[arr[i] - min]++;
    }
    
    // Sort the array
    for (i = 0; i < range; i++) {
        for (j = 0; j < bucket[i]; j++) {
            arr[j + i * MAX_SIZE] = i + min;
        }
    }
}

int main() {
    int arr[] = { 5, 2, 8, 1, 9, 3, 7, 6, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Sort the array using bucket sort
    bucketSort(arr, n);
    
    // Print the sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}