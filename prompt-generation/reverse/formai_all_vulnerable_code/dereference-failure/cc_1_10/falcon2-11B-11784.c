//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: realistic
#include<stdio.h>
#include<stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

void bucketSort(int arr[], int n)
{
    int i, j, k, min_elem;
    int *buckets;
    int bucket_size;

    buckets = (int*)malloc(n * sizeof(int));
    bucket_size = (int)ceil((double)n/2);
    for (i = 0; i < bucket_size; i++)
    {
        buckets[i] = -1;
    }

    for (i = 0; i < n; i++)
    {
        j = (arr[i] - min_elem) / bucket_size;
        if (buckets[j] == -1)
        {
            buckets[j] = arr[i];
        }
        else
        {
            while (buckets[j]!= -1 && buckets[j] < arr[i])
            {
                j++;
                if (j == bucket_size)
                {
                    j = 0;
                }
            }
            buckets[j] = arr[i];
        }
    }

    qsort(buckets, bucket_size, sizeof(int), compare);

    for (i = 0; i < n; i++)
    {
        arr[i] = buckets[i];
    }

    free(buckets);
}

int main()
{
    int arr[] = {3, 7, 8, 1, 2, 6, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}