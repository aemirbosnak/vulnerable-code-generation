//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Function to perform binary search on a sorted array
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid; // Target found at index mid
        }
        if (arr[mid] < target) {
            left = mid + 1; // Ignore the left half
        } else {
            right = mid - 1; // Ignore the right half
        }
    }

    return -1; // Target not found
}

// Function to compare two integers (used for sorting)
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int size, target;
    
    // Taking input for the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);
    
    // Dynamic allocation of memory for the array
    int *arr = (int *)malloc(size * sizeof(int));
    
    // Taking input for array elements
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Sorting the array
    qsort(arr, size, sizeof(int), compare);
    
    // Displaying the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Taking input for the target value
    printf("Enter the element to search for: ");
    scanf("%d", &target);

    // Performing binary search
    int result = binarySearch(arr, size, target);
    
    // Outputting the result of the search
    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    // Freeing the allocated memory
    free(arr);

    return 0;
}