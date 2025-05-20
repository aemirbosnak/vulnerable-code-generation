//FormAI DATASET v1.0 Category: Searching algorithm ; Style: secure
#include<stdio.h>
#include<stdlib.h>

int search(int arr[], int n, int key)
{
    int low = 0, high = n - 1, mid = 0;
 
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;  
}

int main()
{
    int n, key, i;
    int *arr;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    arr = (int*) malloc(n * sizeof(int));
    printf("\nEnter %d elements of array in ascending order: ", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\nEnter the element to be searched: ");
    scanf("%d", &key);
    int result = search(arr, n, key);
    if(result == -1)
    {
        printf("\nElement not found in array\n");
    }
    else
    {
        printf("\nElement found at index %d\n", result);
    }
    return 0;
}