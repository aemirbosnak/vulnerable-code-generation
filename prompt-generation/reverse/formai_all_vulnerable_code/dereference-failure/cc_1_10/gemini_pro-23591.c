//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to generate the Fibonacci sequence
int* generateFibonacciSequence(int n) {
  int* sequence = (int*)malloc(sizeof(int) * n);
  sequence[0] = 0;
  sequence[1] = 1;
  for (int i = 2; i < n; i++) {
    sequence[i] = sequence[i - 1] + sequence[i - 2];
  }
  return sequence;
}

// Function to print the Fibonacci sequence
void printFibonacciSequence(int* sequence, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", sequence[i]);
  }
  printf("\n");
}

// Function to visualize the Fibonacci sequence
void visualizeFibonacciSequence(int* sequence, int n) {
  // Create a 2D array to store the visualization
  char** visualization = (char**)malloc(sizeof(char*) * n);
  for (int i = 0; i < n; i++) {
    visualization[i] = (char*)malloc(sizeof(char) * sequence[i]);
  }

  // Fill the visualization with spaces
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < sequence[i]; j++) {
      visualization[i][j] = ' ';
    }
  }

  // Fill the visualization with asterisks
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < sequence[i]; j++) {
      visualization[i][j] = '*';
    }
  }

  // Print the visualization
  for (int i = 0; i < n; i++) {
    printf("%s\n", visualization[i]);
  }

  // Free the memory allocated for the visualization
  for (int i = 0; i < n; i++) {
    free(visualization[i]);
  }
  free(visualization);
}

int main() {
  // Generate the Fibonacci sequence
  int* sequence = generateFibonacciSequence(MAX_SIZE);

  // Print the Fibonacci sequence
  printFibonacciSequence(sequence, MAX_SIZE);

  // Visualize the Fibonacci sequence
  visualizeFibonacciSequence(sequence, MAX_SIZE);

  // Free the memory allocated for the sequence
  free(sequence);

  return 0;
}