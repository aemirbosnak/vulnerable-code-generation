//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

void bucketSort(int *arr, int n)
{
    int i, j, k, bucketSize, *bucket, **histogram = NULL;

    histogram = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
        histogram[i] = (int *)malloc(bucketSize * sizeof(int));

    bucketSize = n / MAX;
    for (i = 0; i < bucketSize; i++)
        for (j = 0; j < MAX; j++)
            histogram[i][j] = 0;

    for (i = 0; i < n; i++)
    {
        k = arr[i] / bucketSize;
        histogram[k][arr[i] % bucketSize]++;
    }

    for (i = 0; i < bucketSize; i++)
        for (j = 0; j < MAX; j++)
            if (histogram[i][j] > 0)
            {
                for (k = 0; k < histogram[i][j]; k++)
                    arr[i * MAX + k] = j * MAX + i;
            }

    free(histogram);
}

int main()
{
    int i, n, *arr;

    n = 1000;
    arr = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
        arr[i] = rand() % MAX;

    bucketSort(arr, n);

    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    free(arr);

    return 0;
}