//FormAI DATASET v1.0 Category: Benchmarking ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_SIZE 100000 // Array size for benchmarking

// Function to generate random numbers
int* generateRandomNumbers(int size){
    int *arr = malloc(size * sizeof(int));
    srand(time(NULL)); // Seed for random number generation
    for(int i=0; i<size; i++){
        arr[i] = rand() % 100;
    }
    return arr;
}

// Function to perform bubble sort on an integer array
void bubbleSort(int arr[], int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size-i-1; j++){
            if(arr[j] > arr[j+1]){ // Swap if current element is greater than next element
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Function to perform selection sort on an integer array
void selectionSort(int arr[], int size){
    for(int i=0; i<size-1; i++){
        int minIndex = i;
        for(int j=i+1; j<size; j++){
            if(arr[j] < arr[minIndex]){ // Update minimum index if smaller element is found
                minIndex = j;
            }
        }
        // Swap current element with minimum element
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main() {
    int *arr = generateRandomNumbers(ARR_SIZE); // Generate an array of random numbers
    clock_t t1, t2;
    double timeTaken;
    
    t1 = clock(); // Get starting time
    bubbleSort(arr, ARR_SIZE); // Perform bubble sort
    t2 = clock(); // Get ending time
    timeTaken = ((double)(t2 - t1))/CLOCKS_PER_SEC; // Calculate time taken in seconds
    printf("Bubble Sort Time: %f seconds\n", timeTaken);
    
    t1 = clock(); // Get starting time
    selectionSort(arr, ARR_SIZE); // Perform selection sort
    t2 = clock(); // Get ending time
    timeTaken = ((double)(t2 - t1))/CLOCKS_PER_SEC; // Calculate time taken in seconds
    printf("Selection Sort Time: %f seconds\n", timeTaken);
    
    free(arr); // Free the allocated memory
    return 0;
}