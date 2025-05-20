//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
int getRandomNumber(int min, int max);
void swap(int* a, int* b);
void selectionSort(int arr[], int n);
void printArray(int arr[], int size);

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    srand(time(NULL));

    // Populating the array with random numbers
    for (int i = 0; i < size; i++) {
        arr[i] = getRandomNumber(1, 100);
    }

    // Printing the unsorted array
    printf("\nUnsorted Array:\n");
    printArray(arr, size);

    // Sorting the array using selection sort
    selectionSort(arr, size);

    // Printing the sorted array
    printf("\nSorted Array:\n");
    printArray(arr, size);

    return 0;
}

// Function to generate a random number between min and max (inclusive)
int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform selection sort on an array
void selectionSort(int arr[], int n) {
    int min_idx;

    for (int i = 0; i < n - 1; i++) {
        min_idx = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        swap(&arr[i], &arr[min_idx]);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}