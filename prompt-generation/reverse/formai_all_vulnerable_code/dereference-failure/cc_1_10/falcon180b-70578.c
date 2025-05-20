//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define a structure for the element to be searched
typedef struct {
    int data;
    int index;
} element;

// Function to perform a linear search on the given array
int linearSearch(element arr[], int size, int target) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i].data == target) {
            return i;
        }
    }
    return -1;
}

// Function to perform a binary search on the given array
int binarySearch(element arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid].data == target) {
            return mid;
        } else if (arr[mid].data < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

// Main function to take user input and perform search operations
int main() {
    int n, target, result;
    element arr[MAX_SIZE];

    // Take user input for the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Take user input for the elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].data);
        arr[i].index = i;
    }

    // Take user input for the element to be searched
    printf("Enter the element to be searched: ");
    scanf("%d", &target);

    // Perform linear search and display the result
    result = linearSearch(arr, n, target);
    if (result == -1) {
        printf("Element not found in the array.\n");
    } else {
        printf("Element found at index %d.\n", result);
    }

    // Perform binary search and display the result
    result = binarySearch(arr, n, target);
    if (result == -1) {
        printf("Element not found in the array.\n");
    } else {
        printf("Element found at index %d.\n", result);
    }

    return 0;
}