//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the Percolation Model
#define N 10
#define P 0.5

// Function to simulate Percolation
void percolate(int **arr, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[i][j] == 1 && rand() % 2 == 0) {
        arr[i][j] = 0;
      }
    }
  }
}

// Function to print the Percolation Array
void printArray(int **arr, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}

int main() {
  // Create a 2D array to simulate the Percolation model
  int **arr = (int **)malloc(N * sizeof(int *));
  for (int i = 0; i < N; i++) {
    arr[i] = (int *)malloc(N * sizeof(int));
  }

  // Initialize the array with random numbers
  srand(time(NULL));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      arr[i][j] = rand() % 2;
    }
  }

  // Simulate Percolation
  percolate(arr, N);

  // Print the Percolation Array
  printArray(arr, N);

  // Free the memory allocated for the array
  for (int i = 0; i < N; i++) {
    free(arr[i]);
  }
  free(arr);

  return 0;
}