//FormAI DATASET v1.0 Category: Searching algorithm ; Style: systematic
#include<stdio.h>

// Function to perform Binary Search
int binarySearch(int arr[], int left, int right, int x)
{
    while (left <= right) {
        int mid = left + (right - left) / 2;
 
        // Check if x is present at mid
        if (arr[mid] == x)
            return mid;
 
        // If x greater, ignore left half
        if (arr[mid] < x)
            left = mid + 1;
 
        // If x is smaller, ignore right half
        else
            right = mid - 1;
    }
 
    // if we reach here, then element was not present
    return -1;
}

// Function to perform Linear Search
int linearSearch(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++) {
        // Return the index of the element if found
        if (arr[i] == x)
            return i;
    }
    // Return -1 if element not found
    return -1;
}

int main()
{
    int n, i, arr[100], ch, search, pos;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    printf("\nEnter the data: ");
    for (i=0; i<n; i++)
        scanf("%d", &arr[i]);
    printf("\nEnter the element to search: ");
    scanf("%d", &search);
    printf("\nChoose the type of search algorithm: \n1. Binary Search\n2. Linear Search\n\nEnter your choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
        case 1:
            pos = binarySearch(arr, 0, n-1, search);
            if (pos == -1)
                printf("\nElement not found in the array.\n");
            else
                printf("\nElement found at index %d.\n", pos);
            break;

        case 2:
            pos = linearSearch(arr, n, search);
            if (pos == -1)
                printf("\nElement not found in the array.\n");
            else
                printf("\nElement found at index %d.\n", pos);
            break;

        default:
            printf("\nInvalid choice!\n");
            break;
    }
    return 0;
}