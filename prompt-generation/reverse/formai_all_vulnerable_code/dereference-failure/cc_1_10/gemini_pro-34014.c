//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

// Create a random array of integers
int * create_array(int n) {
  int *arr = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    arr[i] = rand() % 100;
  }
  return arr;
}

// Print the array
void print_array(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// Sort the array using the bubble sort algorithm
void bubble_sort(int *arr, int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Create a random array of integers
  int *arr = create_array(N);

  // Print the unsorted array
  printf("Unsorted array:\n");
  print_array(arr, N);

  // Sort the array using the bubble sort algorithm
  bubble_sort(arr, N);

  // Print the sorted array
  printf("Sorted array:\n");
  print_array(arr, N);

  // Free the memory allocated for the array
  free(arr);

  return 0;
}