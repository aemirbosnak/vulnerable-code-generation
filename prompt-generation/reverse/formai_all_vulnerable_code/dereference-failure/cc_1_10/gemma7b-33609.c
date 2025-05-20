//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

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

    bucket_size = (max - min) / MAX + 1;
    bucket = (int **)malloc(bucket_size * sizeof(int *));
    for (i = 0; i < bucket_size; i++)
    {
        bucket[i] = (int *)malloc(n * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        bucket[arr[i][0]]++;
    }

    for (i = 0; i < bucket_size; i++)
    {
        for (j = 0; j < bucket[i]; j++)
        {
            arr[j][0] = i;
        }
    }

    free(bucket);
}

int main()
{
    int **arr = (int **)malloc(10 * sizeof(int *));
    for (int i = 0; i < 10; i++)
    {
        arr[i] = (int *)malloc(2 * sizeof(int));
    }

    arr[0][0] = 10;
    arr[0][1] = 20;
    arr[1][0] = 30;
    arr[1][1] = 40;
    arr[2][0] = 50;
    arr[2][1] = 60;

    bucket_sort(arr, 10);

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i][0]);
    }

    printf("\n");

    free(arr);

    return 0;
}