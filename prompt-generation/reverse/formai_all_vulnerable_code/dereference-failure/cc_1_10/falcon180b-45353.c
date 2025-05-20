//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAX 10000

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void bucketSort(int arr[], int n) {
    int i, j, k;
    int min, max;
    int* bucket[MAX];

    // Find minimum and maximum elements
    min = arr[0];
    max = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] < min)
            min = arr[i];
        else if (arr[i] > max)
            max = arr[i];
    }

    // Create empty buckets
    for (i = 0; i < MAX; i++) {
        bucket[i] = (int*) malloc(sizeof(int) * n);
    }

    // Place elements in buckets
    for (i = 0; i < n; i++) {
        k = (arr[i] - min) * MAX / (max - min);
        bucket[k] = (int*) realloc(bucket[k], sizeof(int) * (j + 1));
        bucket[k][j] = arr[i];
    }

    // Concatenate sorted buckets
    j = 0;
    for (i = 0; i < MAX; i++) {
        for (k = 0; k < j; k++) {
            arr[k] = bucket[i][k];
        }
        j += j;
    }

    // Free memory
    for (i = 0; i < MAX; i++) {
        free(bucket[i]);
    }
}

int main() {
    int n;
    srand(time(NULL));
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];

    // Generate random elements
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    // Print unsorted array
    printf("Unsorted array: ");
    printArray(arr, n);

    // Sort array using bucket sort
    bucketSort(arr, n);

    // Print sorted array
    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}