//FormAI DATASET v1.0 Category: Sorting ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) // function to perform sorting
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++) // outer loop to traverse the array
    {
        for (j = 0; j < n - i - 1; j++) // inner loop to compare each element with the following ones
        {
            if (arr[j] > arr[j + 1]) // if a number is greater than the one after it, swap them
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n, i;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d elements: ", n);
    
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    printf("Before sorting: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    
    sort(arr, n); // calling the sort function
    
    printf("\nAfter sorting: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    
    return 0;
}