//FormAI DATASET v1.0 Category: Sorting ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate an array with random numbers
int* generateRandomArray(int length) {
    int* arr = (int*)malloc(length * sizeof(int));
    for (int i = 0; i < length; i++) {
        arr[i] = rand();
    }
    return arr;
}

// Function to print an array
void printArray(int* arr, int length) {
    printf("[ ");
    for (int i = 0; i < length; i++) {
        printf("%d", arr[i]);
        if (i != length - 1) {
            printf(", ");
        }
    }
    printf(" ]\n");
}

// Function to swap two elements in an array
void swap(int* arr, int index1, int index2) {
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

// Function to perform bubble sort on an array
void bubbleSort(int* arr, int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr, j, j + 1);
            }
        }
    }
}

int main() {
    // Set the random seed
    srand(time(NULL));
    
    // Generate an array with random numbers
    int* arr = generateRandomArray(10);
    
    // Print the unsorted array
    printf("Unsorted array:\n");
    printArray(arr, 10);
    
    // Sort the array using bubble sort
    bubbleSort(arr, 10);
    
    // Print the sorted array
    printf("Sorted array:\n");
    printArray(arr, 10);
    
    return 0;
}