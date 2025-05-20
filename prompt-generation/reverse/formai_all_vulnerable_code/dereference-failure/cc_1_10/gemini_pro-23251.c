//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the array size
#define ARRAY_SIZE 100

// Define the number of elements to search for
#define NUM_ELEMENTS_TO_SEARCH 10

// Define the maximum value for the elements
#define MAX_VALUE 100

// Generate a random array of integers
int* generate_random_array(int size, int max_value) {
  int* array = (int*)malloc(sizeof(int) * size);
  for (int i = 0; i < size; i++) {
    array[i] = rand() % max_value;
  }
  return array;
}

// Search for an element in an array using linear search
int linear_search(int* array, int size, int element) {
  for (int i = 0; i < size; i++) {
    if (array[i] == element) {
      return i;
    }
  }
  return -1;
}

// Search for an element in an array using binary search
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

// Print the array
void print_array(int* array, int size) {
  printf("[");
  for (int i = 0; i < size; i++) {
    printf("%d", array[i]);
    if (i < size - 1) {
      printf(", ");
    }
  }
  printf("]\n");
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate a random array
  int* array = generate_random_array(ARRAY_SIZE, MAX_VALUE);

  // Print the array
  printf("Array:\n");
  print_array(array, ARRAY_SIZE);

  // Generate a list of elements to search for
  int elements_to_search[NUM_ELEMENTS_TO_SEARCH];
  for (int i = 0; i < NUM_ELEMENTS_TO_SEARCH; i++) {
    elements_to_search[i] = rand() % MAX_VALUE;
  }

  // Search for each element in the array using linear search
  printf("\nLinear search results:\n");
  for (int i = 0; i < NUM_ELEMENTS_TO_SEARCH; i++) {
    int index = linear_search(array, ARRAY_SIZE, elements_to_search[i]);
    if (index == -1) {
      printf("Element %d not found.\n", elements_to_search[i]);
    } else {
      printf("Element %d found at index %d.\n", elements_to_search[i], index);
    }
  }

  // Search for each element in the array using binary search
  printf("\nBinary search results:\n");
  for (int i = 0; i < NUM_ELEMENTS_TO_SEARCH; i++) {
    int index = binary_search(array, ARRAY_SIZE, elements_to_search[i]);
    if (index == -1) {
      printf("Element %d not found.\n", elements_to_search[i]);
    } else {
      printf("Element %d found at index %d.\n", elements_to_search[i], index);
    }
  }

  // Free the memory allocated for the array
  free(array);

  return 0;
}