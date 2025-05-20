//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void bucketSort(int **arr, int n)
{
    int i, j, k, bucketSize, key, min, max;

    min = arr[0][0];
    max = arr[0][0];

    for (i = 0; i < n; i++)
    {
        min = fmin(min, arr[i][0]);
        max = fmax(max, arr[i][0]);
    }

    bucketSize = (max - min) / MAX_SIZE + 1;

    int **buckets = (int **)malloc(bucketSize * sizeof(int *));

    for (i = 0; i < bucketSize; i++)
    {
        buckets[i] = (int *)malloc(n * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        key = arr[i][0] - min;
        buckets[key][i] = arr[i];
    }

    int **sortedArr = (int **)malloc(n * sizeof(int *));

    for (i = 0; i < n; i++)
    {
        sortedArr[i] = buckets[key][i];
    }

    free(buckets);
    free(sortedArr);
}

int main()
{
    int n = 5;
    int **arr = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(2 * sizeof(int));
    }

    arr[0][0] = 10;
    arr[0][1] = 20;
    arr[1][0] = 30;
    arr[1][1] = 40;
    arr[2][0] = 50;
    arr[2][1] = 60;
    arr[3][0] = 70;
    arr[3][1] = 80;
    arr[4][0] = 90;
    arr[4][1] = 100;

    bucketSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i][0]);
    }

    printf("\n");

    free(arr);

    return 0;
}