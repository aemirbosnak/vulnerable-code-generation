//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

// Defining the maximum number of Fibonacci numbers to generate
#define MAX_NUMBERS 20

// Function to generate the Fibonacci sequence
void generate_fibonacci(int *fibonacci, int n) {
  // Initializing the first two Fibonacci numbers
  fibonacci[0] = 0;
  fibonacci[1] = 1;

  // Generating the remaining Fibonacci numbers
  for (int i = 2; i < n; i++) {
    fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
  }
}

// Function to print the Fibonacci sequence in a post-apocalyptic style
void print_fibonacci(int *fibonacci, int n) {
  // Printing the header
  printf("\n\n\t\t********************************************************\n");
  printf("\t\t*                Fibonacci Sequence Visualizer             *\n");
  printf("\t\t********************************************************\n\n");

  // Printing the Fibonacci numbers
  for (int i = 0; i < n; i++) {
    // Printing the Fibonacci number
    printf("\t\t*  %d  ", fibonacci[i]);

    // Printing the post-apocalyptic style
    if (i % 5 == 0) {
      printf("\n\t\t*  ---------------------------------------------------- *\n");
    }
  }

  // Printing the footer
  printf("\n\t\t********************************************************\n\n");
}

// Main function
int main() {
  // Allocating memory for the Fibonacci sequence
  int *fibonacci = (int *)malloc(MAX_NUMBERS * sizeof(int));

  // Generating the Fibonacci sequence
  generate_fibonacci(fibonacci, MAX_NUMBERS);

  // Printing the Fibonacci sequence
  print_fibonacci(fibonacci, MAX_NUMBERS);

  // Freeing the allocated memory
  free(fibonacci);

  return 0;
}