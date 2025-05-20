//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int *buckets, count, i;
    int maxVal, minVal;
    int *temp = (int*)malloc(n * sizeof(int));

    // Calculate max and min values in the array
    maxVal = arr[0];
    minVal = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }

    // Allocate memory for buckets
    buckets = (int*)malloc((maxVal - minVal + 1) * sizeof(int));
    for (count = 0; count <= maxVal - minVal; count++) {
        buckets[count] = 0;
    }

    // Put elements into respective buckets
    for (i = 0; i < n; i++) {
        buckets[arr[i] - minVal]++;
    }

    // Reorder the array by filling the buckets in reverse order
    for (count = maxVal - minVal; count >= 0; count--) {
        for (i = 0; i < buckets[count]; i++) {
            temp[i] = arr[count];
            arr[count] = temp[i];
        }
    }

    // Free memory
    free(buckets);
    free(temp);
}

int main() {
    int arr[] = {5, 2, 8, 1, 9, 3, 6, 7, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}