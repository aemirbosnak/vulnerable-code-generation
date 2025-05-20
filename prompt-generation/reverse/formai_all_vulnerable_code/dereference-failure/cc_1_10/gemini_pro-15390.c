//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 10
#define MAX_STEPS 10000

typedef struct {
  int x;
  int y;
} position;

typedef struct {
  char** grid;
  position start;
  position end;
} maze;

// Function to create a new maze
maze* create_maze() {
  maze* m = (maze*)malloc(sizeof(maze));
  m->grid = (char**)malloc(MAZE_SIZE * sizeof(char*));
  for (int i = 0; i < MAZE_SIZE; i++) {
    m->grid[i] = (char*)malloc(MAZE_SIZE * sizeof(char));
  }

  // Initialize the grid with walls
  for (int i = 0; i < MAZE_SIZE; i++) {
    for (int j = 0; j < MAZE_SIZE; j++) {
      m->grid[i][j] = '*';
    }
  }

  // Set the start and end positions
  m->start.x = 0;
  m->start.y = 0;
  m->end.x = MAZE_SIZE - 1;
  m->end.y = MAZE_SIZE - 1;

  return m;
}

// Function to print the maze
void print_maze(maze* m) {
  for (int i = 0; i < MAZE_SIZE; i++) {
    for (int j = 0; j < MAZE_SIZE; j++) {
      printf("%c", m->grid[i][j]);
    }
    printf("\n");
  }
}

// Function to solve the maze
int solve_maze(maze* m, position current, int steps) {
  // Check if the current position is the end position
  if (current.x == m->end.x && current.y == m->end.y) {
    return steps;
  }

  // Check if the current position is a valid move
  if (current.x < 0 || current.x >= MAZE_SIZE || current.y < 0 || current.y >= MAZE_SIZE || m->grid[current.x][current.y] == '*') {
    return -1;
  }

  // Mark the current position as visited
  m->grid[current.x][current.y] = '.';

  // Try all possible moves
  int min_steps = -1;
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (i == 0 && j == 0) {
        continue;
      }

      position next = {current.x + i, current.y + j};
      int steps_taken = solve_maze(m, next, steps + 1);
      if (steps_taken != -1 && (min_steps == -1 || steps_taken < min_steps)) {
        min_steps = steps_taken;
      }
    }
  }

  // If no valid moves were found, backtrack
  if (min_steps == -1) {
    m->grid[current.x][current.y] = '*';
  }

  return min_steps;
}

int main() {
  // Create a new maze
  maze* m = create_maze();

  // Print the maze
  print_maze(m);

  // Solve the maze
  int steps = solve_maze(m, m->start, 0);

  // Print the number of steps taken to solve the maze
  if (steps == -1) {
    printf("No solution found\n");
  } else {
    printf("Solution found in %d steps\n", steps);
  }

  // Free the memory allocated for the maze
  for (int i = 0; i < MAZE_SIZE; i++) {
    free(m->grid[i]);
  }
  free(m->grid);
  free(m);

  return 0;
}