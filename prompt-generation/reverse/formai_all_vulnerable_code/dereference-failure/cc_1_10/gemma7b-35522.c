//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Define the bucket sort function
void bucketSort(int *arr, int n)
{
    int i, j, k, bucketSize = 10, **buckets = NULL;

    // Allocate memory for buckets
    buckets = (int **)malloc(sizeof(int *) * bucketSize);
    for (i = 0; i < bucketSize; i++)
    {
        buckets[i] = (int *)malloc(sizeof(int) * n);
    }

    // Distribute elements into buckets
    for (i = 0; i < n; i++)
    {
        buckets[arr[i]]++;
    }

    // Merge buckets into one array
    k = 0;
    for (i = 0; i < bucketSize; i++)
    {
        for (j = 0; j < buckets[i]; j++)
        {
            arr[k++] = i;
        }
    }

    // Free memory
    for (i = 0; i < bucketSize; i++)
    {
        free(buckets[i]);
    }
    free(buckets);
}

int main()
{
    int arr[] = {4, 3, 5, 2, 8, 6, 1, 9, 7, 0};
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