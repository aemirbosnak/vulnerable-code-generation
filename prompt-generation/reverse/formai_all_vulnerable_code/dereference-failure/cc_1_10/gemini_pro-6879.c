//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define WIDTH 21
#define HEIGHT 21

// Types
typedef struct {
  int x;
  int y;
} Point;

typedef struct {
  Point **grid;
} Maze;

// Functions
Maze *create_maze() {
  // Allocate memory for the maze
  Maze *maze = malloc(sizeof(Maze));
  maze->grid = malloc(HEIGHT * sizeof(Point *));
  for (int i = 0; i < HEIGHT; i++) {
    maze->grid[i] = malloc(WIDTH * sizeof(Point));
  }

  // Initialize the maze
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      maze->grid[i][j].x = j;
      maze->grid[i][j].y = i;
    }
  }

  // Return the maze
  return maze;
}

void free_maze(Maze *maze) {
  // Free the memory for the maze
  for (int i = 0; i < HEIGHT; i++) {
    free(maze->grid[i]);
  }
  free(maze->grid);
  free(maze);
}

void print_maze(Maze *maze) {
  // Print the maze
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      Point *point = &maze->grid[i][j];
      if (point->x == 0 || point->y == 0 || point->x == WIDTH - 1 || point->y == HEIGHT - 1) {
        printf("#");
      } else {
        printf(".");
      }
    }
    printf("\n");
  }
}

int main() {
  // Create a maze
  Maze *maze = create_maze();

  // Print the maze
  print_maze(maze);

  // Free the maze
  free_maze(maze);

  return 0;
}