//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: recursive
#include <stdio.h>

// Function to perform binary search recursively
int recursiveBinarySearch(int arr[], int left, int right, int target) {
    // Base case: if left index exceeds right index, the element is not found
    if (left > right) {
        return -1; // Element not found
    }

    // Calculate the mid index
    int mid = left + (right - left) / 2;

    // Check if the element at mid is the target
    if (arr[mid] == target) {
        return mid; // Element found
    }

    // If the target is smaller than mid, search in the left sub-array
    if (target < arr[mid]) {
        return recursiveBinarySearch(arr, left, mid - 1, target);
    }

    // If the target is larger than mid, search in the right sub-array
    return recursiveBinarySearch(arr, mid + 1, right, target);
}

// Function to initialize and execute the binary search
void performBinarySearch() {
    int size, target;

    // Input the size of the array
    printf("Enter number of elements in the array: ");
    scanf("%d", &size);

    // Allocate memory for the array
    int arr[size];

    // Input the elements of the array
    printf("Enter the elements of the array in sorted order:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the target element to search for
    printf("Enter the target element to search for: ");
    scanf("%d", &target);

    // Perform the binary search
    int result = recursiveBinarySearch(arr, 0, size - 1, target);

    // Output the result
    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found in the array\n", target);
    }
}

// Main function to execute the program
int main() {
    // Call the function to perform binary search
    performBinarySearch();
    return 0;
}