//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int *arr, int n)
{
    int i, j, k, bucket_size, **buckets;

    bucket_size = n / 10 + 1;
    buckets = (int **)malloc(bucket_size * sizeof(int *));
    for (i = 0; i < bucket_size; i++)
        buckets[i] = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        k = arr[i] / bucket_size;
        buckets[k][i] = arr[i];
    }

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

    for (i = 0; i < n; i++)
    {
        buckets[i] = NULL;
    }
    free(buckets);
}

int main()
{
    int arr[] = {1, 3, 5, 2, 4, 6, 3, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(int);

    bucket_sort(arr, n);

    printf("Sorted array:");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", arr[i]);
    }

    printf("\n");

    return 0;
}