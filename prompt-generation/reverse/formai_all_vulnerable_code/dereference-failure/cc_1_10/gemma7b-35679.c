//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void bucket_sort(int *arr, int n)
{
    int i, j, k, bucket_size, **buckets;

    buckets = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        buckets[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        buckets[arr[i]]++;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; buckets[i] > 0; j++)
        {
            arr[k] = arr[i];
            buckets[i]--;
            k++;
        }
    }

    free(buckets);
}

int main()
{
    int arr[] = {4, 3, 5, 2, 8, 9, 1, 7, 6, 0};
    int n = sizeof(arr) / sizeof(int);

    bucket_sort(arr, n);

    printf("Sorted array:");
    for (int i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }

    printf("\n");

    return 0;
}