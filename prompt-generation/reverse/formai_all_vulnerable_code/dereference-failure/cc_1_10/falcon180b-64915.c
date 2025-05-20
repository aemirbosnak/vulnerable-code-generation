//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100 // maximum size of the array

// function to perform linear search on the array
int linearSearch(int arr[], int size, int target) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1; // target not found
}

// function to perform binary search on the array
int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1, mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
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
    int i, size, target, *arr;

    // allocate memory for the array
    arr = (int *) malloc(MAX_SIZE * sizeof(int));
    if (arr == NULL) {
        printf("Error: Failed to allocate memory for array.\n");
        exit(1);
    }

    // prompt user to enter size of array
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    if (size <= 0 || size > MAX_SIZE) {
        printf("Error: Invalid size of array.\n");
        exit(1);
    }

    // prompt user to enter elements of array
    printf("Enter the elements of the array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // prompt user to enter target value to search for
    printf("Enter the target value to search for: ");
    scanf("%d", &target);

    // perform linear search
    int result = linearSearch(arr, size, target);
    if (result == -1) {
        printf("Target value not found in the array.\n");
    } else {
        printf("Target value found at index %d.\n", result);
    }

    // perform binary search
    result = binarySearch(arr, size, target);
    if (result == -1) {
        printf("Target value not found in the array.\n");
    } else {
        printf("Target value found at index %d.\n", result);
    }

    // free memory allocated for the array
    free(arr);

    return 0;
}