//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Grid dimensions
#define WIDTH 20
#define HEIGHT 10

// Cell types
#define WALL '#'
#define FLOOR '.'

// Player character
#define PLAYER '@'

// Function to generate a random number between min and max
int rand_range(int min, int max) {
  return min + (rand() % (max - min + 1));
}

// Function to create a new grid
char** create_grid(int width, int height) {
  char** grid = (char**)malloc(sizeof(char*) * height);
  for (int i = 0; i < height; i++) {
    grid[i] = (char*)malloc(sizeof(char) * width);
  }
  return grid;
}

// Function to free the grid
void free_grid(char** grid, int height) {
  for (int i = 0; i < height; i++) {
    free(grid[i]);
  }
  free(grid);
}

// Function to initialize the grid with walls
void init_grid(char** grid, int width, int height) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      grid[i][j] = WALL;
    }
  }
}

// Function to generate a maze using a recursive backtracker algorithm
void generate_maze(char** grid, int width, int height) {
  // Create a stack to store the cells that have been visited
  int stack_size = width * height;
  int* stack = (int*)malloc(sizeof(int) * stack_size);
  int top = -1;

  // Initialize the grid with walls
  init_grid(grid, width, height);

  // Set the starting position of the player
  int player_x = 0;
  int player_y = 0;
  grid[player_y][player_x] = PLAYER;

  // Push the starting position onto the stack
  stack[++top] = player_x + (player_y * width);

  // While there are still cells to visit
  while (top >= 0) {
    // Pop the top of the stack
    int cell = stack[top--];
    int x = cell % width;
    int y = cell / width;

    // If the cell is a wall, make it a floor
    if (grid[y][x] == WALL) {
      grid[y][x] = FLOOR;

      // Get a list of the neighboring cells
      int neighbors[4];
      neighbors[0] = x - 1 + (y * width);
      neighbors[1] = x + 1 + (y * width);
      neighbors[2] = x + (y - 1) * width;
      neighbors[3] = x + (y + 1) * width;

      // Shuffle the neighbors
      for (int i = 0; i < 4; i++) {
        int j = rand_range(i, 3);
        int temp = neighbors[i];
        neighbors[i] = neighbors[j];
        neighbors[j] = temp;
      }

      // Push the neighboring cells onto the stack
      for (int i = 0; i < 4; i++) {
        if (grid[neighbors[i] / width][neighbors[i] % width] == WALL) {
          stack[++top] = neighbors[i];
        }
      }
    }
  }

  // Free the stack
  free(stack);
}

// Function to print the grid
void print_grid(char** grid, int width, int height) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      printf("%c", grid[i][j]);
    }
    printf("\n");
  }
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Create a new grid
  char** grid = create_grid(WIDTH, HEIGHT);

  // Generate a maze
  generate_maze(grid, WIDTH, HEIGHT);

  // Print the grid
  print_grid(grid, WIDTH, HEIGHT);

  // Free the grid
  free_grid(grid, HEIGHT);

  return 0;
}