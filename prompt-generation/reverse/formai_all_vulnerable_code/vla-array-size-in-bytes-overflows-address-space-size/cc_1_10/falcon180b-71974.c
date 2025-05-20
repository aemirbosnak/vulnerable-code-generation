//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void bucketSort(int arr[], int n) {
    int i, j, min, max;
    int *bucket[MAX_SIZE];

    // Initialize all buckets to NULL
    for (i = 0; i < MAX_SIZE; i++) {
        bucket[i] = NULL;
    }

    // Find the minimum and maximum values in the array
    min = arr[0];
    max = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Create the buckets
    for (i = 0; i < max - min + 1; i++) {
        bucket[i] = (int *) malloc(n * sizeof(int));
    }

    // Place the elements in the appropriate buckets
    for (i = 0; i < n; i++) {
        j = (arr[i] - min) / (max - min) * (MAX_SIZE - 1);
        bucket[j] = realloc(bucket[j], (++bucket[j][0]) * sizeof(int));
        bucket[j][bucket[j][0]] = arr[i];
    }

    // Concatenate the sorted buckets back into the original array
    i = 0;
    for (j = 0; j < MAX_SIZE; j++) {
        if (bucket[j]!= NULL) {
            for (int k = 0; k < bucket[j][0]; k++) {
                arr[i++] = bucket[j][k];
            }
            free(bucket[j]);
            bucket[j] = NULL;
        }
    }
}

int main() {
    int i, n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    bucketSort(arr, n);
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}