//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int *arr, int n)
{
    int i, j, k, bucket_size, min, max;

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

    int *buckets = (int *)malloc(bucket_size * sizeof(int));

    for (i = 0; i < n; i++)
    {
        buckets[arr[i] - min] = 1;
    }

    int output[n];

    k = 0;
    for (i = 0; i < bucket_size; i++)
    {
        if (buckets[i] > 0)
        {
            for (j = 0; j < buckets[i]; j++)
            {
                output[k++] = min + i;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }

    free(buckets);
}

int main()
{
    int arr[] = {4, 3, 5, 2, 8, 9, 1, 7, 6};
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