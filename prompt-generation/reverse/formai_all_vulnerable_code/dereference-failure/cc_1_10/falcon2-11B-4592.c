//Falcon2-11B DATASET v1.0 Category: Sorting ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to sort an array of integers using bubble sort
void sortArray(int arr[], int size) {
    for (int i = 0; i < size-1; i++) {
        for (int j = 0; j < size-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Function to generate a random array of integers
int* generateRandomArray(int size) {
    int* arr = (int*) malloc(size*sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
    return arr;
}

// Function to print an array of integers
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); // Seed random number generator with current time
    int size = 10;
    int* arr = generateRandomArray(size);
    printf("Original array: \n");
    printArray(arr, size);

    // Sort the array using bubble sort
    sortArray(arr, size);

    printf("Sorted array: \n");
    printArray(arr, size);

    free(arr); // Free memory allocated for the array
    return 0;
}