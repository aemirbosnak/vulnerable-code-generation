//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>

void bucketSort(int **arr, int n)
{
    int i, j, k, min, max, buckets[n], *tempArr;

    min = arr[0][0];
    max = arr[0][0];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 2; j++)
        {
            if (arr[i][j] < min)
                min = arr[i][j];

            if (arr[i][j] > max)
                max = arr[i][j];
        }
    }

    buckets[0] = (max - min) / n + 1;

    tempArr = (int *)malloc(buckets[0] * sizeof(int));

    for (i = 0; i < n; i++)
    {
        k = arr[i][0] - min;
        buckets[k]++;
    }

    for (i = 1; i < buckets[0]; i++)
    {
        buckets[i] += buckets[i - 1];
    }

    arr = (int **)realloc(arr, buckets[0] * sizeof(int *));

    for (i = 0; i < n; i++)
    {
        k = arr[i][0] - min;
        arr[buckets[k]] = arr[i];
        buckets[k]--;
    }

    free(tempArr);
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
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}