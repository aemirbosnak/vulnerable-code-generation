//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

void bucketSort(int arr[], int n) {
    int i, j, max, min, range, bucket[MAX_SIZE];

    // Find the maximum and minimum values in the array
    max = arr[0];
    min = arr[0];
    for (i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    // Calculate the range and the size of each bucket
    range = max - min + 1;
    for (i = 0; i < MAX_SIZE; i++) {
        bucket[i] = 0;
    }

    // Place each element in its corresponding bucket
    for (i = 0; i < n; i++) {
        j = (arr[i] - min) / range * MAX_SIZE;
        bucket[j]++;
    }

    // Modify the array to store the sorted values
    for (i = 0; i < n; i++) {
        j = (arr[i] - min) / range * MAX_SIZE;
        arr[i] = min + j * range;
    }
}

int main() {
    int i, n;
    srand(time(0));

    // Generate a random array of integers
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    // Print the unsorted array
    printf("Unsorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort the array using bucket sort
    bucketSort(arr, n);

    // Print the sorted array
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}