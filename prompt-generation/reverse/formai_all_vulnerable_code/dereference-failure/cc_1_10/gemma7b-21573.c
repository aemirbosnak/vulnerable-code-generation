//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

void bucketSort(int **arr, int n)
{
    int i, j, k, bucketSize, min, max, **bucket, count = 0;

    min = arr[0][0];
    max = arr[0][0];

    for (i = 0; i < n; i++)
    {
        min = arr[i][0] < min ? arr[i][0] : min;
        max = arr[i][0] > max ? arr[i][0] : max;
    }

    bucketSize = (max - min) / MAX + 1;
    bucket = (int *)malloc(bucketSize * sizeof(int));

    for (i = 0; i < bucketSize; i++)
    {
        bucket[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        bucket[arr[i][0] - min]++;
    }

    for (i = 0; i < bucketSize; i++)
    {
        for (j = 0; j < bucket[i]; j++)
        {
            arr[count][0] = min + i;
            count++;
        }
    }

    free(bucket);
}

int main()
{
    int n, i, **arr;

    scanf("Enter the number of elements: ", &n);

    arr = (int **)malloc(n * sizeof(int *));

    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(MAX * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        printf("Enter the elements: ");
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    bucketSort(arr, n);

    printf("Sorted elements: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i][0]);
    }

    return 0;
}