//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the nth Fibonacci number
unsigned long long int fib(unsigned int n) {
  if (n <= 1) {
    return n;
  } else {
    return fib(n - 1) + fib(n - 2);
  }
}

// Function to visualize the Fibonacci sequence
void visualize_fib(unsigned int n) {
  // Initialize the Fibonacci sequence
  unsigned long long int* fib_seq = malloc(n * sizeof(unsigned long long int));
  for (unsigned int i = 0; i < n; i++) {
    fib_seq[i] = fib(i);
  }

  // Print the Fibonacci sequence in a table
  printf("Fibonacci Sequence:\n");
  printf("---------------------\n");
  printf("| Index | Fibonacci Number |\n");
  printf("---------------------\n");
  for (unsigned int i = 0; i < n; i++) {
    printf("| %4u | %20llu |\n", i, fib_seq[i]);
  }

  // Free the allocated memory
  free(fib_seq);
}

// Function to generate a random number between min and max
unsigned int random_number(unsigned int min, unsigned int max) {
  return rand() % (max - min + 1) + min;
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Get a random number between 1 and 100
  unsigned int n = random_number(1, 100);

  // Visualize the Fibonacci sequence
  visualize_fib(n);

  return 0;
}