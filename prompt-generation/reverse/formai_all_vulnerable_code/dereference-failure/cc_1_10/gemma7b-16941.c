//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void bucketSort(int **arr, int n)
{
    int i, j, k, bucketSize, min, max;

    min = arr[0][0];
    max = arr[0][1];

    for (i = 0; i < n; i++)
    {
        if (arr[i][0] < min)
            min = arr[i][0];

        if (arr[i][1] > max)
            max = arr[i][1];
    }

    bucketSize = (max - min) / MAX + 1;

    int **buckets = (int **)malloc(bucketSize * sizeof(int *));
    for (i = 0; i < bucketSize; i++)
        buckets[i] = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        buckets[arr[i][0]]++;
    }

    for (i = 0; i < bucketSize; i++)
    {
        for (j = 0; j < buckets[i]; j++)
        {
            arr[j][0] = i;
        }
    }

    free(buckets);
}

int main()
{
    int **arr = (int **)malloc(MAX * sizeof(int *));
    for (int i = 0; i < MAX; i++)
        arr[i] = (int *)malloc(2 * sizeof(int));

    arr[0][0] = 10;
    arr[0][1] = 20;
    arr[1][0] = 15;
    arr[1][1] = 25;
    arr[2][0] = 22;
    arr[2][1] = 30;

    bucketSort(arr, MAX);

    for (int i = 0; i < MAX; i++)
    {
        printf("arr[%d][0] = %d, arr[%d][1] = %d\n", i, arr[i][0], arr[i][1]);
    }

    free(arr);

    return 0;
}