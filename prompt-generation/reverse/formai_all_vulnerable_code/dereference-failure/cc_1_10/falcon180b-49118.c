//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Bucket Sort Function
void bucket_sort(int arr[], int n, int max_val) {
    int bucket_size = max_val / n;
    int *buckets[n];

    // Initialize buckets
    for (int i = 0; i < n; i++) {
        buckets[i] = (int*) malloc(sizeof(int) * bucket_size);
    }

    // Place elements in buckets
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i] % max_val == j) {
                buckets[j][arr[i] / bucket_size] = arr[i];
            }
        }
    }

    // Concatenate sorted buckets
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucket_size; j++) {
            if (buckets[i][j]!= 0) {
                arr[index] = buckets[i][j];
                index++;
            }
        }
    }
}

int main() {
    int arr[] = { 5, 7, 2, 8, 1, 3, 9, 6, 4, 0 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int max_val = arr[0];

    // Find maximum value in array
    for (int i = 0; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    // Sort array using bucket sort
    bucket_sort(arr, n, max_val);

    // Print sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}