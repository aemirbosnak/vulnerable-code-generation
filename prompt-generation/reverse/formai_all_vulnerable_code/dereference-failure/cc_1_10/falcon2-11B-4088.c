//Falcon2-11B DATASET v1.0 Category: Sorting ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

// Function to merge two sorted arrays
void merge(int arr1[], int arr2[], int n1, int n2, int n) {
    int i, j, k;
    int temp[n];

    i = 0;
    j = 0;
    k = 0;

    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            temp[k] = arr1[i];
            i++;
        } else {
            temp[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        temp[k] = arr1[i];
        i++;
        k++;
    }

    while (j < n2) {
        temp[k] = arr2[j];
        j++;
        k++;
    }

    for (int l = 0; l < n; l++) {
        arr1[l] = temp[l];
    }
}

// Function to perform merge sort on an array
void mergeSort(int arr[], int n) {
    if (n <= 1) {
        return;
    }

    int mid = n / 2;
    int arr1[mid];
    int arr2[n - mid];

    // Divide the array into two halves
    for (int i = 0; i < mid; i++) {
        arr1[i] = arr[i];
    }
    for (int i = mid; i < n; i++) {
        arr2[i - mid] = arr[i];
    }

    // Recursively sort the two halves
    mergeSort(arr1, mid);
    mergeSort(arr2, n - mid);

    // Merge the sorted halves
    merge(arr1, arr2, mid, n - mid, n);
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    mergeSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}