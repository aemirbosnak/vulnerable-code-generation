//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Function to perform linear search on the array
int linear_search(int arr[], int size, int target) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1; // Target not found
}

// Function to perform binary search on the array
int binary_search(int arr[], int size, int target) {
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
    return -1; // Target not found
}

int main() {
    int arr[MAX_SIZE];
    int size, target, choice;

    // Get the size of the array from the user
    printf("Enter the size of the array (maximum %d): ", MAX_SIZE);
    scanf("%d", &size);

    // Get the elements of the array from the user
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Get the target value from the user
    printf("Enter the target value: ");
    scanf("%d", &target);

    // Get the search method from the user
    printf("Choose a search method:\n1. Linear search\n2. Binary search\n");
    scanf("%d", &choice);

    // Perform the chosen search method and display the result
    int result;
    switch (choice) {
        case 1:
            result = linear_search(arr, size, target);
            break;
        case 2:
            result = binary_search(arr, size, target);
            break;
        default:
            printf("Invalid choice.\n");
            return 0;
    }

    if (result == -1) {
        printf("Target not found.\n");
    } else {
        printf("Target found at index %d.\n", result);
    }

    return 0;
}