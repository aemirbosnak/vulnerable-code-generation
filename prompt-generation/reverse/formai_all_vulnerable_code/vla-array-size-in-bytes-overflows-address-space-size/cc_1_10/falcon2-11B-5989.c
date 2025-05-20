//Falcon2-11B DATASET v1.0 Category: Sorting ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform selection sort
void selectionSort(int arr[], int n) {
    int i, j, min_index;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++) {
        // Find the minimum element in unsorted array
        min_index = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_index])
                min_index = j;
        }

        // Swap the found minimum element with the first element
        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n, i;
    srand(time(NULL));

    // Input size of array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Input elements of array
    printf("Enter the elements of the array: ");
    int arr[n];
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Sort the array using selection sort
    selectionSort(arr, n);

    // Print the sorted array
    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}