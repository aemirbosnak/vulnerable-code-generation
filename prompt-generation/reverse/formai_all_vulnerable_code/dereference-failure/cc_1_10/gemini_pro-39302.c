//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Function to sort an array using bucket sort
void bucketSort(int arr[], int n)
{
    // Create buckets
    int buckets[n];
    for (int i = 0; i < n; i++)
    {
        buckets[i] = 0;
    }

    // Distribute elements into buckets
    for (int i = 0; i < n; i++)
    {
        int bucketIndex = arr[i] / n;
        buckets[bucketIndex]++;
    }

    // Sort elements in each bucket
    for (int i = 0; i < n; i++)
    {
        int bucketIndex = arr[i] / n;
        int count = buckets[bucketIndex];
        while (count > 0)
        {
            arr[i] = arr[i] % n;
            i++;
            count--;
        }
    }
}

// Function to print an array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

// Driver code
int main()
{
    int arr[] = {60, 10, 40, 50, 30, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);
    printArray(arr, n);

    return 0;
}