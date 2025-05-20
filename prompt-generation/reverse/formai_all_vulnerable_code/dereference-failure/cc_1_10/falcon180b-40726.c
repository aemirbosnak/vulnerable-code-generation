//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100000

void bucketSort(int arr[], int n) {
    int i, j, index;
    int *bucket[MAX_SIZE];

    // Allocate memory for buckets
    for (i = 0; i < n; i++) {
        bucket[arr[i] % n] = (int *) malloc(sizeof(int));
        *bucket[arr[i] % n] = 0;
    }

    // Place elements into buckets
    for (i = 0; i < n; i++) {
        index = arr[i] % n;
        *(bucket[index] + *(bucket[index])) = arr[i];
        *(bucket[index])++;
    }

    // Concatenate buckets and copy back to array
    j = 0;
    for (i = 0; i < n; i++) {
        index = arr[i] % n;
        while (*(bucket[index]) > 0) {
            arr[j++] = *(bucket[index] + --(*(bucket[index])));
        }
    }
}

int main() {
    int i, n;

    srand(time(NULL));
    n = rand() % 10000 + 1;

    int *arr = (int *) malloc(sizeof(int) * n);

    // Fill array with random numbers
    for (i = 0; i < n; i++) {
        arr[i] = rand() % MAX_SIZE;
    }

    // Print unsorted array
    printf("Unsorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort array using bucket sort
    bucketSort(arr, n);

    // Print sorted array
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}