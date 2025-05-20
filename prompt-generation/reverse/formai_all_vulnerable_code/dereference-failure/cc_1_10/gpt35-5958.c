//FormAI DATASET v1.0 Category: Sorting ; Style: decentralized
// Decentralized Sorting Example Program

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 100

// Define custom swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Define function to select random pivot element
int select_pivot(int low, int high) {
    srand(time(NULL));
    return rand() % (high - low + 1) + low;
}

// Define function to partition array based on pivot element
int partition(int *arr, int low, int high) {
    int pivot_index = select_pivot(low, high);
    int pivot = arr[pivot_index];
    // Move pivot element to end of array
    swap(&arr[pivot_index], &arr[high]);
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    // Move pivot element to correct position in array
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Define decentralized quicksort function
void decentralized_quicksort(int *arr, int low, int high) {
    if (low < high) {
        int partition_index = partition(arr, low, high);
        // Create child processes to sort each partition
        #pragma omp parallel sections
        {
            #pragma omp section
            decentralized_quicksort(arr, low, partition_index - 1);
            #pragma omp section
            decentralized_quicksort(arr, partition_index + 1, high);
        }
    }
}

// Main function to test decentralized quicksort
int main() {

    int arr[MAX_ELEMENTS];
    int n;

    // Take user input for size of array and array elements
    printf("Enter size of array (maximum %d): ", MAX_ELEMENTS);
    scanf("%d", &n);
    printf("Enter elements of array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort array using decentralized quicksort
    decentralized_quicksort(arr, 0, n - 1);

    // Print sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}