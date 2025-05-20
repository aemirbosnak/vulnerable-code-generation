//Falcon-180B DATASET v1.0 Category: Sorting ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two integers
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Function to perform quicksort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to get user input for array size and elements
void getInput(int arr[], int size) {
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

int main() {
    int size;

    // Get array size from user
    printf("Enter the size of the array:\n");
    scanf("%d", &size);

    // Initialize the array with random numbers
    srand(time(NULL));
    int arr[size];
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }

    // Print the unsorted array
    printf("Unsorted array:\n");
    printArray(arr, size);

    // Sort the array using quicksort
    quickSort(arr, 0, size - 1);

    // Print the sorted array
    printf("Sorted array:\n");
    printArray(arr, size);

    return 0;
}