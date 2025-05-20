//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

// Directions
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

// Cell states
#define UNVISITED 0
#define VISITED 1
#define WALL 2

// Maze data structure
struct maze {
  int width;
  int height;
  int **cells;
};

// Create a new maze
struct maze *create_maze(int width, int height) {
  struct maze *maze = malloc(sizeof(struct maze));
  maze->width = width;
  maze->height = height;

  // Allocate memory for the cells
  maze->cells = malloc(sizeof(int *) * height);
  for (int i = 0; i < height; i++) {
    maze->cells[i] = malloc(sizeof(int) * width);
  }

  // Initialize all cells to unvisited
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      maze->cells[i][j] = UNVISITED;
    }
  }

  return maze;
}

// Free the memory allocated for the maze
void destroy_maze(struct maze *maze) {
  // Free the memory allocated for the cells
  for (int i = 0; i < maze->height; i++) {
    free(maze->cells[i]);
  }

  // Free the memory allocated for the maze
  free(maze);
}

// Print the maze to the console
void print_maze(struct maze *maze) {
  printf("+");
  for (int i = 0; i < maze->width; i++) {
    printf("--+");
  }
  printf("\n");

  for (int i = 0; i < maze->height; i++) {
    printf("|");
    for (int j = 0; j < maze->width; j++) {
      if (maze->cells[i][j] == WALL) {
        printf("##");
      } else {
        printf("  ");
      }
    }
    printf("|\n");

    printf("+");
    for (int i = 0; i < maze->width; i++) {
      printf("--+");
    }
    printf("\n");
  }
}

// Generate a random direction
int get_random_direction() {
  return rand() % 4;
}

// Visit a cell in the maze
void visit_cell(struct maze *maze, int x, int y) {
  maze->cells[y][x] = VISITED;

  // Get a random direction
  int direction = get_random_direction();

  // Recursively visit the next cell in the given direction
  switch (direction) {
    case NORTH:
      if (y > 0 && maze->cells[y - 1][x] == UNVISITED) {
        visit_cell(maze, x, y - 1);
      }
      break;
    case EAST:
      if (x < maze->width - 1 && maze->cells[y][x + 1] == UNVISITED) {
        visit_cell(maze, x + 1, y);
      }
      break;
    case SOUTH:
      if (y < maze->height - 1 && maze->cells[y + 1][x] == UNVISITED) {
        visit_cell(maze, x, y + 1);
      }
      break;
    case WEST:
      if (x > 0 && maze->cells[y][x - 1] == UNVISITED) {
        visit_cell(maze, x - 1, y);
      }
      break;
  }
}

// Generate a maze using the recursive backtracking algorithm
struct maze *generate_maze(int width, int height) {
  // Create a new maze
  struct maze *maze = create_maze(width, height);

  // Set the starting cell to visited
  maze->cells[0][0] = VISITED;

  // Visit the starting cell
  visit_cell(maze, 0, 0);

  return maze;
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate a maze
  struct maze *maze = generate_maze(WIDTH, HEIGHT);

  // Print the maze to the console
  print_maze(maze);

  // Free the memory allocated for the maze
  destroy_maze(maze);

  return 0;
}