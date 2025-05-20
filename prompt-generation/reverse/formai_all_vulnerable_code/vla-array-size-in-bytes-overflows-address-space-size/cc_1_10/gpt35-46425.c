//FormAI DATASET v1.0 Category: Searching algorithm ; Style: introspective
#include <stdio.h>

// Function to perform binary search recursively
int binarysearch(int arr[], int start, int end, int key)
{
    // If start point is greater than end point; boarder is crossed and key not found in the array
    if (start > end)
        return -1;
 
    // Calculate mid point
    int mid = (start + end) / 2;
 
    // If key is found at the mid point, return mid index
    if (arr[mid] == key)
        return mid;
 
    // If key is less than mid point; search in left half of the array
    if (arr[mid] > key)
        return binarysearch(arr, start, mid - 1, key);
 
    // If key is greater than mid point; search in right half of the array
    return binarysearch(arr, mid + 1, end, key);
}
 
int main()
{
    printf("Enter the size of an array: ");
    int n;
    scanf("%d", &n);
    
    int arr[n];
    
    printf("\nEnter %d numbers in ascending order:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);   
    }
 
    printf("\nEnter the number to search: ");
    int key;
    scanf("%d", &key);
    
    int index = binarysearch(arr, 0, n - 1, key);
 
    if (index == -1)
        printf("\n%d not found in the array.\n", key);
    else
        printf("\n%d found at index %d.\n", key, index);
 
    return 0;
}