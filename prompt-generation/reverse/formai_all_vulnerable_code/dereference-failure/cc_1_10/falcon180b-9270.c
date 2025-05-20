//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000
#define MAX_VALUE 1000

void bucketSort(int arr[], int n) {
    int i, j, max_val, min_val;
    int *bucket[MAX_SIZE];

    // Find minimum and maximum values in array
    min_val = arr[0];
    max_val = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] < min_val)
            min_val = arr[i];
        if (arr[i] > max_val)
            max_val = arr[i];
    }

    // Create empty buckets
    for (i = 0; i < MAX_SIZE; i++) {
        bucket[i] = (int *) malloc(MAX_VALUE * sizeof(int));
        for (j = 0; j < MAX_VALUE; j++)
            bucket[i][j] = 0;
    }

    // Place elements in appropriate buckets
    for (i = 0; i < n; i++) {
        int index = (arr[i] - min_val) * MAX_VALUE / (max_val - min_val);
        bucket[index][bucket[index][0]++] = arr[i];
    }

    // Concatenate sorted buckets
    int k = 0;
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < bucket[i][0]; j++) {
            arr[k++] = bucket[i][j];
        }
    }
}

int main() {
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bucketSort(arr, n);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}