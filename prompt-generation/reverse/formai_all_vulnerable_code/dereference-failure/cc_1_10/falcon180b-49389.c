//Falcon-180B DATASET v1.0 Category: Recursive ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to perform a binary search recursively
int binarySearch(int arr[], int size, int target) {
    // Base case
    if (size == 0) {
        return -1;
    }
    
    // Find the middle element in the array
    int mid = size / 2;
    
    // If the target element is found, return the index
    if (arr[mid] == target) {
        return mid;
    }
    
    // If the target element is less than the middle element, search the left half
    if (target < arr[mid]) {
        return binarySearch(arr, mid, target);
    }
    
    // If the target element is greater than the middle element, search the right half
    return binarySearch(arr, size - mid - 1, target);
}

int main() {
    // Initialize an array with some values
    int arr[MAX_SIZE] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    
    // Get the size of the array from the user
    int size = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    // Get the target element from the user
    int target = 0;
    printf("Enter the target element: ");
    scanf("%d", &target);
    
    // Perform a binary search recursively
    int result = binarySearch(arr, size, target);
    
    // Print the result
    if (result == -1) {
        printf("Target element not found in the array.\n");
    } else {
        printf("Target element found at index %d.\n", result);
    }
    
    return 0;
}