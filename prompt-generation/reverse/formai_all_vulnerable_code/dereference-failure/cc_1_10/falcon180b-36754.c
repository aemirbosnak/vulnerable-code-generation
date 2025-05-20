//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to find the maximum value in an array
int find_max(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform the bucket sort
void bucket_sort(int arr[], int n) {
    int max = find_max(arr, n);
    int *buckets = malloc(max * sizeof(int));
    for (int i = 0; i < max; i++) {
        buckets[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int bucket = arr[i] / max;
        buckets[bucket]++;
    }
    for (int i = 0; i < max; i++) {
        for (int j = 0; j < buckets[i]; j++) {
            arr[j * max + i] = i * max;
        }
    }
    free(buckets);
}

int main() {
    int arr[] = { 5, 2, 8, 3, 1, 9, 6, 7, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Before sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    bucket_sort(arr, n);
    printf("After sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}