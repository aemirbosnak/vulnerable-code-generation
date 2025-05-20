//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void bubbleSort(int arr[], int n);
void printArray(int arr[], int n);

// Main function - the adventure starts here!
int main() {
    // Speed Up: Seed the random number generator
    srand(time(0));

    // Let's define the size and create an array!
    int n = 10; // You can change this value for even more fun!
    int *arr = (int *)malloc(n * sizeof(int));

    // Populating the array with random numbers!
    printf("Generating an array of %d random integers:\n", n);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Random integers between 0 and 99
    }
    
    // Show the unsorted array
    printArray(arr, n);

    // Now, let's sort that array with style!
    printf("Sorting the array using Bubble Sort...\n");
    bubbleSort(arr, n);

    // Show the sorted array
    printf("Yay! The array is sorted:\n");
    printArray(arr, n);

    // Free the allocated memory
    free(arr);
    return 0;
}

// The Bubble Sort function - making it happen!
void bubbleSort(int arr[], int n) {
    // Here we go, a classic bubble sort in action!
    for (int i = 0; i < n - 1; i++) {
        // Let's keep track if we made any swaps
        int swapped = 0;

        // Inner loop to compare adjacent elements
        for (int j = 0; j < n - 1 - i; j++) {
            // If the current element is greater than the next, swap them!
            if (arr[j] > arr[j + 1]) {
                // Swapping using a temporary variable
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1; // Mark that we swapped!
            }
        }
        
        // Optional: Print the array at each outer loop iteration
        printf("After pass %d: ", i + 1);
        printArray(arr, n);

        // If no swaps were made, the array is sorted!
        if (!swapped) {
            printf("No swaps made, the array is sorted! Breaking out...\n");
            break;
        }
    }
}

// Function to print the array - let's visualize it!
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}