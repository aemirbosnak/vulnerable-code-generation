//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bucket_sort(int *arr, int n)
{
    int i, j, k, bucket_size = 10, **buckets = (int **)malloc(bucket_size * sizeof(int *));

    for (i = 0; i < bucket_size; i++)
    {
        buckets[i] = (int *)malloc(n * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        buckets[arr[i]]++;
    }

    for (i = 0; i < bucket_size; i++)
    {
        for (j = 0; j < buckets[i]; j++)
        {
            arr[k] = i + 1;
            k++;
        }
    }

    free(buckets);
}

int main()
{
    int n = 1000;
    int *arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % n;
    }

    bucket_sort(arr, n);

    printf("Sorted array:");
    for (int i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }

    free(arr);
    return 0;
}