//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

// Define the structure for each bucket
typedef struct Bucket
{
    int count;      // number of elements in bucket
    int* values;    // the elements themselves
} Bucket;

// Define the bucket sort function
void bucketSort(int arr[], int n)
{
    Bucket* buckets = (Bucket*)malloc(n * sizeof(Bucket));  // create n buckets
    int max_val = arr[0];  // find maximum value in array
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max_val)
            max_val = arr[i];
    }

    // Initialize bucket counts to 0
    for (int i = 0; i < n; i++)
    {
        buckets[i].count = 0;
        buckets[i].values = (int*)malloc(n * sizeof(int));
    }

    // Iterate through array, adding elements to their respective buckets
    for (int i = 0; i < n; i++)
    {
        int bucket_index = (arr[i] * n) / (max_val + 1);  // calculate bucket index
        buckets[bucket_index].values[buckets[bucket_index].count++] = arr[i];
    }

    // Sort each bucket and concatenate them back into the original array
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        while (j < buckets[i].count)
        {
            arr[index++] = buckets[i].values[j++];
        }
    }

    // Free memory used by buckets
    for (int i = 0; i < n; i++)
    {
        free(buckets[i].values);
    }
    free(buckets);
}

// Test the bucket sort function
int main()
{
    int arr[10] = { 3, 6, 2, 1, 8, 5, 9, 4, 7, 0 };
    int n = 10;

    printf("Unsorted array: ");
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