//FormAI DATASET v1.0 Category: Searching algorithm ; Style: innovative
#include <stdio.h>
#define MAX 100 // Maximum number of elements in the array

// Function to perform linear search
int linear_search(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

// Function to perform binary search
int binary_search(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        
        if (arr[mid] == x) {
            return mid;
        }
        if (arr[mid] > x) {
            return binary_search(arr, l, mid - 1, x);
        }
        return binary_search(arr, mid + 1, r, x);
    }
    return -1;
}

int main() {
    int arr[MAX], n, x, choice, index;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &x);
    printf("Choose the type of search:\n1. Linear Search\n2. Binary Search\nEnter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            index = linear_search(arr, n, x);
            break;
        case 2:
            index = binary_search(arr, 0, n - 1, x);
            break;
        default:
            printf("Invalid choice!\n");
            return 0;
    }
    if (index == -1) {
        printf("Element not found!\n");
    } else {
        printf("Element found at index %d.\n", index);
    }
    return 0;
}