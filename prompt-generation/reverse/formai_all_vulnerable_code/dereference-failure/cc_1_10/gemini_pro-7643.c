//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of Fibonacci numbers to generate
#define MAX_FIB_NUMBERS 100

// Define the width and height of the output window
#define WINDOW_WIDTH 80
#define WINDOW_HEIGHT 25

// Define the colors for the Fibonacci numbers
#define FIB_COLOR_0 "\033[31m" // Red
#define FIB_COLOR_1 "\033[32m" // Green
#define FIB_COLOR_2 "\033[33m" // Yellow
#define FIB_COLOR_3 "\033[34m" // Blue
#define FIB_COLOR_4 "\033[35m" // Magenta
#define FIB_COLOR_5 "\033[36m" // Cyan
#define FIB_COLOR_6 "\033[37m" // White

// Define the reset color code
#define RESET_COLOR "\033[0m"

// Function to generate the Fibonacci numbers
int* generate_fibonacci_numbers(int num_numbers) {
  int* fib_numbers = malloc(sizeof(int) * num_numbers);

  fib_numbers[0] = 0;
  fib_numbers[1] = 1;

  for (int i = 2; i < num_numbers; i++) {
    fib_numbers[i] = fib_numbers[i - 1] + fib_numbers[i - 2];
  }

  return fib_numbers;
}

// Function to visualize the Fibonacci numbers
void visualize_fibonacci_numbers(int* fib_numbers, int num_numbers) {
  // Clear the screen
  system("clear");

  // Print the Fibonacci numbers
  for (int i = 0; i < num_numbers; i++) {
    switch (i % 6) {
      case 0:
        printf(FIB_COLOR_0 "%d ", fib_numbers[i]);
        break;
      case 1:
        printf(FIB_COLOR_1 "%d ", fib_numbers[i]);
        break;
      case 2:
        printf(FIB_COLOR_2 "%d ", fib_numbers[i]);
        break;
      case 3:
        printf(FIB_COLOR_3 "%d ", fib_numbers[i]);
        break;
      case 4:
        printf(FIB_COLOR_4 "%d ", fib_numbers[i]);
        break;
      case 5:
        printf(FIB_COLOR_5 "%d ", fib_numbers[i]);
        break;
    }
  }

  // Reset the color
  printf(RESET_COLOR);
}

// Main function
int main() {
  // Generate the Fibonacci numbers
  int* fib_numbers = generate_fibonacci_numbers(MAX_FIB_NUMBERS);

  // Visualize the Fibonacci numbers
  visualize_fibonacci_numbers(fib_numbers, MAX_FIB_NUMBERS);

  // Free the allocated memory
  free(fib_numbers);

  return 0;
}