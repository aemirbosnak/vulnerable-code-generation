//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the array
#define MAX_SIZE 1000

// Function to perform a linear search on the array
int linearSearch(int arr[], int size, int target) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1; // Element not found
}

// Function to perform a binary search on the array
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
    return -1; // Element not found
}

int main() {
    int arr[MAX_SIZE];
    int size, target;

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Get the elements of the array from the user
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Get the target element from the user
    printf("Enter the target element: ");
    scanf("%d", &target);

    // Perform a linear search on the array
    int result1 = linearSearch(arr, size, target);
    if (result1 == -1) {
        printf("Element not found!\n");
    } else {
        printf("Element found at position %d!\n", result1);
    }

    // Perform a binary search on the array
    int result2 = binarySearch(arr, size, target);
    if (result2 == -1) {
        printf("Element not found!\n");
    } else {
        printf("Element found at position %d!\n", result2);
    }

    return 0;
}