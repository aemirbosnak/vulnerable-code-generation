//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

// Define the function for bucket sort
void bucketSort(int arr[], int n) {
    int bucketSize = 1000;
    int *buckets = (int *)malloc(bucketSize * sizeof(int));
    int *counts = (int *)malloc(bucketSize * sizeof(int));

    for (int i = 0; i < bucketSize; i++) {
        buckets[i] = 0;
        counts[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int key = arr[i];
        int index = key % bucketSize;
        buckets[index]++;
        counts[index]++;
    }

    int totalBuckets = 0;
    int totalElements = 0;
    for (int i = 0; i < bucketSize; i++) {
        totalBuckets += counts[i];
        totalElements += buckets[i];
    }

    int *temp = (int *)malloc(totalElements * sizeof(int));
    int index = 0;
    for (int i = 0; i < bucketSize; i++) {
        for (int j = 0; j < buckets[i]; j++) {
            temp[index] = i;
            index++;
        }
    }

    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }

    free(buckets);
    free(counts);
    free(temp);
}

// Define the function for quicksort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[(low + high) / 2];
        int i = low;
        int j = high;

        while (i < j) {
            while (arr[i] < pivot) {
                i++;
            }
            while (arr[j] > pivot) {
                j--;
            }
            if (i <= j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
            }
        }
        if (j > low) {
            quickSort(arr, low, j);
        }
        if (i < high) {
            quickSort(arr, i, high);
        }
    }
}

int main() {
    int arr[] = {5, 2, 8, 1, 9, 4, 6, 3, 7, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);
    bucketSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}