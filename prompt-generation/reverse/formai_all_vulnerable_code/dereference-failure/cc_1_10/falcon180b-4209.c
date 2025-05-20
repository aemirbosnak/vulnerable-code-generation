//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void bucket_sort(int arr[], int n) {
    int i, j, k, max, min;
    int *bucket[MAX_SIZE];
    int count[MAX_SIZE] = {0};

    // Find the range of the array
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

    // Calculate the size of each bucket
    int bucket_size = (max - min) / n;

    // Create the buckets
    for (i = 0; i < n; i++) {
        bucket[i] = (int *) malloc(sizeof(int) * (n + 1));
    }

    // Put the elements into the buckets
    for (i = 0; i < n; i++) {
        k = (arr[i] - min) / bucket_size;
        bucket[k] = realloc(bucket[k], sizeof(int) * (count[k] + 1));
        bucket[k][count[k]++] = arr[i];
    }

    // Concatenate the sorted buckets
    int index = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < count[i]; j++) {
            arr[index++] = bucket[i][j];
        }
    }

    // Free the memory
    for (i = 0; i < n; i++) {
        free(bucket[i]);
    }
}

int main() {
    int arr[] = {3, 2, 1, 5, 4};
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