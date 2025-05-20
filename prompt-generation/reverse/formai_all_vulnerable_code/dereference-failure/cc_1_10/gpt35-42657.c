//FormAI DATASET v1.0 Category: Memory management ; Style: Claude Shannon
/* 
   This program demonstrates memory management in C by dynamically creating
   an array of integers and dynamically resizing the array using realloc.

   We initialize the array with random integers between 0 and 100 and print
   the array. Then we extend the array by 5 elements, fill these with random
   integers, and print the array again.

   Author: Claude Shannon
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed the random number generator

    int size = 10; // Starting size of the array
    int* array = (int*) malloc(size * sizeof(int)); // Allocate memory for the array

    // Initialize the array with random integers
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 101;
    }

    // Print the array
    printf("Original array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    // Extend the array by 5 elements and fill them with random integers
    size += 5;
    array = (int*) realloc(array, size * sizeof(int)); // Resize the array
    for (int i = size - 5; i < size; i++) {
        array[i] = rand() % 101;
    }

    // Print the array again
    printf("\n\nExtended array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    // Free the memory allocated for the array
    free(array);

    return 0;
}