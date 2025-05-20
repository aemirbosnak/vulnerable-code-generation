//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the maze
#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

// Define the possible directions
enum direction {
  NORTH,
  EAST,
  SOUTH,
  WEST
};

// Define the structure of a cell
struct cell {
  int x;
  int y;
  enum direction visited;
};

// Define the structure of the maze
struct maze {
  struct cell cells[MAZE_WIDTH][MAZE_HEIGHT];
};

// Create a new maze
struct maze *create_maze() {
  struct maze *maze = malloc(sizeof(struct maze));
  for (int i = 0; i < MAZE_WIDTH; i++) {
    for (int j = 0; j < MAZE_HEIGHT; j++) {
      maze->cells[i][j].x = i;
      maze->cells[i][j].y = j;
      maze->cells[i][j].visited = 0;
    }
  }
  return maze;
}

// Free the memory allocated for the maze
void free_maze(struct maze *maze) {
  free(maze);
}

// Print the maze to the console
void print_maze(struct maze *maze) {
  for (int i = 0; i < MAZE_WIDTH; i++) {
    for (int j = 0; j < MAZE_HEIGHT; j++) {
      if (maze->cells[i][j].visited == 0) {
        printf("#");
      } else {
        printf(".");
      }
    }
    printf("\n");
  }
}

// Generate a random direction
enum direction random_direction() {
  return rand() % 4;
}

// Check if a cell is valid
int is_valid_cell(struct maze *maze, int x, int y) {
  return x >= 0 && x < MAZE_WIDTH && y >= 0 && y < MAZE_HEIGHT && maze->cells[x][y].visited == 0;
}

// Visit a cell
void visit_cell(struct maze *maze, int x, int y) {
  maze->cells[x][y].visited = 1;
}

// Generate a maze using the recursive backtracker algorithm
void generate_maze(struct maze *maze) {
  // Start at a random cell
  int x = rand() % MAZE_WIDTH;
  int y = rand() % MAZE_HEIGHT;

  // Visit the cell
  visit_cell(maze, x, y);

  // While there are still unvisited cells
  while (1) {
    // Get a list of valid directions
    enum direction directions[4];
    int num_directions = 0;
    if (is_valid_cell(maze, x + 1, y)) {
      directions[num_directions++] = EAST;
    }
    if (is_valid_cell(maze, x - 1, y)) {
      directions[num_directions++] = WEST;
    }
    if (is_valid_cell(maze, x, y + 1)) {
      directions[num_directions++] = SOUTH;
    }
    if (is_valid_cell(maze, x, y - 1)) {
      directions[num_directions++] = NORTH;
    }

    // If there are no valid directions, backtrack
    if (num_directions == 0) {
      break;
    }

    // Choose a random direction
    enum direction direction = directions[rand() % num_directions];

    // Move in the chosen direction
    switch (direction) {
    case EAST:
      x++;
      break;
    case WEST:
      x--;
      break;
    case SOUTH:
      y++;
      break;
    case NORTH:
      y--;
      break;
    }

    // Visit the cell
    visit_cell(maze, x, y);
  }
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Create a new maze
  struct maze *maze = create_maze();

  // Generate the maze
  generate_maze(maze);

  // Print the maze to the console
  print_maze(maze);

  // Free the memory allocated for the maze
  free_maze(maze);

  return 0;
}