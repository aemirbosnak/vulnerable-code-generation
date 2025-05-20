//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum element in an array
int findMax(int arr[], int n) {
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
    int max = findMax(arr, n);
    int bucketSize = max / n;
    int *buckets[n];
    for (int i = 0; i < n; i++) {
        buckets[i] = (int *)malloc(bucketSize * sizeof(int));
        for (int j = 0; j < bucketSize; j++) {
            buckets[i][j] = -1;
        }
    }
    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] / bucketSize;
        int j = 0;
        while (buckets[bucketIndex][j]!= -1) {
            j++;
        }
        buckets[bucketIndex][j] = arr[i];
    }
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketSize; j++) {
            if (buckets[i][j]!= -1) {
                arr[k++] = buckets[i][j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        free(buckets[i]);
    }
}

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
    printf("\n");
    return 0;
}