//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Function to sort an array in ascending order using bucket sort
void bucketSort(int *arr, int n)
{
    // Calculate the maximum number of buckets
    int maxBucketSize = arr[0] + 1;

    // Create buckets
    int **buckets = (int **)malloc(maxBucketSize * sizeof(int *));
    for (int i = 0; i < maxBucketSize; i++)
    {
        buckets[i] = (int *)malloc(n * sizeof(int));
    }

    // Distribute elements into buckets
    for (int i = 0; i < n; i++)
    {
        buckets[arr[i]]++;
    }

    // Merge buckets into one sorted array
    int i = 0, j = 0;
    for (int k = 0; k < maxBucketSize; k++)
    {
        while (buckets[k] > 0)
        {
            arr[i] = k;
            buckets[k]--;
            i++;
        }
    }

    // Free buckets
    for (int i = 0; i < maxBucketSize; i++)
    {
        free(buckets[i]);
    }
    free(buckets);
}

int main()
{
    int arr[] = {4, 3, 5, 2, 8, 9, 1, 7, 6};
    int n = sizeof(arr) / sizeof(int);

    bucketSort(arr, n);

    printf("Sorted array:");
    for (int i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }

    printf("\n");

    return 0;
}