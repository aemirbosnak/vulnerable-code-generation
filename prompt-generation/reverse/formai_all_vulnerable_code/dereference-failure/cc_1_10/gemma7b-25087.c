//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void bucketSort(int **arr, int n)
{
    int i, j, k, bucketSize, *buckets, key;
    buckets = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        buckets[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        key = arr[i];
        buckets[key]++;
    }

    for (i = 1; i <= bucketSize; i++)
    {
        buckets[i] += buckets[i - 1];
    }

    for (i = n - 1; i >= 0; i--)
    {
        key = arr[i];
        arr[buckets[key] - 1] = key;
        buckets[key]--;
    }

    free(buckets);
}

int main()
{
    int n, i, *arr;
    srand(time(NULL));

    n = MAX;
    arr = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        arr[i] = rand() % n;
    }

    bucketSort(arr, n);

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    free(arr);

    return 0;
}