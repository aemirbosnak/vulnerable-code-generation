//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k;
    int arr[100], arr2[100], key;
    int bsize, num_buckets;
    int *bucket_arr;

    // Input size of the array
    scanf("%d", &n);

    // Input elements of the array
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);

    // Compute number of buckets
    num_buckets = n / bsize;
    if(n % bsize!= 0)
        num_buckets++;

    // Initialize the bucket array
    bucket_arr = (int *)malloc(sizeof(int)*num_buckets);

    // Create buckets
    for(i=0; i<num_buckets; i++)
    {
        bucket_arr[i] = 0;
    }

    // Insert elements into buckets
    for(i=0; i<n; i++)
    {
        key = arr[i];
        for(j=0; j<num_buckets; j++)
        {
            if(key <= bucket_arr[j])
            {
                bucket_arr[j]++;
                break;
            }
        }
    }

    // Sort buckets
    for(i=0; i<num_buckets; i++)
    {
        for(j=1; j<bucket_arr[i]; j++)
        {
            int temp = bucket_arr[i];
            bucket_arr[i] = temp - 1;
            bucket_arr[temp] = temp;
        }
    }

    // Copy elements into sorted array
    for(i=0; i<n; i++)
    {
        arr2[i] = bucket_arr[i];
    }

    // Print the sorted array
    for(i=0; i<n; i++)
        printf("%d ", arr2[i]);

    free(bucket_arr);
    return 0;
}