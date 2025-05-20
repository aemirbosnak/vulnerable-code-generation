//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define DEBUG
#define OPENMP

// Define the size of the maze
#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

// Define the possible directions
#define UP    0
#define RIGHT 1
#define DOWN  2
#define LEFT  3

// Define the cell states
#define UNVISITED 0
#define VISITED   1

// Define the maze structure
typedef struct {
  int width;
  int height;
  int cells[MAZE_WIDTH][MAZE_HEIGHT];
} maze_t;

// Function to create a new maze
maze_t *create_maze(int width, int height) {
  maze_t *maze = (maze_t *)malloc(sizeof(maze_t));
  if (maze == NULL) {
    return NULL;
  }

  maze->width = width;
  maze->height = height;

  // Initialize all cells to UNVISITED
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      maze->cells[i][j] = UNVISITED;
    }
  }

  return maze;
}

// Function to print a maze
void print_maze(maze_t *maze) {
  for (int i = 0; i < maze->width; i++) {
    for (int j = 0; j < maze->height; j++) {
      if (maze->cells[i][j] == UNVISITED) {
        printf("#");
      } else {
        printf(".");
      }
    }
    printf("\n");
  }
}

// Function to recursively generate a maze
void generate_maze(maze_t *maze, int x, int y) {
  // Mark the current cell as visited
  maze->cells[x][y] = VISITED;

  // Get a list of all unvisited neighbors
  int neighbors[4];
  int num_neighbors = 0;
  if (x > 0 && maze->cells[x - 1][y] == UNVISITED) {
    neighbors[num_neighbors++] = UP;
  }
  if (y < maze->height - 1 && maze->cells[x][y + 1] == UNVISITED) {
    neighbors[num_neighbors++] = RIGHT;
  }
  if (x < maze->width - 1 && maze->cells[x + 1][y] == UNVISITED) {
    neighbors[num_neighbors++] = DOWN;
  }
  if (y > 0 && maze->cells[x][y - 1] == UNVISITED) {
    neighbors[num_neighbors++] = LEFT;
  }

  // If there are no unvisited neighbors, return
  if (num_neighbors == 0) {
    return;
  }

  // Choose a random unvisited neighbor
  int next_direction = neighbors[rand() % num_neighbors];

  // Recursively generate the maze from the chosen neighbor
  switch (next_direction) {
    case UP:
      generate_maze(maze, x - 1, y);
      break;
    case RIGHT:
      generate_maze(maze, x, y + 1);
      break;
    case DOWN:
      generate_maze(maze, x + 1, y);
      break;
    case LEFT:
      generate_maze(maze, x, y - 1);
      break;
  }

  // Remove the wall between the current cell and the chosen neighbor
  switch (next_direction) {
    case UP:
      maze->cells[x][y] &= ~0x8;
      maze->cells[x - 1][y] &= ~0x2;
      break;
    case RIGHT:
      maze->cells[x][y] &= ~0x4;
      maze->cells[x][y + 1] &= ~0x1;
      break;
    case DOWN:
      maze->cells[x][y] &= ~0x2;
      maze->cells[x + 1][y] &= ~0x8;
      break;
    case LEFT:
      maze->cells[x][y] &= ~0x1;
      maze->cells[x][y - 1] &= ~0x4;
      break;
  }
}

int main(int argc, char **argv) {
  // Create a new maze
  maze_t *maze = create_maze(MAZE_WIDTH, MAZE_HEIGHT);

  // Seed the random number generator
  srand(time(NULL));

  // Recursively generate the maze
  generate_maze(maze, 0, 0);

  // Print the maze
  print_maze(maze);

  // Free the maze
  free(maze);
  return 0;
}