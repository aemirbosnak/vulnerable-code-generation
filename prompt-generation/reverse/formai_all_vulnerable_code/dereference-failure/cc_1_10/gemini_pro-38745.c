//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the array
#define SIZE 10

// Define the search key
#define KEY 5

// Function to generate a random array
int *generate_array(int size) {
  int *array = (int *)malloc(sizeof(int) * size);

  for (int i = 0; i < size; i++) {
    array[i] = rand() % 100;
  }

  return array;
}

// Function to search for the key in the array using linear search
int linear_search(int *array, int size, int key) {
  for (int i = 0; i < size; i++) {
    if (array[i] == key) {
      return i;
    }
  }

  return -1;
}

// Function to search for the key in the array using binary search
int binary_search(int *array, int size, int key) {
  int low = 0;
  int high = size - 1;

  while (low <= high) {
    int mid = (low + high) / 2;

    if (array[mid] == key) {
      return mid;
    } else if (array[mid] < key) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return -1;
}

// Function to print the array
void print_array(int *array, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }

  printf("\n");
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate a random array
  int *array = generate_array(SIZE);

  // Print the array
  printf("Array: ");
  print_array(array, SIZE);

  // Search for the key using linear search
  int linear_search_result = linear_search(array, SIZE, KEY);

  if (linear_search_result != -1) {
    printf("Key found at index %d using linear search\n", linear_search_result);
  } else {
    printf("Key not found using linear search\n");
  }

  // Search for the key using binary search
  int binary_search_result = binary_search(array, SIZE, KEY);

  if (binary_search_result != -1) {
    printf("Key found at index %d using binary search\n", binary_search_result);
  } else {
    printf("Key not found using binary search\n");
  }

  // Free the memory allocated for the array
  free(array);

  return 0;
}