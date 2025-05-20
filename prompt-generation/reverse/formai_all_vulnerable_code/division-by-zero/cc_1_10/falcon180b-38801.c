//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000 // Maximum size of the array

// Function to perform linear search on the given array
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1; // Element not found
}

// Function to perform binary search on the given array
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

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

// Function to perform hash table search on the given array
int hashTableSearch(int arr[], int size, int target) {
    int hash = target % size;

    if (arr[hash] == target) {
        return hash;
    } else if (arr[hash] == -1) {
        return -1; // Element not found
    } else {
        return linearSearch(arr, size, target);
    }
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;

    // Prompt user to enter array elements
    printf("Enter array elements (enter -1 to stop):\n");
    while (scanf("%d", &arr[size]) == 1 && arr[size]!= -1) {
        size++;
    }

    // Prompt user to enter target element
    int target;
    printf("Enter target element:\n");
    scanf("%d", &target);

    // Perform different search algorithms on the array
    int result1 = linearSearch(arr, size, target);
    int result2 = binarySearch(arr, size, target);
    int result3 = hashTableSearch(arr, size, target);

    // Print results
    printf("Linear search result: %d\n", result1);
    printf("Binary search result: %d\n", result2);
    printf("Hash table search result: %d\n", result3);

    return 0;
}