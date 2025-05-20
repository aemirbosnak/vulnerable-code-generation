//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void bucket_sort(int arr[], int n)
{
    int i, j, k, bucket_size, *bucket;

    // Calculate the bucket size
    bucket_size = n / MAX;

    // Allocate the bucket
    bucket = (int *)malloc(bucket_size * MAX * sizeof(int));

    // Distribute the elements into the buckets
    for (i = 0; i < n; i++)
    {
        k = arr[i] / bucket_size;
        bucket[k] = bucket[k] + 1;
    }

    // Merge the buckets
    for (j = 0; j < bucket_size; j++)
    {
        for (i = 0; i < bucket[j]; i++)
        {
            arr[i] = j * bucket_size + i;
        }
    }

    // Free the bucket
    free(bucket);
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n = sizeof(arr) / sizeof(int);

    bucket_sort(arr, n);

    printf("Sorted array:");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", arr[i]);
    }

    return 0;
}