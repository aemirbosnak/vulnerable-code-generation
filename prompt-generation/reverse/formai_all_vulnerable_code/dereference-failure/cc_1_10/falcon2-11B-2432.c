//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// A function to find the median of a array of 2 numbers
int median2(int arr[], int n)
{
    if (n == 1)
        return arr[0];

    int mid = n / 2;
    if (n % 2 == 0)
        return (arr[mid - 1] + arr[mid]) / 2;
    else
        return arr[mid];
}

// A function to sort the array using bucket sort
void bucketSort(int arr[], int n)
{
    int *buckets = (int*) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        buckets[arr[i] % 100] = arr[i];

    int count[100] = {0};

    for (int i = 0; i < 100; i++)
    {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        count[buckets[i] % 100]++;
    }

    for (int i = 0; i < 100; i++)
    {
        int min_index = -1;
        int min_count = 100;
        for (int j = 0; j < count[i]; j++)
        {
            min_index = i;
            min_count = 1;
            for (int k = 0; k < count[i]; k++)
            {
                if (min_count > count[buckets[(i * count[i]) + j] % 100])
                {
                    min_index = buckets[(i * count[i]) + j] % 100;
                    min_count = count[buckets[(i * count[i]) + j] % 100];
                }
            }
            int temp = buckets[min_index];
            buckets[min_index] = buckets[i * count[i] + min_count - 1];
            buckets[i * count[i] + min_count - 1] = temp;
        }
    }

    for (int i = 0; i < n; i++)
        arr[i] = buckets[i];

    free(buckets);
}

int main()
{
    int arr[] = {3, 4, 5, 2, 1, 6, 4, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array is : ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    bucketSort(arr, n);

    printf("Sorted array is : ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}