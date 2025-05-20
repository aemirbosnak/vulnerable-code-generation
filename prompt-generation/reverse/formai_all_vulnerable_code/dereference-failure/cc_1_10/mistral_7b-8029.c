//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100000

// Function to perform binary search
int CSearch(int arr[], int l, int r, int x) {
    while (l <= r) {
        int m = l + (r - l) / 2;

        // Check if x is present at mid
        if (arr[m] == x)
            return m;

        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;

        // If x is smaller, ignore right half
        else
            r = m - 1;
    }

    // If we reach here, then the element was not present
    return -1;
}

int main() {
    int arr[MAX_SIZE], n, i, x, result;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number to search: ");
    scanf("%d", &x);

    // Function call
    result = CSearch(arr, 0, n - 1, x);

    // If element is present, print position
    if (result != -1)
        printf("Element found at position %d", result + 1);

    // If element is not present, print message
    else
        printf("Element not present in array");

    return 0;
}