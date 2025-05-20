//Falcon2-11B DATASET v1.0 Category: Sorting ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int size = 100; // Define the size of the array
    int* arr = (int*)malloc(size * sizeof(int)); // Allocate memory for the array

    // Generate random numbers for the array
    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Generate a random number between 0 and 99
    }

    // Print the unsorted array
    printf("Unsorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort the array using bubble sort algorithm
    int swapped;
    for (int i = 0; i < size - 1; i++) {
        swapped = 0;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap the elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0) {
            break;
        }
    }

    // Print the sorted array
    printf("Sorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free the memory allocated for the array
    free(arr);

    return 0;
}