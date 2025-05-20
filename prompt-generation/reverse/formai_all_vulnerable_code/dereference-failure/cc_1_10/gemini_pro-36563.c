//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the maze
#define MAZE_SIZE 10

// Define the directions
enum direction {
  NORTH,
  EAST,
  SOUTH,
  WEST
};

// Define the cell structure
struct cell {
  int x;
  int y;
  int walls[4]; // 0: north, 1: east, 2: south, 3: west
};

// Create a new cell
struct cell *new_cell(int x, int y) {
  struct cell *cell = malloc(sizeof(struct cell));
  cell->x = x;
  cell->y = y;
  for (int i = 0; i < 4; i++) {
    cell->walls[i] = 1;
  }
  return cell;
}

// Print the maze
void print_maze(struct cell *maze[MAZE_SIZE][MAZE_SIZE]) {
  for (int i = 0; i < MAZE_SIZE; i++) {
    for (int j = 0; j < MAZE_SIZE; j++) {
      struct cell *cell = maze[i][j];
      printf("+");
      if (cell->walls[NORTH]) {
        printf("-");
      } else {
        printf(" ");
      }
      if (cell->walls[EAST]) {
        printf("|");
      } else {
        printf(" ");
      }
    }
    printf("+\n");
    for (int j = 0; j < MAZE_SIZE; j++) {
      struct cell *cell = maze[i][j];
      if (cell->walls[SOUTH]) {
        printf("+");
      } else {
        printf(" ");
      }
      if (cell->walls[WEST]) {
        printf("|");
      } else {
        printf(" ");
      }
    }
    printf("+\n");
  }
}

// Generate a maze
void generate_maze(struct cell *maze[MAZE_SIZE][MAZE_SIZE]) {
  // Initialize the maze
  for (int i = 0; i < MAZE_SIZE; i++) {
    for (int j = 0; j < MAZE_SIZE; j++) {
      maze[i][j] = new_cell(i, j);
    }
  }

  // Set the current cell
  struct cell *current_cell = maze[0][0];

  // While there are still unvisited cells
  while (1) {
    // Get a random direction
    int direction = rand() % 4;

    // If the direction is valid
    if (direction >= 0 && direction < 4) {
      // Get the next cell in that direction
      struct cell *next_cell = NULL;
      switch (direction) {
        case NORTH:
          if (current_cell->y > 0) {
            next_cell = maze[current_cell->y - 1][current_cell->x];
          }
          break;
        case EAST:
          if (current_cell->x < MAZE_SIZE - 1) {
            next_cell = maze[current_cell->y][current_cell->x + 1];
          }
          break;
        case SOUTH:
          if (current_cell->y < MAZE_SIZE - 1) {
            next_cell = maze[current_cell->y + 1][current_cell->x];
          }
          break;
        case WEST:
          if (current_cell->x > 0) {
            next_cell = maze[current_cell->y][current_cell->x - 1];
          }
          break;
      }

      // If the next cell is valid
      if (next_cell) {
        // Remove the wall between the current cell and the next cell
        current_cell->walls[direction] = 0;
        next_cell->walls[(direction + 2) % 4] = 0;

        // Set the current cell to the next cell
        current_cell = next_cell;
      }
    }

    // Check if all cells have been visited
    int all_visited = 1;
    for (int i = 0; i < MAZE_SIZE; i++) {
      for (int j = 0; j < MAZE_SIZE; j++) {
        if (maze[i][j]->walls[NORTH] || maze[i][j]->walls[EAST] || maze[i][j]->walls[SOUTH] || maze[i][j]->walls[WEST]) {
          all_visited = 0;
          break;
        }
      }
    }

    // If all cells have been visited, break out of the loop
    if (all_visited) {
      break;
    }
  }
}

// Free the maze
void free_maze(struct cell *maze[MAZE_SIZE][MAZE_SIZE]) {
  for (int i = 0; i < MAZE_SIZE; i++) {
    for (int j = 0; j < MAZE_SIZE; j++) {
      free(maze[i][j]);
    }
  }
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Generate the maze
  struct cell *maze[MAZE_SIZE][MAZE_SIZE];
  generate_maze(maze);

  // Print the maze
  print_maze(maze);

  // Free the maze
  free_maze(maze);

  return 0;
}