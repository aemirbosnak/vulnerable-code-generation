//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int *arr, int n)
{
    int i, j, k, bucket_size, **buckets;

    // Calculate the bucket size
    bucket_size = n / 10 + 1;

    // Create buckets
    buckets = (int **)malloc(bucket_size * sizeof(int *));
    for (i = 0; i < bucket_size; i++)
    {
        buckets[i] = (int *)malloc(n * sizeof(int));
    }

    // Distribute the elements into the buckets
    for (i = 0; i < n; i++)
    {
        k = arr[i] / bucket_size;
        buckets[k][i] = arr[i];
    }

    // Merge the buckets
    for (i = 0; i < bucket_size; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (buckets[i][j] != 0)
            {
                arr[j] = buckets[i][j];
            }
        }
    }

    // Free the buckets
    for (i = 0; i < bucket_size; i++)
    {
        free(buckets[i]);
    }
    free(buckets);
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n = sizeof(arr) / sizeof(int);

    bucket_sort(arr, n);

    printf("Sorted array:");
    for (int i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }

    printf("\n");

    return 0;
}