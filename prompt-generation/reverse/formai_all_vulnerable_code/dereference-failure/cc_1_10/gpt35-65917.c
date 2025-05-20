//FormAI DATASET v1.0 Category: Searching algorithm ; Style: complex
#include <stdio.h>
#include <stdlib.h>

int binary_search(int arr[], int low, int high, int target);

int main() {
    int size, target, result;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // dynamically allocate memory for the array
    int *arr = (int*) malloc(size * sizeof(int));

    // populate the array
    printf("Enter %d integers in ascending order:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // ask for target element
    printf("Enter integer to be searched in the array: ");
    scanf("%d", &target);

    // perform binary search and store the result
    result = binary_search(arr, 0, size-1, target);

    if (result == -1) {
        printf("%d not found in the array\n", target);
    } else {
        printf("%d found at position %d in the array\n", target, result);
    }

    // free memory allocated for the array
    free(arr);

    return 0;
}

int binary_search(int arr[], int low, int high, int target) {
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    // target not found in the array
    return -1;
}