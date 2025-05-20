//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

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

    bucket_size = (max - min) / MAX_SIZE + 1;
    int **buckets = (int **)malloc(bucket_size * sizeof(int *));
    for (i = 0; i < bucket_size; i++)
    {
        buckets[i] = (int *)malloc(n * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        buckets[arr[i][0]]++;
    }

    for (i = 0; i < bucket_size; i++)
    {
        for (j = 0; j < buckets[i]; j++)
        {
            arr[j][0] = i;
        }
    }

    free(buckets);
}

int main()
{
    int **arr = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (int i = 0; i < MAX_SIZE; i++)
    {
        arr[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    // Fill the array with sample data
    arr[0][0] = 10;
    arr[0][1] = 20;
    arr[0][2] = 30;
    arr[0][3] = 40;
    arr[0][4] = 50;

    bucket_sort(arr, 1);

    // Print the sorted array
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    free(arr);

    return 0;
}