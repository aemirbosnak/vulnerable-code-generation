//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 1000000
#define BUCKET_SIZE 10

int main() {
    int i, j, n, *arr, *bucket[BUCKET_SIZE];
    float range;

    // Allocate memory for the array and initialize the elements with random values
    arr = (int *)malloc(SIZE * sizeof(int));
    srand(time(NULL));
    for (i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
    }

    // Find the range of the array
    range = *arr;
    for (i = 1; i < SIZE; i++) {
        if (arr[i] < range) {
            range = arr[i];
        }
    }

    // Calculate the number of buckets
    n = ceil(SIZE / BUCKET_SIZE);

    // Create the buckets
    for (i = 0; i < n; i++) {
        bucket[i] = (int *)malloc(BUCKET_SIZE * sizeof(int));
    }

    // Sort the array using bucket sort
    for (i = 0; i < SIZE; i++) {
        j = (int)floor(arr[i] / range * n);
        bucket[j] = (int *)realloc(bucket[j], BUCKET_SIZE * sizeof(int) * (1 + (i + 1) / BUCKET_SIZE));
        bucket[j][i / BUCKET_SIZE] = arr[i];
    }

    // Merge the buckets
    for (i = 0; i < n; i++) {
        for (j = 0; j < BUCKET_SIZE; j++) {
            arr[i * BUCKET_SIZE + j] = bucket[i][j];
        }
    }

    // Free the memory allocated for the buckets
    for (i = 0; i < n; i++) {
        free(bucket[i]);
    }

    // Print the sorted array
    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}