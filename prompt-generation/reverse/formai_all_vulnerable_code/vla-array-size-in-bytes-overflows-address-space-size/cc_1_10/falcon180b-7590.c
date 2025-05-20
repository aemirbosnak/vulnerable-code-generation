//Falcon-180B DATASET v1.0 Category: Educational ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

// Function to print the array in reverse order
void printArray(int arr[], int size) {
    int i;
    for(i=size-1; i>=0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to reverse an array
void reverseArray(int arr[], int size) {
    int i;
    for(i=0; i<size/2; i++) {
        int temp = arr[i];
        arr[i] = arr[size-i-1];
        arr[size-i-1] = temp;
    }
}

// Function to recursively reverse an array
void reverseArrayRecursive(int arr[], int start, int end) {
    if(start >= end)
        return;
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    reverseArrayRecursive(arr, start+1, end-1);
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of the array:\n");
    for(int i=0; i<size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Original array: ");
    printArray(arr, size);
    reverseArray(arr, size);
    printf("Reversed array: ");
    printArray(arr, size);
    reverseArrayRecursive(arr, 0, size-1);
    printf("Recursively reversed array: ");
    printArray(arr, size);
    return 0;
}