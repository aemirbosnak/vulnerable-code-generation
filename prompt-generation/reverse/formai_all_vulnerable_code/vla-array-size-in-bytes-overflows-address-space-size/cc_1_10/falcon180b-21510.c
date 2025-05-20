//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void bucketSort(int arr[], int n) {
    int i, j, max, min, temp;
    int bucket[MAX_SIZE] = {0};

    // Find the maximum and minimum values in the array
    max = arr[0];
    min = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    // Calculate the range of the array
    max = max - min + 1;

    // Create buckets and distribute the elements into them
    for (i = 0; i < n; i++) {
        bucket[arr[i] - min]++;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < bucket[arr[i] - min]; j++) {
            printf("%d ", arr[i]);
        }
    }
}

void main() {
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements: ");

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bucketSort(arr, n);
}