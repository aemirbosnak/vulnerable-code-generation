//Falcon-180B DATASET v1.0 Category: Recursive ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

// Function to print the array in reverse order
void printArray(int arr[], int size) {
    for (int i = size - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to reverse an array recursively
void reverseArray(int arr[], int start, int end) {
    if (start >= end) {
        return;
    }

    // Swap elements at start and end
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    // Recursively reverse the rest of the array
    reverseArray(arr, start + 1, end - 1);
}

// Function to fill an array with random numbers
void fillArray(int arr[], int size) {
    srand(time(NULL)); // Seed the random number generator with the current time

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Generate a random number between 0 and 99
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    fillArray(arr, size);
    printf("Original array: ");
    printArray(arr, size);

    reverseArray(arr, 0, size - 1);
    printf("Reversed array: ");
    printArray(arr, size);

    return 0;
}