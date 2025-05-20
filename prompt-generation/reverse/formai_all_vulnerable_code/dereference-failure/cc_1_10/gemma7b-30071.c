//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void bucketSort(int *arr, int n)
{
    int i, j, k, bucketSize, **buckets;

    buckets = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        buckets[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        k = arr[i];
        buckets[k][0]++;
    }

    for (i = 0; i < n; i++)
    {
        buckets[i] = buckets[i] + buckets[i][0] - 1;
    }

    for (i = 0; i < n; i++)
    {
        arr[i] = buckets[i];
    }

    free(buckets);
}

int main()
{
    int arr[] = {1, 3, 5, 2, 4, 6, 7, 8, 9, 10};
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