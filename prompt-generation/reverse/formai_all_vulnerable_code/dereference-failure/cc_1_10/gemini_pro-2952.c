//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 10
#define WALL '#'
#define SPACE ' '

// Function to generate a maze
char** generateMaze() {
  // Initialize the maze
  char** maze = malloc(MAZE_SIZE * sizeof(char*));
  for (int i = 0; i < MAZE_SIZE; i++) {
    maze[i] = malloc(MAZE_SIZE * sizeof(char));
    for (int j = 0; j < MAZE_SIZE; j++) {
      maze[i][j] = WALL;
    }
  }

  // Create the entrance and exit
  maze[0][0] = SPACE;
  maze[MAZE_SIZE - 1][MAZE_SIZE - 1] = SPACE;

  // Generate the maze using a depth-first search
  int x = 0, y = 0;
  while (1) {
    // Check if we have reached the exit
    if (x == MAZE_SIZE - 1 && y == MAZE_SIZE - 1) {
      break;
    }

    // Get the possible directions we can move in
    int directions[] = {0, 1, 2, 3};
    int numDirections = 4;

    // Shuffle the directions
    for (int i = 0; i < numDirections; i++) {
      int r = rand() % numDirections;
      int tmp = directions[i];
      directions[i] = directions[r];
      directions[r] = tmp;
    }

    // Try to move in each direction
    for (int i = 0; i < numDirections; i++) {
      int dx = 0, dy = 0;
      switch (directions[i]) {
        case 0:
          dx = -1;
          break;
        case 1:
          dy = -1;
          break;
        case 2:
          dx = 1;
          break;
        case 3:
          dy = 1;
          break;
      }

      // Check if we can move in that direction
      if (x + dx >= 0 && x + dx < MAZE_SIZE && y + dy >= 0 && y + dy < MAZE_SIZE && maze[x + dx][y + dy] == WALL) {
        // Move in that direction
        maze[x + dx][y + dy] = SPACE;
        x += dx;
        y += dy;
        break;
      }
    }
  }

  return maze;
}

// Function to print the maze
void printMaze(char** maze) {
  for (int i = 0; i < MAZE_SIZE; i++) {
    for (int j = 0; j < MAZE_SIZE; j++) {
      printf("%c", maze[i][j]);
    }
    printf("\n");
  }
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Generate the maze
  char** maze = generateMaze();

  // Print the maze
  printMaze(maze);

  // Free the memory allocated for the maze
  for (int i = 0; i < MAZE_SIZE; i++) {
    free(maze[i]);
  }
  free(maze);

  return 0;
}