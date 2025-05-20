//Falcon-180B DATASET v1.0 Category: Sorting ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

// Function to generate a random array of integers
void generate_array(int arr[], int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_SIZE;
    }
}

// Function to print an array of integers
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform counting sort
void counting_sort(int arr[], int size) {
    int count[MAX_SIZE] = {0};
    int output[size];

    // Count the frequency of each element
    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }

    // Modify count array to store the cumulative frequency
    for (int i = 1; i < MAX_SIZE; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = size - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the output array to the original array
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
}

int main() {
    int arr[MAX_SIZE];
    int size;

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Generate a random array of integers
    generate_array(arr, size);

    // Print the original array
    printf("Original array:\n");
    print_array(arr, size);

    // Perform counting sort
    counting_sort(arr, size);

    // Print the sorted array
    printf("Sorted array:\n");
    print_array(arr, size);

    return 0;
}