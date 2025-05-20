//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to implement bucket sort
void bucketSort(int arr[], int n)
{
    // Initialize an array of size n+1 to store the number of elements in each bucket
    int buckets[n+1];

    // Initialize the last bucket to store any remaining elements
    buckets[n] = 0;

    // Calculate the number of elements in each bucket
    for (int i = 0; i < n; i++)
    {
        buckets[arr[i]]++;
    }

    // Create buckets of appropriate size
    for (int i = 1; i <= n; i++)
    {
        buckets[i] += buckets[i-1];
    }

    // Create an array to store the sorted elements
    int sorted[buckets[n]];

    // Copy the elements into the sorted array
    for (int i = 0; i < buckets[n]; i++)
    {
        sorted[i] = arr[i];
    }

    // Copy the sorted array back into the original array
    for (int i = 0; i < buckets[n]; i++)
    {
        arr[i] = sorted[i];
    }
}

int main()
{
    // Test the bucketSort function
    int arr[] = {5, 3, 8, 2, 9, 1, 6, 4, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, n);

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}