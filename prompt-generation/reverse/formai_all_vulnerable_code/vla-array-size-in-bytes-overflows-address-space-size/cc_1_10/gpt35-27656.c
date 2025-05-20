//FormAI DATASET v1.0 Category: Searching algorithm ; Style: rigorous
#include <stdio.h>

// Function to find the index of an element using Linear Search
int linearSearch(int arr[], int n, int x) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == x)
            return i;
    }
    return -1;
}

// Recursive Function to perform Binary Search
int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = (l + r) / 2;

        // If the element is present at the middle itself
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        // Else the element can only be present in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }

    // We reach here when element is not present in array
    return -1;
}

// Main function for testing the search algorithms
int main() {
    int n, i, x;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the array elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element you want to search: ");
    scanf("%d", &x);
    
    // Performing Linear Search on the array
    int linear_result = linearSearch(arr, n, x);
    if(linear_result == -1)
        printf("Element not found using Linear Search\n");
    else
        printf("Element found at index %d using Linear Search\n", linear_result);

    // Sorting the array
    int temp, j;
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // Performing Binary Search on the sorted array
    int binary_result = binarySearch(arr, 0, n-1, x);
    if(binary_result == -1)
        printf("Element not found using Binary Search\n");
    else
        printf("Element found at index %d using Binary Search\n", binary_result);

    return 0;
}