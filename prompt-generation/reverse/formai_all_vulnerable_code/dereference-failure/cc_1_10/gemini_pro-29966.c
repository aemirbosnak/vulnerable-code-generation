//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

// Define the directions we can move in the maze
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

// Define the data structure for a maze cell
typedef struct {
  int x;
  int y;
  int visited;
  int direction;
} Cell;

// Define the data structure for a stack of cells
typedef struct {
  Cell *cells;
  int top;
  int size;
} Stack;

// Create a new maze
Cell **create_maze() {
  // Allocate memory for the maze
  Cell **maze = malloc(sizeof(Cell *) * MAZE_HEIGHT);
  for (int i = 0; i < MAZE_HEIGHT; i++) {
    maze[i] = malloc(sizeof(Cell) * MAZE_WIDTH);
  }

  // Initialize the maze cells
  for (int i = 0; i < MAZE_HEIGHT; i++) {
    for (int j = 0; j < MAZE_WIDTH; j++) {
      maze[i][j].x = j;
      maze[i][j].y = i;
      maze[i][j].visited = 0;
      maze[i][j].direction = -1;
    }
  }

  // Return the maze
  return maze;
}

// Destroy a maze
void destroy_maze(Cell **maze) {
  // Free the memory allocated for the maze
  for (int i = 0; i < MAZE_HEIGHT; i++) {
    free(maze[i]);
  }
  free(maze);
}

// Print a maze
void print_maze(Cell **maze) {
  // Print the top border of the maze
  printf("+");
  for (int i = 0; i < MAZE_WIDTH; i++) {
    printf("--+");
  }
  printf("\n");

  // Print the maze cells
  for (int i = 0; i < MAZE_HEIGHT; i++) {
    printf("|");
    for (int j = 0; j < MAZE_WIDTH; j++) {
      if (maze[i][j].visited) {
        printf("  ");
      } else {
        printf("##");
      }
    }
    printf("|\n");
  }

  // Print the bottom border of the maze
  printf("+");
  for (int i = 0; i < MAZE_WIDTH; i++) {
    printf("--+");
  }
  printf("\n");
}

// Find a path through a maze using a stack
Cell *find_path_through_maze(Cell **maze) {
  // Create a stack to store the cells we have visited
  Stack stack;
  stack.cells = malloc(sizeof(Cell) * MAZE_HEIGHT * MAZE_WIDTH);
  stack.top = -1;
  stack.size = MAZE_HEIGHT * MAZE_WIDTH;

  // Push the starting cell onto the stack
  stack.cells[++stack.top] = maze[0][0];

  // Mark the starting cell as visited
  maze[0][0].visited = 1;

  // While the stack is not empty
  while (stack.top >= 0) {
    // Pop the top cell from the stack
    Cell cell = stack.cells[stack.top--];

    // If the cell is the exit cell
    if (cell.x == MAZE_WIDTH - 1 && cell.y == MAZE_HEIGHT - 1) {
      // Return the stack of cells as the path through the maze
      return stack.cells;
    }

    // If the cell has not been visited
    if (!cell.visited) {
      // Mark the cell as visited
      maze[cell.y][cell.x].visited = 1;

      // Push the cell's neighbors onto the stack
      if (cell.x > 0 && !maze[cell.y][cell.x - 1].visited) {
        stack.cells[++stack.top] = maze[cell.y][cell.x - 1];
      }
      if (cell.y > 0 && !maze[cell.y - 1][cell.x].visited) {
        stack.cells[++stack.top] = maze[cell.y - 1][cell.x];
      }
      if (cell.x < MAZE_WIDTH - 1 && !maze[cell.y][cell.x + 1].visited) {
        stack.cells[++stack.top] = maze[cell.y][cell.x + 1];
      }
      if (cell.y < MAZE_HEIGHT - 1 && !maze[cell.y + 1][cell.x].visited) {
        stack.cells[++stack.top] = maze[cell.y + 1][cell.x];
      }
    }
  }

  // Return NULL if no path was found
  return NULL;
}

// Main function
int main() {
  // Create a maze
  Cell **maze = create_maze();

  // Print the maze
  print_maze(maze);

  // Find a path through the maze
  Cell *path = find_path_through_maze(maze);

  // Print the path
  if (path == NULL) {
    printf("No path found.\n");
  } else {
    printf("Path found:\n");
    for (int i = 0; i <= path; i++) {
      printf("(%d, %d)\n", path[i].x, path[i].y);
    }
  }

  // Destroy the maze
  destroy_maze(maze);

  // Return 0
  return 0;
}