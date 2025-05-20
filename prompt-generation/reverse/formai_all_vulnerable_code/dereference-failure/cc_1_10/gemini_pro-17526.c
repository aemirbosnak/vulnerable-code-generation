//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000 // Array size

// Function to generate a random array
int *generate_array(int size) {
  int *array = malloc(sizeof(int) * size);
  for (int i = 0; i < size; i++) {
    array[i] = rand() % 1000; // Generate a random number between 0 and 999
  }
  return array;
}

// Function to search for an element in an array using linear search
int linear_search(int *array, int size, int element) {
  for (int i = 0; i < size; i++) {
    if (array[i] == element) {
      return i; // Return the index of the element if found
    }
  }
  return -1; // Return -1 if the element is not found
}

// Function to search for an element in an array using binary search
int binary_search(int *array, int size, int element) {
  int low = 0;
  int high = size - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (array[mid] == element) {
      return mid; // Return the index of the element if found
    } else if (array[mid] < element) {
      low = mid + 1; // Search in the right half of the array
    } else {
      high = mid - 1; // Search in the left half of the array
    }
  }
  return -1; // Return -1 if the element is not found
}

// Function to print the array
void print_array(int *array, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate a random array
  int *array = generate_array(SIZE);

  // Print the original array
  printf("Original array:\n");
  print_array(array, SIZE);

  // Search for an element in the array using linear search
  int element = 500; // The element to search for
  int index = linear_search(array, SIZE, element);
  if (index == -1) {
    printf("Element not found using linear search.\n");
  } else {
    printf("Element found at index %d using linear search.\n", index);
  }

  // Search for the same element in the array using binary search
  index = binary_search(array, SIZE, element);
  if (index == -1) {
    printf("Element not found using binary search.\n");
  } else {
    printf("Element found at index %d using binary search.\n", index);
  }

  // Free the allocated memory
  free(array);

  return 0;
}