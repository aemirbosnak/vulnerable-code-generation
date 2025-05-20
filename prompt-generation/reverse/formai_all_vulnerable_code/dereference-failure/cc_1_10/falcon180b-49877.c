//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Function to perform binary search on the array
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // target not found
}

int main() {
    int arr[MAX_SIZE];
    int size, target;

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Get the elements of the array from the user
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Get the target element from the user
    printf("Enter the target element: ");
    scanf("%d", &target);

    // Perform binary search on the array
    int result = binarySearch(arr, size, target);

    // Print the result of the search
    if (result!= -1) {
        printf("Element found at position: %d\n", result);
    } else {
        printf("Element not found in the array\n");
    }

    return 0;
}