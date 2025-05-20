//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void bucketSort(int arr[], int n)
{
    int i, j, max, min, range, bucket[MAX_SIZE];

    // Find the maximum and minimum values in the array
    max = arr[0];
    min = arr[0];
    for (i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    // Calculate the range and bucket size
    range = max - min + 1;
    for (i = 0; i < MAX_SIZE; i++)
        bucket[i] = 0;

    // Place each element in its corresponding bucket
    for (i = 0; i < n; i++)
    {
        j = (arr[i] - min) / range;
        bucket[j]++;
    }

    // Sort each bucket using any sorting algorithm
    for (i = 0; i < MAX_SIZE; i++)
    {
        if (bucket[i]!= 0)
        {
            j = 0;
            while (j < n && arr[j] - min == i * range)
            {
                arr[j] = arr[j + 1];
                j++;
            }
            while (j < n && arr[j] - min == (i + 1) * range - 1)
            {
                arr[j] = arr[j - 1];
                j--;
            }
        }
    }
}

int main()
{
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    bucketSort(arr, n);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}