//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

void bucketSort(int *arr, int n)
{
    int i, j, k, bucketSize, min, max;
    bucketSize = n / ARRAY_SIZE;
    min = arr[0];
    max = arr[0];
    for (i = 0; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    int *buckets = (int *)malloc(bucketSize * sizeof(int));
    for (i = 0; i < bucketSize; i++)
        buckets[i] = 0;

    for (i = 0; i < n; i++)
    {
        buckets[arr[i] / bucketSize]++;
    }

    int sortedArr[n];
    j = 0;
    for (i = 0; i < bucketSize; i++)
    {
        for (k = 0; k < buckets[i]; k++)
        {
            sortedArr[j++] = min + i * bucketSize;
        }
    }

    free(buckets);
    memcpy(arr, sortedArr, n * sizeof(int));
}

int main()
{
    int arr[] = {4, 3, 8, 6, 2, 5, 1, 9, 7, 3};
    int n = sizeof(arr) / sizeof(int);

    bucketSort(arr, n);

    printf("Sorted array:");
    for (int i = 0; i < n; i++)
        printf(" %d", arr[i]);

    printf("\n");

    return 0;
}