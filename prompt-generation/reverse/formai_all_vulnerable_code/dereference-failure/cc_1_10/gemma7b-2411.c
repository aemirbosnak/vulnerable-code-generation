//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Define the bucket sort algorithm
void bucketSort(int *arr, int n)
{
    int i, j, k, bucketSize, **buckets;

    // Calculate the bucket size
    bucketSize = n / 10 + 1;

    // Create buckets
    buckets = (int **)malloc(bucketSize * sizeof(int *));
    for (i = 0; i < bucketSize; i++)
    {
        buckets[i] = (int *)malloc(n * sizeof(int));
    }

    // Distribute the elements into the buckets
    for (i = 0; i < n; i++)
    {
        buckets[arr[i]]++;
    }

    // Combine the buckets
    for (i = 0; i < bucketSize; i++)
    {
        for (j = 0; j < buckets[i]; j++)
        {
            buckets[i][j] = arr[j];
        }
    }

    // Free the buckets
    for (i = 0; i < bucketSize; i++)
    {
        free(buckets[i]);
    }
    free(buckets);
}

int main()
{
    int arr[] = {10, 7, 8, 9, 12, 2, 5, 3, 4, 6};
    int n = sizeof(arr) / sizeof(int);

    bucketSort(arr, n);

    printf("Sorted array:");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", arr[i]);
    }

    printf("\n");

    return 0;
}