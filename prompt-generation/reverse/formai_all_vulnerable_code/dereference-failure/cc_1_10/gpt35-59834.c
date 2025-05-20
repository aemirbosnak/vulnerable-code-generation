//FormAI DATASET v1.0 Category: Game of Life ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 30


// Function to generate the initial state of the grid
void initGrid(int **grid, int w, int h) {
  srand(time(NULL));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      grid[i][j] = rand() % 2;
    }
  }
}


// Function to print the current state of the grid
void printGrid(int **grid, int w, int h) {
  printf("\033[2J"); // Clear the terminal
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (grid[i][j]) {
        printf("\033[1;42m  \033[0m"); // Green block for alive cells
      } else {
        printf("\033[1;40m  \033[0m"); // Black block for dead cells
      }
    }
    printf("\n");
  }
}


// Function to count the number of live neighbors of a cell
int countNeighbors(int **grid, int x, int y, int w, int h) {
  int count = 0;
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      int row = (x + i + h) % h;
      int col = (y + j + w) % w;
      count += grid[row][col];
    }
  }
  int current = grid[x][y];
  count -= current;
  return count;
}


// Function to simulate one iteration of the game of life
void simulateStep(int **grid, int w, int h) {
  int newGrid[h][w];

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      int neighbors = countNeighbors(grid, i, j, w, h);
      if (grid[i][j]) {
        if (neighbors < 2 || neighbors > 3) {
          newGrid[i][j] = 0;
        } else {
          newGrid[i][j] = 1;
        }
      } else {
        if (neighbors == 3) {
          newGrid[i][j] = 1;
        } else {
          newGrid[i][j] = 0;
        }
      }
    }
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      grid[i][j] = newGrid[i][j];
    }
  }
}


int main() {
  // Allocate memory for the grid
  int **grid = malloc(HEIGHT * sizeof(int *));
  for (int i = 0; i < HEIGHT; i++) {
    grid[i] = malloc(WIDTH * sizeof(int));
  }

  // Generate initial state of the grid
  initGrid(grid, WIDTH, HEIGHT);

  // Loop through simulation steps and print the state of the grid
  for (int i = 0; i < 100; i++) {
    printGrid(grid, WIDTH, HEIGHT);
    simulateStep(grid, WIDTH, HEIGHT);
    usleep(100000); // Sleep for 100 milliseconds between steps
  }

  // Free memory for the grid
  for (int i = 0; i < HEIGHT; i++) {
    free(grid[i]);
  }
  free(grid);

  return 0;
}