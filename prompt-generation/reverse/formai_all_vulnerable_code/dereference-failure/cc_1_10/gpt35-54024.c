//FormAI DATASET v1.0 Category: Sorting ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Function to swap two numbers
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Function to perform selection sort
void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++) {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}

int main() {
    int *arr;
    int n, i;

    // Ask user for number of array elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Allocate memory for array dynamically
    arr = (int*) malloc(n * sizeof(int));

    // Ask user for array elements
    printf("\nEnter the elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Perform selection sort
    selectionSort(arr, n);

    // Print the sorted array
    printf("\nSorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    // Free the dynamically allocated memory
    free(arr);

    // Thank the user for using the program
    printf("\n\nThank you for using this sorting program. Have a nice day!\n");

    return 0;
}