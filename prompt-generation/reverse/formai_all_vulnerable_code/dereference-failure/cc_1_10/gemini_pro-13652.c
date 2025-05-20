//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ROWS 25
#define COLUMNS 80

int main(int argc, char *argv[]) {
  int **grid;
  int i, j, n;
  int max_fib;
  int num_fibs;
  int num_leading_spaces;
  int num_trailing_spaces;
  int num_printed;
  char *fib_str;
  char *padded_str;

  // Allocate memory for the grid.
  grid = (int **)malloc(ROWS * sizeof(int *));
  for (i = 0; i < ROWS; i++) {
    grid[i] = (int *)malloc(COLUMNS * sizeof(int));
  }

  // Initialize the grid to 0.
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLUMNS; j++) {
      grid[i][j] = 0;
    }
  }

  // Get the maximum Fibonacci number to display.
  printf("Enter the maximum Fibonacci number to display: ");
  scanf("%d", &max_fib);

  // Calculate the number of Fibonacci numbers to display.
  num_fibs = (int)floor(log10(max_fib)) + 1;

  // Calculate the number of leading spaces for each number.
  num_leading_spaces = (COLUMNS - num_fibs) / 2;

  // Calculate the number of trailing spaces for each number.
  num_trailing_spaces = COLUMNS - num_leading_spaces - num_fibs;

  // Calculate the Fibonacci sequence.
  fib_str = (char *)malloc(num_fibs * sizeof(char));
  for (i = 0; i < num_fibs; i++) {
    fib_str[i] = fibonacci(i);
  }

  // Pad each number with leading and trailing spaces.
  padded_str = (char *)malloc(COLUMNS * sizeof(char));
  for (i = 0; i < num_fibs; i++) {
    memset(padded_str, ' ', COLUMNS);
    strncpy(padded_str + num_leading_spaces, fib_str + i, num_fibs - i);
    padded_str[COLUMNS - 1] = '\0';
    grid[i][0] = 1;
  }

  // Draw the grid.
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLUMNS; j++) {
      if (grid[i][j] == 0) {
        printf(" ");
      } else {
        printf("%c", padded_str[j]);
      }
    }
    printf("\n");
  }

  // Free the allocated memory.
  free(grid);
  free(fib_str);
  free(padded_str);

  return 0;
}

int fibonacci(int n) {
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}