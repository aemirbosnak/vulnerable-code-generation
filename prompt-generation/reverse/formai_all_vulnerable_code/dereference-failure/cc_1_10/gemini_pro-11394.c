//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

// Function to generate a random number between 0 and 1
double rand01() {
  return (double)rand() / RAND_MAX;
}

// Function to generate a random integer between 0 and n-1
int randInt(int n) {
  return rand() % n;
}

// Function to create a new maze with the given width and height
char** createMaze(int width, int height) {
  // Allocate memory for the maze
  char** maze = (char**)malloc(height * sizeof(char*));
  for (int i = 0; i < height; i++) {
    maze[i] = (char*)malloc(width * sizeof(char));
  }

  // Initialize the maze to all walls
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      maze[i][j] = '#';
    }
  }

  // Create the maze using a depth-first search
  int stack[width * height];
  int top = 0;

  // Start at the top-left corner of the maze
  int x = 0;
  int y = 0;

  // While there are still cells to visit
  while (top > 0 || x != width - 1 || y != height - 1) {
    // If the current cell has any unvisited neighbors
    if (rand01() < 0.5 || (x == 0 && y == 0) || (x == width - 1 && y == height - 1)) {
      // Choose a random unvisited neighbor
      int neighbors[4];
      int numNeighbors = 0;
      if (x > 0 && maze[y][x - 1] == '#') {
        neighbors[numNeighbors++] = -1;
      }
      if (y > 0 && maze[y - 1][x] == '#') {
        neighbors[numNeighbors++] = -2;
      }
      if (x < width - 1 && maze[y][x + 1] == '#') {
        neighbors[numNeighbors++] = 1;
      }
      if (y < height - 1 && maze[y + 1][x] == '#') {
        neighbors[numNeighbors++] = 2;
      }
      int neighbor = neighbors[randInt(numNeighbors)];

      // Add the current cell to the stack
      stack[top++] = x;
      stack[top++] = y;

      // Move to the chosen neighbor
      if (neighbor == -1) {
        x--;
      } else if (neighbor == -2) {
        y--;
      } else if (neighbor == 1) {
        x++;
      } else if (neighbor == 2) {
        y++;
      }

      // Mark the current cell as visited
      maze[y][x] = '.';
    } else {
      // Backtrack to the previous cell
      top -= 2;
      if (top >= 0) {
        x = stack[top];
        y = stack[top - 1];
      }
    }
  }

  // Return the maze
  return maze;
}

// Function to print a maze
void printMaze(char** maze, int width, int height) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      printf("%c", maze[i][j]);
    }
    printf("\n");
  }
}

// Function to free the memory allocated for a maze
void freeMaze(char** maze, int width, int height) {
  for (int i = 0; i < height; i++) {
    free(maze[i]);
  }
  free(maze);
}

// Main function
int main() {
  // Seed the random number generator
  srand((unsigned int)time(NULL));

  // Create a new maze
  char** maze = createMaze(MAZE_WIDTH, MAZE_HEIGHT);

  // Print the maze
  printMaze(maze, MAZE_WIDTH, MAZE_HEIGHT);

  // Free the memory allocated for the maze
  freeMaze(maze, MAZE_WIDTH, MAZE_HEIGHT);

  return 0;
}