//Falcon2-11B DATASET v1.0 Category: Sorting ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to do bubble sort
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to get the size of an array
int getArraySize(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i]!= 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int size = getArraySize(arr, n);
    if (size == -1) {
        printf("Array is empty\n");
    } else {
        bubbleSort(arr, size);
        printf("Sorted array: ");
        printArray(arr, size);
    }
    return 0;
}