//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

void bucketSort(float arr[], int n) {
    int i, j;
    float *bucket = NULL;

    // Find the maximum value in the array
    float max_value = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max_value)
            max_value = arr[i];
    }

    // Create the buckets
    bucket = (float *)calloc((size_t)max_value + 1, sizeof(float));
    if (bucket == NULL) {
        printf("Memory allocation error.\n");
        return;
    }

    // Fill the buckets with the values from the array
    for (i = 0; i < n; i++) {
        bucket[(int)arr[i]]++;
    }

    // Sort the elements in each bucket
    for (i = 0, j = 0; i <= max_value; i++) {
        while (bucket[i] > 0) {
            arr[j++] = i;
            bucket[i]--;
        }
    }

    // Free the memory used by the bucket array
    free(bucket);
}

int main() {
    int n, i;
    float *arr = NULL;

    printf("Enter the number of elements to sort: ");
    scanf("%d", &n);

    // Allocate memory for the array
    arr = (float *)malloc(n * sizeof(float));
    if (arr == NULL) {
        printf("Memory allocation error.\n");
        return 0;
    }

    // Get input from the user
    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%f", &arr[i]);
    }

    // Sort the array
    bucketSort(arr, n);

    // Print the sorted array
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");

    // Free the memory used by the array
    free(arr);

    return 0;
}