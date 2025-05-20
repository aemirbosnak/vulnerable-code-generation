//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

void bucketSort(int arr[], int n) {
    int i, j, index, max, min;
    int *bucket[MAX_SIZE];

    // Find minimum and maximum values in the array
    max = arr[0];
    min = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    // Calculate the range of the array
    int range = max - min + 1;

    // Create an empty bucket array
    for (i = 0; i < MAX_SIZE; i++) {
        bucket[i] = (int *)malloc(sizeof(int) * range);
    }

    // Place each element in the appropriate bucket
    for (i = 0; i < n; i++) {
        index = (arr[i] - min) * range / (max - min);
        bucket[index][j] = arr[i];
        j++;
    }

    // Sort each bucket and concatenate them
    int k = 0;
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < range; j++) {
            arr[k++] = bucket[i][j];
        }
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