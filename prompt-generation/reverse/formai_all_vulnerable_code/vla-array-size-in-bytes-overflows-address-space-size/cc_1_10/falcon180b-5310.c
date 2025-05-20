//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random integer between min and max (inclusive)
int randInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition an array around a pivot element
int partition(int arr[], int low, int high, int pivotIndex) {
    int pivotValue = arr[pivotIndex];
    swap(&arr[pivotIndex], &arr[high]);
    int storeIndex = low;

    for (int i = low; i < high; i++) {
        if (arr[i] <= pivotValue) {
            swap(&arr[i], &arr[storeIndex]);
            storeIndex++;
        }
    }
    swap(&arr[storeIndex], &arr[high]);
    return storeIndex;
}

// Function to perform quicksort on an array
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = randInt(low, high);
        pivotIndex = partition(arr, low, high, pivotIndex);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array:\n");
    printArray(arr, size);

    quickSort(arr, 0, size - 1);

    printf("Sorted array:\n");
    printArray(arr, size);

    return 0;
}