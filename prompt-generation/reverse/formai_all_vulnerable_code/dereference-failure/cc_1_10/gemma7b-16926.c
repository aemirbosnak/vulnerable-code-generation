//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>

void bucketSort(int *arr, int n)
{
    int i, j, k, bucketSize, *bucket, **histogram = NULL;

    bucketSize = n / 10 + 1;
    bucket = (int *)malloc(bucketSize * sizeof(int));
    histogram = (int **)malloc(bucketSize * sizeof(int *));

    for (i = 0; i < bucketSize; i++)
    {
        histogram[i] = (int *)malloc(n * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        k = arr[i] / bucketSize;
        histogram[k][i] = arr[i];
    }

    for (i = 0; i < bucketSize; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (histogram[i][j] != 0)
            {
                arr[j] = histogram[i][j];
            }
        }
    }

    free(bucket);
    free(histogram);
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
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