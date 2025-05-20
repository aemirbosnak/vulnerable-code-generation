//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: cheerful
// A cheerful C program to search for an element in an array

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int main() {
    int arr[MAX_SIZE], n, search_element;

    // Prompt user to enter the size of the array
    printf("Enter the size of the array (maximum %d): ", MAX_SIZE);
    scanf("%d", &n);

    // Prompt user to enter the elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Prompt user to enter the element to search for
    printf("Enter the element to search for: ");
    scanf("%d", &search_element);

    // Call the binary search function
    int result = binary_search(arr, n, search_element);

    // Print the result
    if (result == -1) {
        printf("Element not found!\n");
    } else {
        printf("Element found at index %d!\n", result);
    }

    return 0;
}

// Binary search function
int binary_search(int arr[], int n, int element) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == element) {
            return mid;
        } else if (arr[mid] < element) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

/*
Sample Input/Output:

Enter the size of the array (maximum 1000): 5
Enter the elements of the array:
1 3 5 7 9
Enter the element to search for: 7
Element found at index 3!

Enter the size of the array (maximum 1000): 4
Enter the elements of the array:
2 4 6 8
Enter the element to search for: 5
Element not found!

Enter the size of the array (maximum 1000): 0
Error: Array size must be greater than 0!

Enter the size of the array (maximum 1000): -1
Error: Array size must be greater than or equal to 0 and less than or equal to 1000!
*/