//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of elements in the array
#define ARRAY_SIZE 100000

// Function to generate a random array of integers
int* generate_random_array(int size) {
  int* array = malloc(sizeof(int) * size);
  for (int i = 0; i < size; i++) {
    array[i] = rand() % 10000;
  }
  return array;
}

// Function to print an array of integers
void print_array(int* array, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

// Function to swap two integers
void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Function to perform the bubble sort algorithm
void bubble_sort(int* array, int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        swap(&array[j], &array[j + 1]);
      }
    }
  }
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate a random array of integers
  int* array = generate_random_array(ARRAY_SIZE);

  // Print the unsorted array
  printf("Unsorted array:\n");
  print_array(array, ARRAY_SIZE);

  // Sort the array using the bubble sort algorithm
  bubble_sort(array, ARRAY_SIZE);

  // Print the sorted array
  printf("Sorted array:\n");
  print_array(array, ARRAY_SIZE);

  // Free the memory allocated for the array
  free(array);

  return 0;
}