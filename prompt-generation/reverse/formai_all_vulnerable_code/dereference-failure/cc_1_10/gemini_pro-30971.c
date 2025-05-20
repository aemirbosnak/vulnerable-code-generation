//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

// Linus Torvalds style Fibonacci Sequence Visualizer

// Define the maximum number of Fibonacci numbers to generate
#define MAX_FIB 100

// Define the colors for the Fibonacci numbers
#define COLOR_WHITE  "\033[0m"
#define COLOR_RED    "\033[31m"
#define COLOR_GREEN  "\033[32m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_BLUE   "\033[34m"
#define COLOR_MAGENTA "\033[35m"
#define COLOR_CYAN   "\033[36m"

// Define the array to store the Fibonacci numbers
unsigned long long fib[MAX_FIB];

// Define the function to generate the Fibonacci numbers
void generate_fibonacci(int n) {
  fib[0] = 0;
  fib[1] = 1;
  for (int i = 2; i < n; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }
}

// Define the function to print the Fibonacci numbers
void print_fibonacci(int n) {
  for (int i = 0; i < n; i++) {
    // Choose a color for the Fibonacci number
    switch (i % 7) {
      case 0: printf(COLOR_WHITE); break;
      case 1: printf(COLOR_RED); break;
      case 2: printf(COLOR_GREEN); break;
      case 3: printf(COLOR_YELLOW); break;
      case 4: printf(COLOR_BLUE); break;
      case 5: printf(COLOR_MAGENTA); break;
      case 6: printf(COLOR_CYAN); break;
    }

    // Print the Fibonacci number
    printf("%llu ", fib[i]);
  }

  // Reset the color to white
  printf(COLOR_WHITE);
}

// Define the function to visualize the Fibonacci numbers
void visualize_fibonacci(int n) {
  // Generate the Fibonacci numbers
  generate_fibonacci(n);

  // Print the Fibonacci numbers
  print_fibonacci(n);

  // Print a newline character
  printf("\n");
}

// Define the main function
int main(int argc, char *argv[]) {
  // Check if the number of arguments is valid
  if (argc != 2) {
    printf("Usage: %s <n>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Get the number of Fibonacci numbers to generate
  int n = atoi(argv[1]);

  // Visualize the Fibonacci numbers
  visualize_fibonacci(n);

  return EXIT_SUCCESS;
}