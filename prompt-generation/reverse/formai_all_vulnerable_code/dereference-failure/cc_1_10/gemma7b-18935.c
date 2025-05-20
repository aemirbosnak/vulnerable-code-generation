//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int **arr, int n)
{
    int i, j, k, bucket_size, min, max, **bucket;

    min = arr[0][0];
    max = arr[0][0];
    for (i = 0; i < n; i++)
    {
        min = fmin(min, arr[i][0]);
        max = fmax(max, arr[i][0]);
    }

    bucket_size = (max - min) / 10 + 1;
    bucket = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        bucket[i] = (int *)malloc(bucket_size * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        k = arr[i][0] - min;
        bucket[k][0] = arr[i][0];
    }

    for (i = 0; i < n; i++)
    {
        arr[i][0] = bucket[k][0];
    }

    for (i = 0; i < n; i++)
    {
        free(bucket[i]);
    }
    free(bucket);
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