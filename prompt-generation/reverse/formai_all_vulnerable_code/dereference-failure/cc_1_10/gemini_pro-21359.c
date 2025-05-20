//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort an array using the bubble sort algorithm
void bubbleSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Function to print an array
void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    // Get the size of the array from the user
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));

    // Get the elements of the array from the user
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Sort the array using the bubble sort algorithm
    bubbleSort(arr, n);

    // Print the sorted array
    printf("The sorted array is: ");
    printArray(arr, n);

    // Free the memory allocated for the array
    free(arr);

    return 0;
}