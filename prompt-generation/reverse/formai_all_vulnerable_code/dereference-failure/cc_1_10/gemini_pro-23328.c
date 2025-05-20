//GEMINI-pro DATASET v1.0 Category: Educational ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of elements in the array
#define MAX_SIZE 100

// Create a function to generate a random array
int* generate_random_array(int size) {
    // Allocate memory for the array
    int* array = (int*)malloc(size * sizeof(int));

    // Initialize the random number generator
    srand(time(NULL));

    // Generate random numbers and store them in the array
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }

    // Return the array
    return array;
}

// Create a function to find the maximum element in the array
int find_max_element(int* array, int size) {
    // Initialize the maximum element to the first element in the array
    int max_element = array[0];

    // Iterate over the array and update the maximum element if a larger element is found
    for (int i = 1; i < size; i++) {
        if (array[i] > max_element) {
            max_element = array[i];
        }
    }

    // Return the maximum element
    return max_element;
}

// Create a function to find the minimum element in the array
int find_min_element(int* array, int size) {
    // Initialize the minimum element to the first element in the array
    int min_element = array[0];

    // Iterate over the array and update the minimum element if a smaller element is found
    for (int i = 1; i < size; i++) {
        if (array[i] < min_element) {
            min_element = array[i];
        }
    }

    // Return the minimum element
    return min_element;
}

// Create a function to find the average of the elements in the array
float find_average(int* array, int size) {
    // Initialize the sum of the elements to 0
    int sum = 0;

    // Iterate over the array and add each element to the sum
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }

    // Calculate the average
    float average = (float)sum / size;

    // Return the average
    return average;
}

// Create a function to print the array
void print_array(int* array, int size) {
    // Iterate over the array and print each element
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    // Print a newline
    printf("\n");
}

// Create a function to test the functions
void test_functions() {
    // Generate a random array
    int* array = generate_random_array(MAX_SIZE);

    // Print the array
    printf("Original array: ");
    print_array(array, MAX_SIZE);

    // Find the maximum element
    int max_element = find_max_element(array, MAX_SIZE);

    // Print the maximum element
    printf("Maximum element: %d\n", max_element);

    // Find the minimum element
    int min_element = find_min_element(array, MAX_SIZE);

    // Print the minimum element
    printf("Minimum element: %d\n", min_element);

    // Find the average of the elements
    float average = find_average(array, MAX_SIZE);

    // Print the average
    printf("Average: %.2f\n", average);

    // Free the memory allocated for the array
    free(array);
}

// Create a main function
int main() {
    // Test the functions
    test_functions();

    return 0;
}