//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int *arr, int n)
{
    int i, j, k, min, max, bucket_size, **buckets;

    min = arr[0];
    max = arr[0];
    for (i = 1; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    bucket_size = (max - min) / n + 1;
    buckets = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
        buckets[i] = (int *)malloc(bucket_size * sizeof(int));

    for (i = 0; i < n; i++)
    {
        buckets[arr[i] - min][arr[i]] = 1;
    }

    for (i = 0; i < n; i++)
    {
        arr[i] = buckets[arr[i] - min][arr[i]] + min;
    }

    free(buckets);
}

int main()
{
    int arr[] = {1, 3, 5, 2, 4, 6, 3, 2, 4, 7, 5};
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