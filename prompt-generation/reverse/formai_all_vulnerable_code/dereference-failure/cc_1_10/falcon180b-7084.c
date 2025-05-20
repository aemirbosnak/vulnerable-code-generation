//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to find the maximum element in an array
int find_max(int arr[], int n) {
    int max = arr[0];
    for(int i=1; i<n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform bucket sort
void bucket_sort(int arr[], int n) {
    int max = find_max(arr, n);
    int* buckets = (int*)malloc(MAX_SIZE*sizeof(int));
    for(int i=0; i<MAX_SIZE; i++) {
        buckets[i] = 0;
    }

    // Place elements in appropriate buckets
    for(int i=0; i<n; i++) {
        int bucket_index = arr[i]/MAX_SIZE;
        buckets[bucket_index]++;
    }

    // Combine elements from buckets
    int index = 0;
    for(int i=0; i<MAX_SIZE; i++) {
        for(int j=0; j<buckets[i]; j++) {
            arr[index] = i*MAX_SIZE + j;
            index++;
        }
    }
}

int main() {
    int arr[] = {5, 3, 1, 8, 2, 6, 9, 7, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Before sorting:\n");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucket_sort(arr, n);

    printf("After sorting:\n");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}