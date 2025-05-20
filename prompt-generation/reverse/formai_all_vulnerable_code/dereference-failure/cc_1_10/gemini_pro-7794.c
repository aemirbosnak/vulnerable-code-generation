//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maze dimensions
#define MAZE_WIDTH 20
#define MAZE_HEIGHT 20

// Define the directions
enum direction {
  NORTH,
  EAST,
  SOUTH,
  WEST
};

// Define the maze structure
struct maze {
  int width;
  int height;
  int **cells;
};

// Create a new maze
struct maze *create_maze(int width, int height) {
  // Allocate memory for the maze
  struct maze *maze = malloc(sizeof(struct maze));
  maze->width = width;
  maze->height = height;
  maze->cells = malloc(sizeof(int *) * height);
  for (int i = 0; i < height; i++) {
    maze->cells[i] = malloc(sizeof(int) * width);
  }

  // Initialize the maze cells to 0
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      maze->cells[i][j] = 0;
    }
  }

  // Return the maze
  return maze;
}

// Free the memory allocated for the maze
void free_maze(struct maze *maze) {
  for (int i = 0; i < maze->height; i++) {
    free(maze->cells[i]);
  }
  free(maze->cells);
  free(maze);
}

// Print the maze to the console
void print_maze(struct maze *maze) {
  for (int i = 0; i < maze->height; i++) {
    for (int j = 0; j < maze->width; j++) {
      if (maze->cells[i][j] == 0) {
        printf(" ");
      } else {
        printf("#");
      }
    }
    printf("\n");
  }
}

// Generate a random direction
enum direction get_random_direction() {
  return rand() % 4;
}

// Check if a cell is valid
int is_valid_cell(struct maze *maze, int x, int y) {
  return x >= 0 && x < maze->width && y >= 0 && y < maze->height && maze->cells[y][x] == 0;
}

// Carve a path through the maze
void carve_path(struct maze *maze, int x, int y) {
  // Mark the current cell as visited
  maze->cells[y][x] = 1;

  // Get a random direction
  enum direction direction = get_random_direction();

  // While there are still unvisited cells in the current direction
  while (1) {
    // Get the next cell in the current direction
    int next_x = x;
    int next_y = y;
    switch (direction) {
      case NORTH:
        next_y--;
        break;
      case EAST:
        next_x++;
        break;
      case SOUTH:
        next_y++;
        break;
      case WEST:
        next_x--;
        break;
    }

    // If the next cell is valid, carve a path through it
    if (is_valid_cell(maze, next_x, next_y)) {
      carve_path(maze, next_x, next_y);
    } else {
      // If the next cell is not valid, try a different direction
      direction = get_random_direction();
    }
  }
}

// Generate a maze
struct maze *generate_maze() {
  // Create a new maze
  struct maze *maze = create_maze(MAZE_WIDTH, MAZE_HEIGHT);

  // Carve a path through the maze
  carve_path(maze, 0, 0);

  // Return the maze
  return maze;
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate a maze
  struct maze *maze = generate_maze();

  // Print the maze to the console
  print_maze(maze);

  // Free the memory allocated for the maze
  free_maze(maze);

  return 0;
}