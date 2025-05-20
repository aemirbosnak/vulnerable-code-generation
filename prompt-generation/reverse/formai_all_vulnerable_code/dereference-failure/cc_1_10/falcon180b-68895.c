//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define MAX_SIZE 1000 //Maximum size of the array

int main()
{
    int arr[MAX_SIZE], n, target;
    char ch;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the target element to search for: ");
    scanf("%d", &target);
    int result = binarySearch(arr, target, 0, n-1);
    if(result == -1)
    {
        printf("Element not found in the array\n");
    }
    else
    {
        printf("Element found at position %d\n", result+1);
    }
    return 0;
}

int binarySearch(int arr[], int target, int start, int end)
{
    if(start > end)
    {
        return -1;
    }
    int mid = start + (end - start) / 2;
    if(arr[mid] == target)
    {
        return mid;
    }
    else if(arr[mid] > target)
    {
        return binarySearch(arr, target, start, mid-1);
    }
    else
    {
        return binarySearch(arr, target, mid+1, end);
    }
}