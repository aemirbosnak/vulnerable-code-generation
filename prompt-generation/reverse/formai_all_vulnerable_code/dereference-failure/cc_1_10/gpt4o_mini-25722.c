//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10

// Function Prototypes
void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);
void printArray(int arr[], int size);
int* generateRandomArray(int size, int upperLimit);

int main() {
    // The seed for randomness is set
    srand(time(0));
    
    // The creation of a new random array
    int *array = generateRandomArray(ARRAY_SIZE, 100);

    // Printing the unsorted array
    printf("Unsorted Array: \n");
    printArray(array, ARRAY_SIZE);

    // The time to sort, to bring order amidst chaos
    mergeSort(array, 0, ARRAY_SIZE - 1);

    // The order emerges, behold the sorted array
    printf("Sorted Array: \n");
    printArray(array, ARRAY_SIZE);

    // Clean up and free the memory
    free(array);
    return 0;
}

// The function that sorts the array
void mergeSort(int arr[], int left, int right) {
    // When the array is but a single element, return
    if (left < right) {
        // Finding the midpoint of this segment
        int mid = left + (right - left) / 2;

        // Sorting the left half
        mergeSort(arr, left, mid);
        
        // Sorting the right half
        mergeSort(arr, mid + 1, right);

        // Merging the two halves together
        merge(arr, left, mid, right);
    }
}

// The merging process transforms disorder into order
void merge(int arr[], int left, int mid, int right) {
    // Calculate sizes of the temp arrays
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Temp arrays to hold the halves
    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merging the temp arrays back into arr[left..right]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = left; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Free memory allocated for temporary arrays
    free(L);
    free(R);
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Generate an array filled with random numbers
int* generateRandomArray(int size, int upperLimit) {
    int *arr = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % upperLimit;
    }
    return arr;
}