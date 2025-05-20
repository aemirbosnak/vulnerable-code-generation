//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: creative
#include <stdio.h>

int main() {
  int n;
  printf("Enter the number of terms: ");
  scanf("%d", &n);

  int a = 0, b = 1, c;

  printf("Fibonacci sequence: ");
  for (int i = 1; i <= n; i++) {
    printf("%d ", a);
    c = a + b;
    a = b;
    b = c;
  }

  // Display the Fibonacci sequence as a spiral
  int width = n * 2;
  int height = n * 2;
  char grid[width][height];

  // Initialize the grid with spaces
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      grid[i][j] = ' ';
    }
  }

  // Mark the starting point
  grid[width / 2][height / 2] = '*';

  // Draw the spiral
  int x = width / 2;
  int y = height / 2;
  int direction = 0;  // 0: right, 1: down, 2: left, 3: up
  int steps = 1;  // Number of steps in the current direction
  int count = 1;  // Current Fibonacci number

  while (count <= n) {
    // Move in the current direction for the specified number of steps
    for (int i = 0; i < steps; i++) {
      switch (direction) {
        case 0:
          x++;
          break;
        case 1:
          y++;
          break;
        case 2:
          x--;
          break;
        case 3:
          y--;
          break;
      }

      // Mark the current position with the corresponding Fibonacci number
      grid[x][y] = count + '0';
      count++;
    }

    // Change the direction
    direction = (direction + 1) % 4;

    // Increase the number of steps
    steps++;
  }

  // Print the grid
  printf("\n\nFibonacci spiral:\n");
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      printf("%c", grid[i][j]);
    }
    printf("\n");
  }

  return 0;
}