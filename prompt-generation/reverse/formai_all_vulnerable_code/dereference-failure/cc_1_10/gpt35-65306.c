//FormAI DATASET v1.0 Category: Memory management ; Style: mathematical
// A mathematical approach to Memory Management in C

#include <stdio.h>
#include <stdlib.h>

// Function to calculate the sum of n natural numbers
int sum(int n) {
    return (n * (n+1)) / 2;
}

int main() {
    // Allocate memory for an array of size 10 using malloc
    int *arr = (int*) malloc(10 * sizeof(int)); 

    // Initialize array with multiples of 3
    for(int i=0; i<10; i++) {
        arr[i] = 3 * (i+1);
    }

    // Calculate the sum of all elements in the array
    int total_sum = 0;
    for(int i=0; i<10; i++) {
        total_sum += arr[i];
    }

    // Print the sum to the console
    printf("Sum of all elements in the array: %d\n", total_sum);

    // Reallocate memory for a larger array of size 15 using realloc
    arr = (int*) realloc(arr, 15 * sizeof(int));
    
    // Initialize the additional elements with squares of even numbers
    for(int i=10; i<15; i++) {
        if(i % 2 == 0) {
            arr[i] = i * i;
        }
    }

    // Calculate the sum of all elements in the array again
    total_sum = 0;
    for(int i=0; i<15; i++) {
        total_sum += arr[i];
    }

    // Print the sum to the console again
    printf("Sum of all elements in the resized array: %d\n", total_sum);

    // Deallocate memory allocated for the array using free
    free(arr);

    return 0;
}