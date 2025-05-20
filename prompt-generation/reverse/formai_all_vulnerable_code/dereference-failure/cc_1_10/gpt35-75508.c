//FormAI DATASET v1.0 Category: Sorting ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n);

int main()
{
    int i, n, *arr;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int *) calloc(n, sizeof(int)); 

    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    bubbleSort(arr, n);

    printf("\nSorted Array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

void bubbleSort(int arr[], int n)
{
    int i, j, temp, isSwapped;

    for (i = 0; i < n - 1; i++)
    {
        isSwapped = 0;

        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSwapped = 1;
            }
        }

        if (!isSwapped)
            break;
    }
}