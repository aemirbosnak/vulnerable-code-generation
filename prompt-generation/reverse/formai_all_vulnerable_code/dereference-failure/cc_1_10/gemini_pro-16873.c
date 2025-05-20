//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Function to generate a random array of integers
int* generate_random_array(int size) {
  int* array = malloc(sizeof(int) * size);
  for (int i = 0; i < size; i++) {
    array[i] = rand() % 100;
  }
  return array;
}

// Function to print the array
void print_array(int* array, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

// Function to search for an element in the array using linear search
int linear_search(int* array, int size, int element) {
  for (int i = 0; i < size; i++) {
    if (array[i] == element) {
      return i;
    }
  }
  return -1;
}

// Function to search for an element in the array using binary search
int binary_search(int* array, int size, int element) {
  int low = 0;
  int high = size - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (array[mid] == element) {
      return mid;
    } else if (array[mid] < element) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}

// Main function
int main() {
  // Generate a random array of integers
  int* array = generate_random_array(MAX_SIZE);

  // Print the original array
  printf("Original array:\n");
  print_array(array, MAX_SIZE);

  // Search for an element in the array using linear search
  int element_to_search = 50;
  int index_linear_search = linear_search(array, MAX_SIZE, element_to_search);
  if (index_linear_search != -1) {
    printf("Element %d found at index %d using linear search\n", element_to_search, index_linear_search);
  } else {
    printf("Element %d not found using linear search\n", element_to_search);
  }

  // Search for the same element in the array using binary search
  int index_binary_search = binary_search(array, MAX_SIZE, element_to_search);
  if (index_binary_search != -1) {
    printf("Element %d found at index %d using binary search\n", element_to_search, index_binary_search);
  } else {
    printf("Element %d not found using binary search\n", element_to_search);
  }

  // Free the allocated memory
  free(array);

  return 0;
}