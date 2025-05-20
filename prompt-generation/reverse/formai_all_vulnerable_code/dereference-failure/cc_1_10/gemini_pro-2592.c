//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maze structure
typedef struct maze {
  int width;
  int height;
  char **map;
} maze;

// Create a new maze
maze *new_maze(int width, int height) {
  maze *m = malloc(sizeof(maze));
  m->width = width;
  m->height = height;
  m->map = malloc(sizeof(char *) * height);
  for (int i = 0; i < height; i++) {
    m->map[i] = malloc(sizeof(char) * width);
  }
  return m;
}

// Free the memory allocated for a maze
void free_maze(maze *m) {
  for (int i = 0; i < m->height; i++) {
    free(m->map[i]);
  }
  free(m->map);
  free(m);
}

// Print a maze to the console
void print_maze(maze *m) {
  for (int i = 0; i < m->height; i++) {
    for (int j = 0; j < m->width; j++) {
      printf("%c", m->map[i][j]);
    }
    printf("\n");
  }
}

// Check if a given cell is a valid move
int is_valid_move(maze *m, int x, int y) {
  return x >= 0 && x < m->width && y >= 0 && y < m->height && m->map[y][x] != '#';
}

// Find all possible moves from a given cell
int **find_moves(maze *m, int x, int y) {
  int **moves = malloc(sizeof(int *) * 4);
  for (int i = 0; i < 4; i++) {
    moves[i] = malloc(sizeof(int) * 2);
  }

  int count = 0;
  if (is_valid_move(m, x + 1, y)) {
    moves[count][0] = x + 1;
    moves[count][1] = y;
    count++;
  }
  if (is_valid_move(m, x - 1, y)) {
    moves[count][0] = x - 1;
    moves[count][1] = y;
    count++;
  }
  if (is_valid_move(m, x, y + 1)) {
    moves[count][0] = x;
    moves[count][1] = y + 1;
    count++;
  }
  if (is_valid_move(m, x, y - 1)) {
    moves[count][0] = x;
    moves[count][1] = y - 1;
    count++;
  }

  return moves;
}

// Find a path through a maze using a depth-first search
int **find_path(maze *m, int start_x, int start_y, int end_x, int end_y) {
  // Create a stack to store the path
  int **stack = malloc(sizeof(int *) * m->width * m->height);
  for (int i = 0; i < m->width * m->height; i++) {
    stack[i] = malloc(sizeof(int) * 2);
  }
  int top = 0;

  // Push the starting cell onto the stack
  stack[top][0] = start_x;
  stack[top][1] = start_y;
  top++;

  // While the stack is not empty
  while (top > 0) {
    // Pop the top cell from the stack
    int x = stack[top - 1][0];
    int y = stack[top - 1][1];
    top--;

    // If the current cell is the end cell, return the path
    if (x == end_x && y == end_y) {
      return stack;
    }

    // Find all possible moves from the current cell
    int **moves = find_moves(m, x, y);

    // For each possible move
    for (int i = 0; i < 4; i++) {
      // If the move is valid, push it onto the stack
      if (is_valid_move(m, moves[i][0], moves[i][1])) {
        stack[top][0] = moves[i][0];
        stack[top][1] = moves[i][1];
        top++;
      }
    }

    // Free the memory allocated for the moves
    for (int i = 0; i < 4; i++) {
      free(moves[i]);
    }
    free(moves);
  }

  // If the stack is empty, no path was found
  return NULL;
}

// Main function
int main() {
  // Create a new maze
  maze *m = new_maze(10, 10);

  // Set the maze map
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (i == 0 || i == 9 || j == 0 || j == 9) {
        m->map[i][j] = '#';
      } else {
        m->map[i][j] = ' ';
      }
    }
  }

  // Print the maze
  print_maze(m);

  // Find a path through the maze
  int **path = find_path(m, 1, 1, 8, 8);

  // If a path was found, print it
  if (path != NULL) {
    printf("Path found:\n");
    for (int i = 0; i < m->width * m->height; i++) {
      if (path[i][0] == -1 && path[i][1] == -1) {
        break;
      }
      printf("(%d, %d)\n", path[i][0], path[i][1]);
    }
  } else {
    printf("No path found.\n");
  }

  // Free the memory allocated for the path
  for (int i = 0; i < m->width * m->height; i++) {
    free(path[i]);
  }
  free(path);

  // Free the memory allocated for the maze
  free_maze(m);

  return 0;
}