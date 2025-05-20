//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void bucketSort(int arr[], int n)
{
    int i, j, k, max_val;
    int *bucket, *temp;

    // create buckets
    bucket = (int *)malloc(sizeof(int) * 1000);
    for (i = 0; i < 1000; i++)
        bucket[i] = 0;

    // fill buckets
    for (i = 0; i < n; i++)
    {
        if (bucket[arr[i]])
            bucket[arr[i]]++;
        else
            bucket[arr[i]] = 1;
    }

    // build a temp array to store elements of each bucket
    temp = (int *)malloc(sizeof(int) * n);

    // sort each bucket
    for (i = 1; i < 1000; i++)
        if (bucket[i])
        {
            max_val = arr[0];
            for (j = 1; j < n; j++)
            {
                if (arr[j] > max_val)
                    max_val = arr[j];
                temp[bucket[max_val] - 1] = max_val;
                bucket[max_val]++;
            }
            for (j = 0; j < n; j++)
                arr[j] = temp[j];
        }

    free(temp);
    free(bucket);
}

int main()
{
    int arr[] = {3, 7, 2, 8, 9, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    clock_t start, end;
    start = clock();

    bucketSort(arr, n);

    end = clock();
    double elapsed_secs = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %lf seconds\n", elapsed_secs);

    return 0;
}