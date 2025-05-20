//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void bucket_sort(int **arr, int n)
{
    int i, j, k, bucket_size, *bucket, **sorted_arr;

    sorted_arr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
        sorted_arr[i] = (int *)malloc(MAX * sizeof(int));

    bucket_size = MAX;
    bucket = (int *)malloc(bucket_size * sizeof(int));
    for (i = 0; i < bucket_size; i++)
        bucket[i] = 0;

    for (i = 0; i < n; i++)
    {
        k = arr[i];
        bucket[k]++;
    }

    for (i = 1; i < bucket_size; i++)
    {
        bucket[i] += bucket[i - 1];
    }

    for (i = n - 1; i >= 0; i--)
    {
        k = arr[i];
        sorted_arr[bucket[k] - 1] = &arr[i];
        bucket[k]--;
    }

    for (i = 0; i < n; i++)
    {
        printf("%d ", sorted_arr[i]);
    }

    free(bucket);
    free(sorted_arr);
}

int main()
{
    int n, i, **arr;

    scanf("Enter the number of elements: ", &n);

    arr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
        arr[i] = (int *)malloc(MAX * sizeof(int));

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%d ", &arr[i][0]);

    bucket_sort(arr, n);

    printf("\nSorted elements: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i][0]);

    free(arr);

    return 0;
}