//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform Bucket Sort
void bucket_sort(int arr[], int n) {
    int *buckets = (int*)malloc(sizeof(int) * n);
    int i, j, k, bucket;

    // Initialize buckets
    for (i = 0; i < n; i++) {
        buckets[i] = 0;
    }

    // Insert elements into buckets
    for (i = 0; i < n; i++) {
        bucket = arr[i] % n;
        buckets[bucket]++;
    }

    // Sort each bucket
    for (bucket = 0; bucket < n; bucket++) {
        for (i = 0; i < buckets[bucket]; i++) {
            for (j = i + 1; j < buckets[bucket]; j++) {
                if (arr[j] < arr[i]) {
                    k = arr[i];
                    arr[i] = arr[j];
                    arr[j] = k;
                }
            }
        }
    }

    // Output sorted array
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    srand(time(NULL)); // Seed random number generator
    int n, i;
    int *arr = (int*)malloc(sizeof(int) * 100);

    // Generate random array
    for (i = 0; i < 100; i++) {
        arr[i] = rand() % 100;
    }

    // Perform Bucket Sort
    bucket_sort(arr, n);

    return 0;
}