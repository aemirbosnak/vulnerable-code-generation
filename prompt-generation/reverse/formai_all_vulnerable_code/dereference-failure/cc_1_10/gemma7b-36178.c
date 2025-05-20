//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void partition(int arr[], int n, int low, int high)
{
    int i = low - 1;
    int j = high;

    int pivot = arr[high];

    for (int k = low; k < high; k++)
    {
        if (arr[k] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[k]);
        }
    }

    swap(&arr[i + 1], &arr[high]);

    return;
}

int main()
{
    int n;
    scanf("Enter the number of elements: ", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d ", &arr[i]);
    }

    partition(arr, n, 0, n - 1);

    printf("The partitioned array is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}