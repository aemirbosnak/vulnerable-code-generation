//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void bucket_sort(int **arr, int n)
{
    int i, j, k, bucket_size, min, max, *bucket;

    min = arr[0][0];
    max = arr[0][0];

    for (i = 0; i < n; i++)
    {
        min = arr[i][0] < min ? arr[i][0] : min;
        max = arr[i][0] > max ? arr[i][0] : max;
    }

    bucket_size = (max - min) / MAX + 1;
    bucket = (int *)malloc(bucket_size * sizeof(int));

    for (i = 0; i < n; i++)
    {
        k = (arr[i][0] - min) / MAX;
        bucket[k]++;
    }

    for (i = 0; i < bucket_size; i++)
    {
        for (j = 0; bucket[j] > 0; j++)
        {
            arr[j][0] = min + MAX * i;
            bucket[j]--;
        }
    }

    free(bucket);
}

int main()
{
    int **arr = (int **)malloc(10 * sizeof(int *));
    int n = 10;

    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(2 * sizeof(int));
    }

    arr[0][0] = 5;
    arr[1][0] = 3;
    arr[2][0] = 8;
    arr[3][0] = 2;
    arr[4][0] = 4;
    arr[5][0] = 7;
    arr[6][0] = 9;
    arr[7][0] = 1;
    arr[8][0] = 6;
    arr[9][0] = 3;

    bucket_sort(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i][0]);
    }

    printf("\n");

    for (int i = 0; i < n; i++)
    {
        free(arr[i]);
    }

    free(arr);

    return 0;
}