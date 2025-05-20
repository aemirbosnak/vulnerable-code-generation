//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Function to find the size of the bucket
int find_bucket_size(int arr[], int n)
{
    int min_val = arr[0];
    int bucket_size = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min_val)
        {
            min_val = arr[i];
            bucket_size = i + 1;
        }
    }
    return bucket_size;
}

// Function to sort the array using bucket sort
void bucket_sort(int arr[], int n)
{
    int bucket_size = find_bucket_size(arr, n);
    int *buckets = (int *)malloc(bucket_size * sizeof(int));
    for (int i = 0; i < bucket_size; i++)
        buckets[i] = 0;

    for (int i = 0; i < n; i++)
        buckets[arr[i] / bucket_size]++;

    int sorted_arr[n];
    int j = 0;
    for (int i = 0; i < bucket_size; i++)
    {
        for (int k = 0; k < buckets[i]; k++)
        {
            sorted_arr[j++] = i * bucket_size + k;
        }
    }

    for (int i = 0; i < n; i++)
        arr[i] = sorted_arr[i];

    free(buckets);
}

// Function to print the array
void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {10, 5, 20, 5, 15, 20, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting: ");
    print_array(arr, n);

    bucket_sort(arr, n);

    printf("After sorting: ");
    print_array(arr, n);

    return 0;
}