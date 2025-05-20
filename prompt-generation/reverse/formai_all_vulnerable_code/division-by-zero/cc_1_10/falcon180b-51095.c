//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: thoughtful
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

    // Create empty buckets
    for (int i = 0; i < n; i++) {
        buckets[i] = (int*) malloc(sizeof(int) * bucketSize);
    }

    // Insert elements into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] / bucketSize;
        int j = 0;
        while (j < bucketSize && (j == 0 || buckets[i][j - 1] <= arr[i])) {
            j++;
        }
        for (int k = bucketSize - 1; k > j; k--) {
            buckets[i][k] = buckets[i][k - 1];
        }
        buckets[i][j] = arr[i];
    }

    // Merge the sorted buckets back into the original array
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketSize; j++) {
            arr[index++] = buckets[i][j];
        }
    }

    // Free the memory used by the buckets
    for (int i = 0; i < n; i++) {
        free(buckets[i]);
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
    printf("\n");

    return 0;
}