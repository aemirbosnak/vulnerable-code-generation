//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a cell in the maze
typedef struct {
  int row;
  int col;
} Cell;

// Structure to represent a stack of cells
typedef struct {
  Cell cells[100];
  int top;
} Stack;

// Function to create a new maze of size (m x n)
int** create_maze(int m, int n) {
  int **maze = malloc(sizeof(int *) * m);
  for (int i = 0; i < m; i++) {
    maze[i] = malloc(sizeof(int) * n);
    for (int j = 0; j < n; j++) {
      maze[i][j] = 0;  // 0 represents an open cell, 1 represents a wall
    }
  }
  return maze;
}

// Function to print the maze
void print_maze(int **maze, int m, int n) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", maze[i][j]);
    }
    printf("\n");
  }
}

// Function to check if a cell is valid
bool is_valid_cell(int **maze, Cell cell, int m, int n) {
  return (cell.row >= 0 && cell.row < m) && (cell.col >= 0 && cell.col < n) && (maze[cell.row][cell.col] == 0);
}

// Function to push a cell onto the stack
void push(Stack *stack, Cell cell) {
  stack->cells[++stack->top] = cell;
}

// Function to pop a cell from the stack
Cell pop(Stack *stack) {
  return stack->cells[stack->top--];
}

// Function to find a path through the maze using a stack
bool find_path(int **maze, int m, int n, Cell start, Cell end) {
  Stack stack;
  stack.top = -1;
  push(&stack, start);
  while (stack.top >= 0) {
    Cell current = pop(&stack);
    if (current.row == end.row && current.col == end.col) {  // Reached the end of the maze
      return true;
    }
    if (is_valid_cell(maze, current, m, n)) {
      maze[current.row][current.col] = 1;  // Mark the cell as visited
      Cell neighbors[4] = {{current.row - 1, current.col},
                           {current.row + 1, current.col},
                           {current.row, current.col - 1},
                           {current.row, current.col + 1}};
      for (int i = 0; i < 4; i++) {  // Check all four neighbors
        push(&stack, neighbors[i]);
      }
    }
  }
  return false;  // No path was found
}

int main() {
  int m, n;
  printf("Enter the dimensions of the maze (m x n): ");
  scanf("%d %d", &m, &n);

  int **maze = create_maze(m, n);

  Cell start, end;
  printf("Enter the starting cell (row, col): ");
  scanf("%d %d", &start.row, &start.col);
  printf("Enter the ending cell (row, col): ");
  scanf("%d %d", &end.row, &end.col);

  if (find_path(maze, m, n, start, end)) {
    printf("A path was found!\n");
  } else {
    printf("No path was found!\n");
  }

  print_maze(maze, m, n);  // Print the maze

  return 0;
}