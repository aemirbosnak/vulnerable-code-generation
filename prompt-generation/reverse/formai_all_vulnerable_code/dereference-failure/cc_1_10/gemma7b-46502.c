//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int **arr, int n)
{
    int i, j, k, bucket_size, min, max;
    min = arr[0][0];
    max = arr[0][0];
    for (i = 0; i < n; i++)
    {
        min = fmin(min, arr[i][0]);
        max = fmax(max, arr[i][0]);
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
    for (i = 0; i < bucket_size; i++)
    {
        for (j = 0; j < buckets[i]; j++)
        {
            arr[k][0] = i + min;
            k++;
        }
    }
    free(buckets);
}

int main()
{
    int **arr = (int **)malloc(10 * sizeof(int *));
    for (int i = 0; i < 10; i++)
    {
        arr[i] = (int *)malloc(2 * sizeof(int));
    }
    arr[0][0] = 2;
    arr[0][1] = 4;
    arr[1][0] = 5;
    arr[1][1] = 6;
    arr[2][0] = 3;
    arr[2][1] = 7;
    bucket_sort(arr, 10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i][0]);
    }
    printf("\n");
    free(arr);
    return 0;
}