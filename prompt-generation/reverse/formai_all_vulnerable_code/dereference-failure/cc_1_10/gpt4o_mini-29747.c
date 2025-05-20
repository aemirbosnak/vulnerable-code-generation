//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Function prototype declarations
void merge(int arr[], int left, int mid, int right);
void mergeSort(int arr[], int left, int right);
void printArray(int arr[], int size);

// Main function: the entry point of our program
int main() {
    // Declaration of an array of integers
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is: \n");
    printArray(arr, arr_size);

    // Calling the mergeSort function to sort the array
    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array is: \n");
    printArray(arr, arr_size);
    return 0;
}

// Function to implement merge operation: combining two sorted halves
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1; // Size of left sub-array
    int n2 = right - mid;    // Size of right sub-array

    // Temporary arrays for storing left and right halves
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    // Copying data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merging the temporary arrays back into arr[left..right]
    i = 0; // Initial index of first sub-array
    j = 0; // Initial index of second sub-array
    k = left; // Initial index of merged sub-array
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copying the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copying the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Free the allocated memory for temporary arrays
    free(L);
    free(R);
}

// Function to implement the Merge Sort algorithm
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Finding the middle point
        int mid = left + (right - left) / 2;

        // Sorting the first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merging the sorted halves
        merge(arr, left, mid, right);
    }
}

// Function to print an array of given size
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}