//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum size of the array
#define MAX_SIZE 100000

// Function to generate a random array of integers
int* generate_array(int size) {
  int* arr = (int*)malloc(sizeof(int) * size);

  for (int i = 0; i < size; i++) {
    arr[i] = rand() % 1000;
  }

  return arr;
}

// Function to find the maximum element in an array
int find_max(int* arr, int size) {
  int max = arr[0];

  for (int i = 1; i < size; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }

  return max;
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Generate an array of random integers
  int* arr = generate_array(MAX_SIZE);

  // Find the maximum element in the array
  int max = find_max(arr, MAX_SIZE);

  // Print the maximum element
  printf("The maximum element is: %d\n", max);

  // Free the allocated memory
  free(arr);

  return 0;
}