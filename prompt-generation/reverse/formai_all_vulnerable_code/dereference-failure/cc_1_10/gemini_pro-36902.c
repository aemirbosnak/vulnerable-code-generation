//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Define the maze dimensions and start and end coordinates
#define WIDTH 10
#define HEIGHT 10
#define START_X 0
#define START_Y 0
#define END_X 9
#define END_Y 9

// Define the maze cells
typedef enum {
  EMPTY,
  WALL
} cell_t;

// Define the direction of movement
typedef enum {
  UP,
  DOWN,
  LEFT,
  RIGHT
} direction_t;

// Define the maze structure
typedef struct {
  cell_t cells[WIDTH][HEIGHT];
  int start_x;
  int start_y;
  int end_x;
  int end_y;
} maze_t;

// Create a new maze
maze_t* create_maze() {
  maze_t* maze = malloc(sizeof(maze_t));

  // Initialize the cells to empty
  for (int i = 0; i < WIDTH; i++) {
    for (int j = 0; j < HEIGHT; j++) {
      maze->cells[i][j] = EMPTY;
    }
  }

  // Set the start and end coordinates
  maze->start_x = START_X;
  maze->start_y = START_Y;
  maze->end_x = END_X;
  maze->end_y = END_Y;

  return maze;
}

// Print the maze
void print_maze(maze_t* maze) {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      if (maze->cells[j][i] == EMPTY) {
        printf(" ");
      } else {
        printf("#");
      }
    }
    printf("\n");
  }
}

// Find the path through the maze
int find_path(maze_t* maze, int x, int y, direction_t direction) {
  // Check if we have reached the end of the maze
  if (x == maze->end_x && y == maze->end_y) {
    return 1;
  }

  // Check if we have hit a wall
  if (maze->cells[x][y] == WALL) {
    return 0;
  }

  // Try all possible directions
  for (int i = 0; i < 4; i++) {
    int new_x = x;
    int new_y = y;

    switch (direction) {
      case UP:
        new_y--;
        break;
      case DOWN:
        new_y++;
        break;
      case LEFT:
        new_x--;
        break;
      case RIGHT:
        new_x++;
        break;
    }

    // Check if the new direction is valid
    if (new_x >= 0 && new_x < WIDTH && new_y >= 0 && new_y < HEIGHT) {
      // Try the new direction
      if (find_path(maze, new_x, new_y, direction)) {
        return 1;
      }
    }
  }

  // No path found
  return 0;
}

// Main function
int main() {
  // Create a new maze
  maze_t* maze = create_maze();

  // Print the maze
  print_maze(maze);

  // Find the path through the maze
  int found = find_path(maze, maze->start_x, maze->start_y, UP);

  // Print the result
  if (found) {
    printf("Path found!\n");
  } else {
    printf("No path found.\n");
  }

  // Free the maze
  free(maze);

  return 0;
}