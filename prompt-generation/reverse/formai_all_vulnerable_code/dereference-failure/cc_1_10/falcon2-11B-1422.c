//Falcon2-11B DATASET v1.0 Category: Memory management ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory for an array of size n
void* allocateMemory(int n) {
    void* ptr = malloc(n * sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    return ptr;
}

// Function to free memory for an array of size n
void freeMemory(void* ptr, int n) {
    free(ptr);
}

// Function to print an array of integers
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to merge two sorted arrays
void merge(int* arr1, int* arr2, int size1, int size2) {
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            arr1[k] = arr1[i];
            i++;
        } else {
            arr1[k] = arr2[j];
            j++;
        }
        k++;
    }
    while (i < size1) {
        arr1[k] = arr1[i];
        i++;
        k++;
    }
    while (j < size2) {
        arr1[k] = arr2[j];
        j++;
        k++;
    }
}

int main() {
    int size = 5;
    int* arr1 = (int*)malloc(size * sizeof(int));
    int* arr2 = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr1[i] = rand() % 10;
        arr2[i] = rand() % 10;
    }

    printf("Array 1: ");
    printArray(arr1, size);
    printf("Array 2: ");
    printArray(arr2, size);

    merge(arr1, arr2, size, size);

    printf("Merged array: ");
    printArray(arr1, size);

    freeMemory(arr1, size);
    freeMemory(arr2, size);

    return 0;
}