//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: Dennis Ritchie
#include <stdio.h>

// Function prototypes
void bubbleSort(int arr[], int n);
int binarySearch(int arr[], int n, int target);
void displayArray(int arr[], int n);

int main() {
    int n, i, target, result;

    // Input the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n]; // Declare the array based on user input

    // Input the elements of the array
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        printf("Element [%d]: ", i);
        scanf("%d", &arr[i]);
    }

    // Display unsorted array
    printf("The entered array is:\n");
    displayArray(arr, n);

    // Sort the array using bubble sort
    bubbleSort(arr, n);

    // Display sorted array
    printf("The sorted array is:\n");
    displayArray(arr, n);

    // Input the target value to search
    printf("Enter the element to search for: ");
    scanf("%d", &target);

    // Perform binary search
    result = binarySearch(arr, n, target);

    // Output the result
    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}

// Function to sort the array using bubble sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap if the element found is greater than the next element
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to perform binary search on a sorted array
int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1, mid;

    while (left <= right) {
        mid = left + (right - left) / 2; // Calculate the mid index

        // Check if target is present at mid
        if (arr[mid] == target) {
            return mid; // Target found
        }

        // If target is greater, ignore left half
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            // If target is smaller, ignore right half
            right = mid - 1;
        }
    }

    return -1; // Target not found
}

// Function to display the contents of the array
void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}