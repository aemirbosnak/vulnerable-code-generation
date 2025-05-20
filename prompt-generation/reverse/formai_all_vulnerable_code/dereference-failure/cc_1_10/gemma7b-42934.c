//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int *arr, int n)
{
    int i, j, k, bucket_size, **buckets;

    bucket_size = n / 10 + 1;
    buckets = (int **)malloc(bucket_size * sizeof(int *));

    for (i = 0; i < bucket_size; i++)
    {
        buckets[i] = (int *)malloc(n * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        k = arr[i] / bucket_size;
        buckets[k][i] = arr[i];
    }

    for (i = 0; i < bucket_size; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (buckets[i][j] != 0)
            {
                arr[j] = buckets[i][j];
            }
        }
    }

    free(buckets);
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47, 49, 51, 53, 55, 57, 59, 61, 63, 65, 67, 69, 71, 73, 75, 77, 79, 81, 83, 85, 87, 89, 91, 93, 95, 97, 99};
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