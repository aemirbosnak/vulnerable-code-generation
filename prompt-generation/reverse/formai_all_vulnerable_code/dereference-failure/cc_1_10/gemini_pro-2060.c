//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Function to calculate the Fibonacci sequence
int fibonacci(int n) {
  if (n <= 1) {
    return n;
  } else {
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}

// Function to create a visual representation of the Fibonacci sequence
void visualizeFibonacci(int n) {
  // Calculate the maximum width of the Fibonacci numbers
  int max_width = floor(log10(fibonacci(n))) + 1;

  // Create a 2D array to store the Fibonacci numbers
  int **fib_array = malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    fib_array[i] = malloc(max_width * sizeof(int));
  }

  // Initialize the 2D array with the Fibonacci numbers
  for (int i = 0; i < n; i++) {
    int fib = fibonacci(i);
    int num_digits = floor(log10(fib)) + 1;
    for (int j = 0; j < max_width; j++) {
      if (j < max_width - num_digits) {
        fib_array[i][j] = ' ';
      } else {
        fib_array[i][j] = fib % 10 + '0';
        fib /= 10;
      }
    }
  }

  // Print the 2D array as a visual representation of the Fibonacci sequence
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < max_width; j++) {
      printf("%c", fib_array[i][j]);
    }
    printf("\n");
  }

  // Free the 2D array
  for (int i = 0; i < n; i++) {
    free(fib_array[i]);
  }
  free(fib_array);
}

int main() {
  // Get the number of Fibonacci numbers to generate
  int n;
  printf("Enter the number of Fibonacci numbers to generate: ");
  scanf("%d", &n);

  // Visualize the Fibonacci sequence
  visualizeFibonacci(n);

  return 0;
}