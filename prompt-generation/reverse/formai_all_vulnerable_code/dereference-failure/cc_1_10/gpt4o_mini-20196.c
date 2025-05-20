//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// Function to perform binary search
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the target is present at mid
        if (arr[mid] == target) {
            return mid; // Target found
        }

        // If target is greater, ignore left half
        if (arr[mid] < target) {
            left = mid + 1; // Move to the right side
        } else {
            right = mid - 1; // Move to the left side
        }
    }
    return -1; // Target not found
}

// Function to fill the array with sorted elements
void fillArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i * 2; // Example: filling the array with even numbers
    }
}

// Main Function
int main() {
    int size = 20; // Size of the array
    int *arr = malloc(size * sizeof(int)); // Dynamic memory allocation for the array

    // Fill the array with sorted elements
    fillArray(arr, size);
    
    // Welcome message
    printf("Welcome to the Brave Binary Search Program!\n");
    printf("We have created a sorted array of the first 20 even numbers.\n");
    printf("Here they are:\n");

    // Display the array
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Prompt user for a number to search
    int target;
    printf("Enter a number to search for (it should be one of the even numbers): ");
    scanf("%d", &target);

    // Perform the search
    int result = binarySearch(arr, size, target);
    
    // Check results
    if (result != -1) {
        printf("Hooray! We found the number %d at index %d!\n", target, result);
    } else {
        printf("Alas! The number %d is not present in the array.\n", target);
    }

    // Free the allocated memory
    free(arr);
    
    // Goodbye message
    printf("Thank you for using the Brave Binary Search Program! Until next time!\n");

    return 0;
}