//Falcon2-11B DATASET v1.0 Category: Sorting ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two numbers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

// Function to generate random array of integers
int* generateRandomArray(int n, int min, int max) {
    int* arr = (int*)malloc(n * sizeof(int));
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (max-min+1) + min;
    }
    return arr;
}

// Function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to check if two arrays are equal
int isEqual(int arr1[], int arr2[], int n) {
    for (int i = 0; i < n; i++) {
        if (arr1[i]!= arr2[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n = 10;
    int* arr1 = generateRandomArray(n, 1, 10);
    int* arr2 = generateRandomArray(n, 1, 10);
    printArray(arr1, n);
    printf("\n");
    bubbleSort(arr1, n);
    printf("Sorted array:\n");
    printArray(arr1, n);
    printf("\n");
    if (isEqual(arr1, arr2, n)) {
        printf("Arrays are equal.\n");
    } else {
        printf("Arrays are not equal.\n");
    }
    free(arr1);
    free(arr2);
    return 0;
}