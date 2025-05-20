//Falcon-180B DATASET v1.0 Category: Recursive ; Style: portable
#include <stdio.h>
#include <stdlib.h>

// Function to print the array in reverse order
void reverseArray(int arr[], int start, int end) {
    if (start >= end)
        return;

    // Swap the elements at start and end
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    // Recursively call the function for the next elements
    reverseArray(arr, start + 1, end - 1);
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    int* arr = (int*)malloc(n * sizeof(int));

    // Get the elements of the array from the user
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Print the original array
    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Reverse the array
    reverseArray(arr, 0, n - 1);

    // Print the reversed array
    printf("Reversed array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}