//FormAI DATASET v1.0 Category: Searching algorithm ; Style: imaginative
#include<stdio.h>

int linear_search(int arr[], int n, int x)             // function for linear search algorithm
{
    for(int i=0; i<n; i++)
    {
        printf("Scanning element %d...\n", arr[i]);   // visual effect to show scanning
        if(arr[i] == x)                               // if element is found
        {
            printf("\nElement %d found at position %d\n\n", x, i+1);  // position is i+1
            return i;
        }
    }
    printf("\nElement %d not found in the array\n\n", x);              // if element is not found
    return -1;
}

void main()
{
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Welcome to the Search Program!\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    printf("Choose the size of the array: ");

    int n;
    scanf("%d", &n);                        // user enters size of array

    int arr[n];
    printf("\nEnter %d elements for the array:\n", n);

    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);                // user enters array elements

    printf("\nThe array is: \n");

    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);               // printing the array

    printf("\n\nEnter the element to be searched: ");
    int x;
    scanf("%d", &x);                         // user enters element to be searched

    int result = linear_search(arr, n, x);  // calling the linear search function

    if(result == -1)
        printf("Try again :(");
    else
        printf("Yay! The element was found!");

    printf("\n\n~~~~~~~~~~~~\nThank You!\n~~~~~~~~~~~~\n\n");
}