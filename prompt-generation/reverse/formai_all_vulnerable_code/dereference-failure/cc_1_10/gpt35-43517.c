//FormAI DATASET v1.0 Category: Searching algorithm ; Style: ultraprecise
#include <stdio.h>

#define MAX_SIZE 100  // Maximum size of the array

// Function prototype
int binarySearch(int arr[], int l, int r, int x);

// Driver code
int main() {
    int arr[MAX_SIZE];
    int n, i, x, index;

    // Read in array size
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Read in array elements
    printf("Enter %d numbers: \n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Read value to search for
    printf("Enter the number to search: ");
    scanf("%d", &x);

    // Perform Binary Search
    index = binarySearch(arr, 0, n-1, x);

    // Check if element was found
    if (index == -1) {
        printf("Element not found in the array.\n");
    } else {
        printf("Element found at index %d.\n", index);
    }

    return 0;
}

// Recursive Binary Search Function
int binarySearch(int arr[], int l, int r, int x) {
    // Base case
    if (r >= l) {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        // Else element can only be present in right
        // subarray
        return binarySearch(arr, mid + 1, r, x);
    }

    // We reach here when element is not present
    // in array
    return -1;
}