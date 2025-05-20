//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void bucketSort(int arr[], int n)
{
    int i, j, k, bucketSize, *bucket, min, max;

    min = arr[0];
    max = arr[0];
    for (i = 1; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    bucketSize = (max - min) / MAX_SIZE + 1;
    bucket = (int *)malloc(bucketSize * sizeof(int));

    for (i = 0; i < n; i++)
    {
        k = (arr[i] - min) / bucketSize;
        bucket[k]++;
    }

    for (i = 0; i < bucketSize; i++)
    {
        for (j = 0; bucket[j] > 0; j++)
        {
            arr[i] = min + j * bucketSize;
            bucket[j]--;
        }
    }

    free(bucket);
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
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