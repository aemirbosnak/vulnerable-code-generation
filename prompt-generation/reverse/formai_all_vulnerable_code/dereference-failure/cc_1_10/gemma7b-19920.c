//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a 2D array of integers
int **arr;

// Function to initialize a 2D array with zeros
void initialize_2D_array(int **arr, int rows, int cols) {
  arr = (int **)malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; i++) {
    arr[i] = (int *)malloc(cols * sizeof(int));
    for (int j = 0; j < cols; j++) {
      arr[i][j] = 0;
    }
  }
}

// Function to print a 2D array
void print_2D_array(int **arr, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}

int main() {
  // Initialize a 2D array of 5 rows and 5 columns
  initialize_2D_array(&arr, 5, 5);

  // Generate random numbers into the array
  srand(time(NULL));
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      arr[i][j] = rand() % 10;
    }
  }

  // Print the array
  print_2D_array(arr, 5, 5);

  // Free the memory allocated for the array
  for (int i = 0; i < 5; i++) {
    free(arr[i]);
  }
  free(arr);

  return 0;
}