//GEMINI-pro DATASET v1.0 Category: Educational ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of elements in the array
#define NUM_ELEMENTS 100

// Define the maximum value for the elements in the array
#define MAX_VALUE 100

// Generate a random array of integers
int* generate_random_array(int num_elements, int max_value) {
  int* array = malloc(sizeof(int) * num_elements);

  for (int i = 0; i < num_elements; i++) {
    array[i] = rand() % max_value;
  }

  return array;
}

// Print the array to the console
void print_array(int* array, int num_elements) {
  printf("[");
  for (int i = 0; i < num_elements; i++) {
    printf("%d, ", array[i]);
  }
  printf("]\n");
}

// Sort the array using the bubble sort algorithm
void bubble_sort(int* array, int num_elements) {
  for (int i = 0; i < num_elements - 1; i++) {
    for (int j = 0; j < num_elements - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}

// Main function
int main() {
  // Set the random seed
  srand(time(NULL));

  // Generate a random array
  int* array = generate_random_array(NUM_ELEMENTS, MAX_VALUE);

  // Print the unsorted array
  printf("Unsorted array:\n");
  print_array(array, NUM_ELEMENTS);

  // Sort the array
  bubble_sort(array, NUM_ELEMENTS);

  // Print the sorted array
  printf("Sorted array:\n");
  print_array(array, NUM_ELEMENTS);

  // Free the memory allocated for the array
  free(array);

  return 0;
}