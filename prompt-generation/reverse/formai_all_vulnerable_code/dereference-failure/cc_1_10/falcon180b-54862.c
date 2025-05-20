//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// Function to get the maximum value in an array
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int max = getMax(arr, n);
    int bucketSize = max / n;
    int *bucket[MAX_SIZE];

    // Create empty buckets
    for (int i = 0; i < n; i++) {
        bucket[i] = (int *)malloc(sizeof(int) * bucketSize);
    }

    // Put elements in buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] / bucketSize;
        bucket[bucketIndex] = (int *)realloc(bucket[bucketIndex], sizeof(int) * (bucketIndex + 1));
        bucket[bucketIndex][bucketIndex] = arr[i];
    }

    // Sort buckets
    for (int i = 0; i < n; i++) {
        int j = 0;
        while (bucket[i][j]) {
            arr[j++] = bucket[i][j];
        }
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        free(bucket[i]);
    }
}

// Main function
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bucketSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}