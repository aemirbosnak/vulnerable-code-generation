//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maze dimensions
#define MAZE_WIDTH 20
#define MAZE_HEIGHT 20

// Define the cell types
#define CELL_EMPTY 0
#define CELL_WALL 1
#define CELL_VISITED 2

// Create a maze structure
typedef struct maze {
  int width;
  int height;
  int cells[MAZE_WIDTH][MAZE_HEIGHT];
} maze;

// Create a stack structure
typedef struct stack {
  int top;
  int size;
  int *items;
} stack;

// Initialize the stack
void stack_init(stack *s, int size) {
  s->top = -1;
  s->size = size;
  s->items = (int *)malloc(sizeof(int) * size);
}

// Push an item onto the stack
void stack_push(stack *s, int item) {
  if (s->top == s->size - 1) {
    printf("Error: Stack overflow\n");
    return;
  }
  s->items[++s->top] = item;
}

// Pop an item from the stack
int stack_pop(stack *s) {
  if (s->top == -1) {
    printf("Error: Stack underflow\n");
    return -1;
  }
  return s->items[s->top--];
}

// Check if the stack is empty
int stack_empty(stack *s) {
  return s->top == -1;
}

// Create a maze
maze *maze_create(int width, int height) {
  maze *m = (maze *)malloc(sizeof(maze));
  m->width = width;
  m->height = height;

  // Initialize the cells to walls
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      m->cells[i][j] = CELL_WALL;
    }
  }

  return m;
}

// Destroy a maze
void maze_destroy(maze *m) {
  free(m);
}

// Print a maze
void maze_print(maze *m) {
  for (int i = 0; i < m->height; i++) {
    for (int j = 0; j < m->width; j++) {
      if (m->cells[i][j] == CELL_WALL) {
        printf("#");
      } else {
        printf(".");
      }
    }
    printf("\n");
  }
}

// Generate a maze using the recursive backtracker algorithm
void maze_generate(maze *m) {
  // Initialize the stack
  stack s;
  stack_init(&s, m->width * m->height);

  // Choose a starting cell
  int x = rand() % m->width;
  int y = rand() % m->height;

  // Push the starting cell onto the stack
  stack_push(&s, x * m->width + y);

  // While the stack is not empty
  while (!stack_empty(&s)) {
    // Pop the top cell from the stack
    int cell = stack_pop(&s);

    // Get the x and y coordinates of the cell
    int x = cell / m->width;
    int y = cell % m->width;

    // Mark the cell as visited
    m->cells[x][y] = CELL_VISITED;

    // Get a list of the neighboring cells
    int neighbors[4];
    neighbors[0] = (x - 1) * m->width + y;
    neighbors[1] = x * m->width + (y - 1);
    neighbors[2] = (x + 1) * m->width + y;
    neighbors[3] = x * m->width + (y + 1);

    // Shuffle the list of neighbors
    for (int i = 0; i < 4; i++) {
      int j = rand() % 4;
      int temp = neighbors[i];
      neighbors[i] = neighbors[j];
      neighbors[j] = temp;
    }

    // Try each neighbor
    for (int i = 0; i < 4; i++) {
      // Get the x and y coordinates of the neighbor
      int nx = neighbors[i] / m->width;
      int ny = neighbors[i] % m->width;

      // If the neighbor is not a wall and has not been visited
      if (m->cells[nx][ny] != CELL_WALL && m->cells[nx][ny] != CELL_VISITED) {
        // Push the neighbor onto the stack
        stack_push(&s, neighbors[i]);

        // Knock down the wall between the current cell and the neighbor
        if (x != nx) {
          m->cells[(x + nx) / 2][y] = CELL_EMPTY;
        } else {
          m->cells[x][(y + ny) / 2] = CELL_EMPTY;
        }
      }
    }
  }
}

// Solve a maze using the depth-first search algorithm
int maze_solve(maze *m, int x, int y) {
  // If the cell is a wall, return false
  if (m->cells[x][y] == CELL_WALL) {
    return 0;
  }

  // If the cell has been visited, return false
  if (m->cells[x][y] == CELL_VISITED) {
    return 0;
  }

  // Mark the cell as visited
  m->cells[x][y] = CELL_VISITED;

  // If the cell is the exit, return true
  if (x == m->width - 1 && y == m->height - 1) {
    return 1;
  }

  // Recursively search the cell's neighbors
  int found = 0;
  if (found = maze_solve(m, x + 1, y)) {
    return 1;
  } else if (found = maze_solve(m, x - 1, y)) {
    return 1;
  } else if (found = maze_solve(m, x, y + 1)) {
    return 1;
  } else if (found = maze_solve(m, x, y - 1)) {
    return 1;
  }

  // If the cell is not the exit and no neighbors have a solution, return false
  return 0;
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Create a maze
  maze *m = maze_create(MAZE_WIDTH, MAZE_HEIGHT);

  // Generate the maze
  maze_generate(m);

  // Print the maze
  maze_print(m);

  // Solve the maze
  int found = maze_solve(m, 0, 0);

  // Print the solution
  if (found) {
    printf("Solution found!\n");
  } else {
    printf("No solution found.\n");
  }

  // Destroy the maze
  maze_destroy(m);

  return 0;
}