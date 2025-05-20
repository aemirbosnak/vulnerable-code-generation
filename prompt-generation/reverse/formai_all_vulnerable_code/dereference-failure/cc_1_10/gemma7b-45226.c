//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int **arr, int n)
{
    int i, j, k, bucket_size, min, max;

    min = arr[0][0];
    max = arr[0][0];

    for (i = 0; i < n; i++)
    {
        min = arr[i][0] < min ? arr[i][0] : min;
        max = arr[i][0] > max ? arr[i][0] : max;
    }

    bucket_size = (max - min) / n + 1;

    int **buckets = (int **)malloc(n * sizeof(int *));

    for (i = 0; i < n; i++)
    {
        buckets[i] = (int *)malloc(bucket_size * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        buckets[arr[i][0]]++;
    }

    int **sorted_arr = (int **)malloc(n * sizeof(int *));

    for (i = 0; i < n; i++)
    {
        sorted_arr[i] = (int *)malloc(bucket_size * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        sorted_arr[arr[i][0]]++;
    }

    for (i = 0; i < n; i++)
    {
        sorted_arr[i][0] = arr[i][0];
    }

    free(buckets);
    free(sorted_arr);
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
    arr[3][0] = 70;
    arr[3][1] = 80;
    arr[4][0] = 90;
    arr[4][1] = 100;

    bucket_sort(arr, 10);

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i][0]);
    }

    printf("\n");

    free(arr);

    return 0;
}