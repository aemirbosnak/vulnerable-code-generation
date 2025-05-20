//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void bucket_sort(int **arr, int n)
{
    int i, j, k, bucket_size, min, max;
    int *bucket = NULL;

    min = arr[0][0];
    max = arr[0][0];
    for (i = 0; i < n; i++)
    {
        min = fmin(min, arr[i][0]);
        max = fmax(max, arr[i][0]);
    }

    bucket_size = (max - min) / MAX_SIZE + 1;
    bucket = (int *)malloc(bucket_size * sizeof(int));
    for (i = 0; i < bucket_size; i++)
    {
        bucket[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        bucket[arr[i][0]]++;
    }

    for (i = 0; i < bucket_size; i++)
    {
        for (j = 0; j < bucket[i]; j++)
        {
            arr[k][0] = i * MAX_SIZE + j;
            k++;
        }
    }

    free(bucket);
}

int main()
{
    int **arr = NULL;
    int n = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    bucket_sort(arr, n);

    printf("Sorted elements: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            printf("%d ", arr[i][j]);
        }
    }

    return 0;
}