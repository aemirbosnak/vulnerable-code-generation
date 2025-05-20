//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate the Fibonacci sequence
int* fibonacci(int n) {
  int* fib = malloc(n * sizeof(int));
  fib[0] = 0;
  fib[1] = 1;
  for (int i = 2; i < n; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }
  return fib;
}

// Function to visualize the Fibonacci sequence
void visualize(int* fib, int n) {
  // Create a 2D array to represent the Fibonacci sequence
  int** grid = malloc(n * sizeof(int*));
  for (int i = 0; i < n; i++) {
    grid[i] = malloc(n * sizeof(int));
  }

  // Initialize the grid with zeros
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      grid[i][j] = 0;
    }
  }

  // Fill the grid with the Fibonacci sequence
  int x = n / 2;
  int y = n / 2;
  int dir = 0; // 0: right, 1: up, 2: left, 3: down
  for (int i = 0; i < n * n; i++) {
    grid[x][y] = fib[i];
    switch (dir) {
      case 0:
        if (x + 1 < n && grid[x + 1][y] == 0) {
          x++;
        } else {
          dir = 1;
          y--;
        }
        break;
      case 1:
        if (y - 1 >= 0 && grid[x][y - 1] == 0) {
          y--;
        } else {
          dir = 2;
          x--;
        }
        break;
      case 2:
        if (x - 1 >= 0 && grid[x - 1][y] == 0) {
          x--;
        } else {
          dir = 3;
          y++;
        }
        break;
      case 3:
        if (y + 1 < n && grid[x][y + 1] == 0) {
          y++;
        } else {
          dir = 0;
          x++;
        }
        break;
    }
  }

  // Print the grid
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }

  // Free the grid
  for (int i = 0; i < n; i++) {
    free(grid[i]);
  }
  free(grid);
}

int main() {
  // Get the number of terms in the Fibonacci sequence
  int n;
  printf("Enter the number of terms in the Fibonacci sequence: ");
  scanf("%d", &n);

  // Generate the Fibonacci sequence
  int* fib = fibonacci(n);

  // Visualize the Fibonacci sequence
  visualize(fib, n);

  // Free the Fibonacci sequence
  free(fib);

  return 0;
}