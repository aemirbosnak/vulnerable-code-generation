//FormAI DATASET v1.0 Category: Searching algorithm ; Style: satisfied
#include <stdio.h>

// Function to perform binary search on an array
int binarySearch(int arr[], int left, int right, int x)
{
    if (right >= left) {
        int mid = left + (right - left) / 2;
 
        // If the element is present at the middle itself
        if (arr[mid] == x)
            return mid;
 
        // If element is smaller than mid, then it can only be present
        // in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, left, mid - 1, x);
 
        // Else the element can only be present in right subarray
        return binarySearch(arr, mid + 1, right, x);
    }
 
    // If element is not present in array
    return -1;
}

// Function to perform linear search on an array
int linearSearch(int arr[], int left, int right, int x)
{
    for (int i = left; i <= right; i++) {
        if (arr[i] == x)
            return i;
    }

    // If element is not present in array
    return -1;
}

int main()
{
    int n, x, choice;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Taking array input from the user
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Taking element to search from the user
    printf("Enter the element to search: ");
    scanf("%d", &x);

    // Asking user for the choice of search algorithm
    printf("Which search algorithm do you want to use? (1 - Linear, 2 - Binary)\n");
    scanf("%d", &choice);

    int index = -1;
    switch(choice) {
        case 1: index = linearSearch(arr, 0, n-1, x); break;
        case 2: index = binarySearch(arr, 0, n-1, x); break;
        default: printf("Invalid choice, please try again."); break;
    }

    if (index != -1) {
        printf("Element found at index %d.", index);
    }
    else {
        printf("Element not found in the array.");
    }

    return 0;
}