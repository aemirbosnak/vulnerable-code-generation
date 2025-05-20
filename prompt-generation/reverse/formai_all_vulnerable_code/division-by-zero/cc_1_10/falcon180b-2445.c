//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Function to swap two integer elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

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
    int range = max / n;
    int* buckets[n];

    // Initialize buckets with -1
    for (int i = 0; i < n; i++) {
        buckets[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            buckets[i][j] = -1;
        }
    }

    // Place elements in appropriate buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] / range;
        buckets[bucketIndex][arr[i] % range] = arr[i];
    }

    // Concatenate buckets to get sorted array
    int j = 0;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            if (buckets[i][k]!= -1) {
                arr[j++] = buckets[i][k];
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));

    // Get array elements from user
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Perform bucket sort
    bucketSort(arr, n);

    // Print sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}