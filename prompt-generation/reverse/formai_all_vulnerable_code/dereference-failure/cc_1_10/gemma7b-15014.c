//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void bucket_sort(int **arr, int n)
{
    int i, j, k, bucket_size, **bucket, key;
    bucket_size = n / MAX;
    bucket = (int **)malloc(bucket_size * sizeof(int *));
    for (i = 0; i < bucket_size; i++)
    {
        bucket[i] = (int *)malloc(MAX * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        key = arr[i];
        bucket[key / MAX][key % MAX] = arr[i];
    }

    for (i = 0; i < bucket_size; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if (bucket[i][j] != NULL)
            {
                arr[k] = bucket[i][j];
                k++;
            }
        }
    }

    free(bucket);
}

int main()
{
    int n, i, **arr;
    scanf("Enter the number of elements: ", &n);
    arr = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        scanf("Enter the element: ", &arr[i]);
    }

    bucket_sort(arr, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
}