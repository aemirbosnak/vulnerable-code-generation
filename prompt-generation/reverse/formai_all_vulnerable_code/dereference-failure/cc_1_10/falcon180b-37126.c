//Falcon-180B DATASET v1.0 Category: Educational ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of integers to generate
#define MAX_NUMBERS 1000

// Function to generate a random integer between min and max (inclusive)
int generate_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate an array of random integers
int* generate_random_array(int size, int min, int max) {
    int* array = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        array[i] = generate_random_number(min, max);
    }
    return array;
}

// Function to sort an array of integers using bubble sort
void bubble_sort(int* array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Function to print an array of integers
void print_array(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Main function
int main() {
    srand(time(NULL));

    // Generate an array of random integers
    int* array = generate_random_array(MAX_NUMBERS, 1, 100);

    // Print the unsorted array
    printf("Unsorted array:\n");
    print_array(array, MAX_NUMBERS);

    // Sort the array
    bubble_sort(array, MAX_NUMBERS);

    // Print the sorted array
    printf("Sorted array:\n");
    print_array(array, MAX_NUMBERS);

    return 0;
}