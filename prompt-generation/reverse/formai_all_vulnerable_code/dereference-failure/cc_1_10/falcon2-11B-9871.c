//Falcon2-11B DATASET v1.0 Category: Sorting ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort an array of integers using bubble sort
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

// Function to print an array of integers
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to read an array of integers from the user
int* readArray(int size) {
    int *arr = (int*)malloc(size * sizeof(int));
    int i;
    printf("Enter %d integers:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    return arr;
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    int *arr = readArray(size);
    printf("Original array: ");
    printArray(arr, size);
    
    bubbleSort(arr, size);
    printf("Sorted array: ");
    printArray(arr, size);
    
    free(arr);
    return 0;
}