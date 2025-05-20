//FormAI DATASET v1.0 Category: Sorting ; Style: interoperable
// Interoperable C program to sort an array of integers using selection sort

#include <stdio.h>
#include <stdlib.h>

// Function to sort an array using selection sort
void selectionSort(int *arr, int size) {
    int i, j, minIndex, temp;
    
    // One by one move boundary of unsorted subarray
    for (i = 0; i < size-1; i++) {
        // Find the minimum element in unsorted array
        minIndex = i;
        for (j = i+1; j < size; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;
        
        // Swap the found minimum element with the first element
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int i, size;
    int *arr;

    // Accept the size of the array from user
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Allocate memory for the array dynamically
    arr = (int*) malloc(size * sizeof(int));

    // Accept the elements of the array from user
    printf("Enter the elements of the array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array using selection sort
    selectionSort(arr, size);

    // Print the sorted array
    printf("The sorted array is:\n");
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}