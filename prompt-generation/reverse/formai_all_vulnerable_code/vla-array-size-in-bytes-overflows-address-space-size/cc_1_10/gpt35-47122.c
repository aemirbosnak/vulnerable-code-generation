//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Donald Knuth
/*
A unique C Searching algorithm example program in a Donald Knuth style.
Author: [Your Name]
*/

#include <stdio.h>
#include <stdlib.h>

// The search function
int search(int arr[], int n, int x)
{
    int left = 0, right = n - 1, mid;

    while (left <= right) {

        // Using Knuth's formula to calculate mid
        mid = left + (right - left) / 3;

        if (arr[mid] == x) {
            return mid;
        }

        if (arr[mid] < x) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }

        if (left <= right && arr[left] == x) {
            return left;
        }

        if (left <= right && arr[right] == x) {
            return right;
        }

        left++, right--;
    }

    return -1;
}

int main()
{
    int n, x, i, index;
    printf("\nEnter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("\nEnter array elements: ");
    for (i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    printf("\nEnter element to search: ");
    scanf("%d", &x);

    index = search(arr, n, x);

    if (index != -1)
        printf("\nElement found at index %d", index);
    else
        printf("\nElement not found");

    return 0;
}