//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers
int compare(const void *a, const void *b) {
    // Cast the pointers back to integers and compare them
    return (*(int *)a - *(int *)b);
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    // Find the range of elements in the array
    int min = arr[0];
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Calculate the size of each bucket
    int bucketSize = (max - min) / n;

    // Create an array of empty buckets
    int *buckets[n];
    for (int i = 0; i < n; i++) {
        buckets[i] = malloc(sizeof(int) * bucketSize);
    }

    // Place each element in its corresponding bucket
    for (int i = 0; i < n; i++) {
        int bucketIndex = (arr[i] - min) / bucketSize;
        int *bucket = buckets[bucketIndex];
        int j = 0;
        while (j < bucketSize && bucket[j]!= 0) {
            j++;
        }
        bucket[j] = arr[i];
    }

    // Sort each bucket using insertion sort
    for (int i = 0; i < n; i++) {
        qsort(buckets[i], bucketSize, sizeof(int), compare);
    }

    // Merge the sorted buckets back into the original array
    int index = 0;
    for (int i = 0; i < n; i++) {
        int j = 0;
        while (j < bucketSize && buckets[i][j]!= 0) {
            arr[index++] = buckets[i][j++];
        }
    }
}

int main() {
    int arr[] = { 3, 2, 9, 1, 7, 5, 8, 6, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}