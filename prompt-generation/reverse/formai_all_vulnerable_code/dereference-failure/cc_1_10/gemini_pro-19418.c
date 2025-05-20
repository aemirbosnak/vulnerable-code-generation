//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Define the number of Fibonacci numbers to generate.
#define NUM_FIB 50

// Define the maximum number of digits in a Fibonacci number.
#define MAX_DIGITS 100

// Define the base of the number system to use.
#define BASE 10

// Define the number of columns to use in the visualization.
#define NUM_COLS 10

// Define the number of rows to use in the visualization.
#define NUM_ROWS 10

// Define the character to use for the background.
#define BG_CHAR ' '

// Define the character to use for the Fibonacci numbers.
#define FIB_CHAR '*'

// Define the character to use for the grid lines.
#define GRID_CHAR '|'

// Define the character to use for the axis labels.
#define AXIS_CHAR '-'

// Define the width of the axis labels.
#define AXIS_WIDTH 10

// Define the height of the axis labels.
#define AXIS_HEIGHT 10

// Define the color of the background.
#define BG_COLOR 0

// Define the color of the Fibonacci numbers.
#define FIB_COLOR 1

// Define the color of the grid lines.
#define GRID_COLOR 2

// Define the color of the axis labels.
#define AXIS_COLOR 3

// Define the function to generate the Fibonacci numbers.
int *generate_fibonacci_numbers(int n) {
  int *fib = malloc(n * sizeof(int));
  fib[0] = 0;
  fib[1] = 1;
  for (int i = 2; i < n; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }
  return fib;
}

// Define the function to convert a number to a string.
char *number_to_string(int n) {
  char *str = malloc(MAX_DIGITS * sizeof(char));
  int i = 0;
  while (n > 0) {
    str[i++] = n % BASE + '0';
    n /= BASE;
  }
  str[i] = '\0';
  return str;
}

// Define the function to draw the visualization.
void draw_visualization(int *fib) {
  // Create a 2D array to store the visualization.
  char **vis = malloc(NUM_ROWS * sizeof(char *));
  for (int i = 0; i < NUM_ROWS; i++) {
    vis[i] = malloc(NUM_COLS * sizeof(char));
  }

  // Initialize the visualization to the background character.
  for (int i = 0; i < NUM_ROWS; i++) {
    for (int j = 0; j < NUM_COLS; j++) {
      vis[i][j] = BG_CHAR;
    }
  }

  // Draw the Fibonacci numbers.
  for (int i = 0; i < NUM_FIB; i++) {
    int n = fib[i];
    int row = i / NUM_COLS;
    int col = i % NUM_COLS;
    char *str = number_to_string(n);
    int len = strlen(str);
    for (int j = 0; j < len; j++) {
      vis[row][col + j] = str[j];
    }
  }

  // Draw the grid lines.
  for (int i = 0; i < NUM_ROWS; i++) {
    vis[i][NUM_COLS - 1] = GRID_CHAR;
  }
  for (int j = 0; j < NUM_COLS; j++) {
    vis[NUM_ROWS - 1][j] = GRID_CHAR;
  }

  // Draw the axis labels.
  for (int i = 0; i < NUM_ROWS; i++) {
    char *str = number_to_string(i);
    int len = strlen(str);
    for (int j = 0; j < len; j++) {
      vis[i][NUM_COLS - 1 - j] = str[j];
    }
  }
  for (int j = 0; j < NUM_COLS; j++) {
    char *str = number_to_string(j);
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
      vis[NUM_ROWS - 1 - i][j] = str[i];
    }
  }

  // Print the visualization to the console.
  for (int i = 0; i < NUM_ROWS; i++) {
    for (int j = 0; j < NUM_COLS; j++) {
      printf("%c", vis[i][j]);
    }
    printf("\n");
  }

  // Free the memory allocated for the visualization.
  for (int i = 0; i < NUM_ROWS; i++) {
    free(vis[i]);
  }
  free(vis);
}

// Define the main function.
int main() {
  // Generate the Fibonacci numbers.
  int *fib = generate_fibonacci_numbers(NUM_FIB);

  // Draw the visualization.
  draw_visualization(fib);

  // Free the memory allocated for the Fibonacci numbers.
  free(fib);

  return 0;
}