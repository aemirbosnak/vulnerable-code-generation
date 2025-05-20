//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void bucket_sort(int arr[], int n)
{
    int i, j, k, bucket_size, min, max;
    bucket_size = MAX_SIZE;
    min = arr[0];
    max = arr[0];

    for (i = 1; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];

        if (arr[i] > max)
            max = arr[i];
    }

    int *buckets = (int *)malloc(bucket_size * sizeof(int));
    for (i = 0; i < bucket_size; i++)
        buckets[i] = 0;

    for (i = 0; i < n; i++)
    {
        buckets[arr[i]]++;
    }

    int sorted_arr[n];
    k = 0;
    for (i = 0; i < bucket_size; i++)
    {
        for (j = 0; j < buckets[i]; j++)
        {
            sorted_arr[k++] = min + i;
        }
    }

    free(buckets);

    printf("Sorted array:");
    for (i = 0; i < n; i++)
    {
        printf(", %d", sorted_arr[i]);
    }

    printf("\n");
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n = sizeof(arr) / sizeof(int);

    bucket_sort(arr, n);

    return 0;
}