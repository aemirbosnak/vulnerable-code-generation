//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Function to generate a random array of integers
int* generate_random_array(int size) {
  int* array = (int*)malloc(size * sizeof(int));
  for (int i = 0; i < size; i++) {
    array[i] = rand() % 100;  // Generate a random number between 0 and 99
  }
  return array;
}

// Function to print an array of integers
void print_array(int* array, int size) {
  printf("[");
  for (int i = 0; i < size; i++) {
    printf("%d, ", array[i]);
  }
  printf("]\n");
}

// Function to search for a target element in an array using linear search
int linear_search(int* array, int size, int target) {
  for (int i = 0; i < size; i++) {
    if (array[i] == target) {
      return i;  // Return the index of the target element if found
    }
  }
  return -1;  // Return -1 if the target element is not found
}

// Function to search for a target element in an array using binary search
int binary_search(int* array, int size, int target) {
  int low = 0;
  int high = size - 1;

  while (low <= high) {
    int mid = (low + high) / 2;  // Calculate the middle index

    if (array[mid] == target) {
      return mid;  // Return the index of the target element if found
    } else if (array[mid] < target) {
      low = mid + 1;  // Search in the right half
    } else {
      high = mid - 1;  // Search in the left half
    }
  }
  return -1;  // Return -1 if the target element is not found
}

// Function to test the searching algorithms
void test_searching_algorithms() {
  srand(time(NULL));  // Initialize the random number generator

  // Generate a random array of integers
  int* array = generate_random_array(MAX_SIZE);

  // Print the original array
  printf("Original array:\n");
  print_array(array, MAX_SIZE);

  // Search for a target element using linear search
  int target = rand() % 100;  // Generate a random target element
  int linear_search_result = linear_search(array, MAX_SIZE, target);
  printf("Target element: %d\n", target);

  if (linear_search_result == -1) {
    printf("Linear search: Target element not found\n");
  } else {
    printf("Linear search: Target element found at index %d\n", linear_search_result);
  }

  // Search for the same target element using binary search
  int binary_search_result = binary_search(array, MAX_SIZE, target);

  if (binary_search_result == -1) {
    printf("Binary search: Target element not found\n");
  } else {
    printf("Binary search: Target element found at index %d\n", binary_search_result);
  }

  free(array);  // Free the allocated memory
}

int main() {
  printf("**Searching Algorithms**\n");

  test_searching_algorithms();

  return 0;
}