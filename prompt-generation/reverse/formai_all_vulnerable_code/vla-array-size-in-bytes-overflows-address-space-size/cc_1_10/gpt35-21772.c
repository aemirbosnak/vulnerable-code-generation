//FormAI DATASET v1.0 Category: Sorting ; Style: satisfied
/*
 * This is a program to sort an integer array using Bubble sort algorithm.
 * It takes an array of integers as input and returns it in sorted order.
 * Let's get started!
 */

#include <stdio.h>

// function to swap two integers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// function to perform bubble sort on an integer array
void bubble_sort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)      
    {   
        for (j = 0; j < n-i-1; j++) 
        {
            if (arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
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
    printf("Enter elements of array: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\nSorting the array using Bubble sort...\n");
    bubble_sort(arr, n);

    printf("\nSorted array is: ");
    for (i=0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}