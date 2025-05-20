//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the array
#define SIZE 100

// Define the search value
#define SEARCH_VALUE 50

// Function to generate a random array
int *generate_array(int size) {
  int *array = malloc(sizeof(int) * size);

  for (int i = 0; i < size; i++) {
    array[i] = rand() % 100;
  }

  return array;
}

// Function to print the array
void print_array(int *array, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }

  printf("\n");
}

// Function to search for the value in the array
int search_array(int *array, int size, int value) {
  for (int i = 0; i < size; i++) {
    if (array[i] == value) {
      return i;
    }
  }

  return -1;
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate the array
  int *array = generate_array(SIZE);

  // Print the array
  printf("Array: ");
  print_array(array, SIZE);

  // Search for the value in the array
  int index = search_array(array, SIZE, SEARCH_VALUE);

  // Print the result
  if (index == -1) {
    printf("Value not found.\n");
  } else {
    printf("Value found at index %d.\n", index);
  }

  // Free the array
  free(array);

  return 0;
}