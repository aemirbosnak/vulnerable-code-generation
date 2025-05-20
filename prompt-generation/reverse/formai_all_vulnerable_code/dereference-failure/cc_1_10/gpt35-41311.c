//FormAI DATASET v1.0 Category: Benchmarking ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A function to randomly generate an array of integers
int* generateIntArray(int size, int maxVal) {
    int* arr = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % maxVal;
    }
    return arr;
}

// A function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// A function to perform bubble sort on an integer array
void bubbleSort(int* arr, int size) {
    for (int i = 0; i < size-1; i++) {
        for (int j = 0; j < size-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

// A function to perform quick sort on an integer array
void quickSort(int* arr, int left, int right) {
    if (left < right) {
        int pivot = arr[right]; // Choose the rightmost element as pivot
        int i = left - 1; // Index of smaller element
        for (int j = left; j < right; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i+1], &arr[right]);
        int pi = i+1;
        quickSort(arr, left, pi-1);
        quickSort(arr, pi+1, right);
    }
}

// Main function to run the benchmarking tests
int main() {
    srand(time(NULL)); // Seed the random number generator
    
    int n = 1000000; // Set array size to 1 million
    int maxVal = 1000; // Maximum value of array elements
    int* arr = generateIntArray(n, maxVal); // Generate an array of size n with values between 0 and maxVal-1
    
    clock_t t1, t2; // Variables to measure time taken by each sort function
    double bubbleTime, quickTime;
    
    // Run bubble sort and measure time taken
    t1 = clock();
    bubbleSort(arr, n);
    t2 = clock();
    bubbleTime = (double)(t2 - t1) / CLOCKS_PER_SEC;
    
    // Regenerate array and run quick sort and measure time taken
    arr = generateIntArray(n, maxVal);
    t1 = clock();
    quickSort(arr, 0, n-1);
    t2 = clock();
    quickTime = (double)(t2 - t1) / CLOCKS_PER_SEC;
    
    // Output results
    printf("Array size: %d\n", n);
    printf("Maximum value of elements in array: %d\n", maxVal-1);
    printf("Time taken by bubble sort: %f seconds\n", bubbleTime);
    printf("Time taken by quick sort: %f seconds\n", quickTime);
    
    free(arr); // Free memory allocated for array
    
    return 0;
}