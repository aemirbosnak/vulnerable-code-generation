//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define Max 10

// Function to swap two elements
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Function to perform bucket sort on an array
void bucketSort(int arr[], int n)
{
    int bucket[Max] = {0};
    int i, j;

    // Place each element in the appropriate bucket
    for (i = 0; i < n; i++)
    {
        bucket[(arr[i] / (Max / n))]++;
    }

    // Modify the bucket counts to cumulatively sum to n
    for (i = 1; i < Max; i++)
    {
        bucket[i] += bucket[i - 1];
    }

    // Sort the array by placing each element in its correct bucket
    for (i = n - 1; i >= 0; i--)
    {
        if (bucket[(arr[i] / (Max / n))] > 0)
        {
            bucket[(arr[i] / (Max / n))]--;
            arr[--j] = arr[i];
        }
    }
}

// Function to print an array
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function
int main()
{
    int arr[] = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Print the original array
    printf("Original array: ");
    printArray(arr, n);

    // Perform bucket sort on the array
    bucketSort(arr, n);

    // Print the sorted array
    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}