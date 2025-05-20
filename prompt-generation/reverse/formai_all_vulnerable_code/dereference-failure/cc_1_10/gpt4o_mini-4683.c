//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

// Function to print array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Function to generate random integers and fill the array
void generateRandomArray(int arr[], int size) {
    srand(time(0)); 
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Random integers between 0 and 99
    }
}

// Function to create a musical representation of sorting
void musicalSorting(int arr[], int n) {
    printf("\n--- Musical Journey of Sorting ---\n");
    const char* notes[] = {"C", "D", "E", "F", "G", "A", "B"};
    
    for (int i = 0; i < n; i++) {
        int noteIndex = arr[i] % 7; // To stay within the range of notes
        printf("Sorting element %d plays note %s\n", arr[i], notes[noteIndex]);
    }
    
    printf("The beautiful symphony of sorting begins...\n");
}

// Main function
int main() {
    // Specify the size of the array
    int size = 10; // Choose a size for the array
    int *arr = (int*)malloc(size * sizeof(int)); // Dynamically allocate memory
    
    // Generate a random array
    generateRandomArray(arr, size);
    
    // Print original array
    printf("Original array:\n");
    printArray(arr, size);
    
    // Perform bubble sort
    bubbleSort(arr, size);
    
    // Print sorted array
    printf("Sorted array:\n");
    printArray(arr, size);
    
    // Create musical representation
    musicalSorting(arr, size);
    
    // Free dynamically allocated memory
    free(arr);
    
    return 0;
}