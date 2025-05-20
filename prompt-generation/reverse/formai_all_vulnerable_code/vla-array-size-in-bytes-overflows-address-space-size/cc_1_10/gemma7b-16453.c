//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

void mergeSort(int arr[], int n);
void partition(int arr[], int low, int high);

int main()
{
    int n, i, arr[MAX];
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}

void mergeSort(int arr[], int n)
{
    int i, j, k, mid, left[n], right[n];

    if (n <= 1)
    {
        return;
    }

    partition(arr, 0, n - 1);

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void partition(int arr[], int low, int high)
{
    int pivot, i, j, temp;

    pivot = arr[high];
    i = low - 1;

    for (j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return;
}