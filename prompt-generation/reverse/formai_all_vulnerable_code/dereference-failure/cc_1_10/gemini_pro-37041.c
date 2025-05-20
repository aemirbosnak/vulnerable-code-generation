//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

// Define the maze structure
typedef struct {
  int width;
  int height;
  char **maze;
} Maze;

// Create a new maze
Maze *createMaze(int width, int height) {
  Maze *maze = malloc(sizeof(Maze));
  maze->width = width;
  maze->height = height;
  maze->maze = malloc(sizeof(char *) * height);
  for (int i = 0; i < height; i++) {
    maze->maze[i] = malloc(sizeof(char) * width);
  }
  return maze;
}

// Free the memory allocated for the maze
void freeMaze(Maze *maze) {
  for (int i = 0; i < maze->height; i++) {
    free(maze->maze[i]);
  }
  free(maze->maze);
  free(maze);
}

// Print the maze to the console
void printMaze(Maze *maze) {
  for (int i = 0; i < maze->height; i++) {
    for (int j = 0; j < maze->width; j++) {
      printf("%c", maze->maze[i][j]);
    }
    printf("\n");
  }
}

// Find the starting position of the maze
int findStartPosition(Maze *maze) {
  for (int i = 0; i < maze->height; i++) {
    for (int j = 0; j < maze->width; j++) {
      if (maze->maze[i][j] == 'S') {
        return i * maze->width + j;
      }
    }
  }
  return -1;
}

// Find the ending position of the maze
int findEndingPosition(Maze *maze) {
  for (int i = 0; i < maze->height; i++) {
    for (int j = 0; j < maze->width; j++) {
      if (maze->maze[i][j] == 'E') {
        return i * maze->width + j;
      }
    }
  }
  return -1;
}

// Check if a move is valid
int isValidMove(Maze *maze, int position, int direction) {
  int newPosition = position + direction;
  if (newPosition < 0 || newPosition >= maze->width * maze->height) {
    return 0;
  }
  int row = newPosition / maze->width;
  int col = newPosition % maze->width;
  if (maze->maze[row][col] == '#') {
    return 0;
  }
  return 1;
}

// Find the shortest path from the starting position to the ending position
int findShortestPath(Maze *maze) {
  int startPosition = findStartPosition(maze);
  int endingPosition = findEndingPosition(maze);
  if (startPosition == -1 || endingPosition == -1) {
    return -1;
  }
  int queue[maze->width * maze->height];
  int distances[maze->width * maze->height];
  for (int i = 0; i < maze->width * maze->height; i++) {
    queue[i] = -1;
    distances[i] = -1;
  }
  queue[0] = startPosition;
  distances[startPosition] = 0;
  int head = 0;
  int tail = 1;
  while (head < tail) {
    int position = queue[head];
    head++;
    if (position == endingPosition) {
      return distances[position];
    }
    // Check the four directions
    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        if (i == 0 && j == 0) {
          continue;
        }
        int direction = i * maze->width + j;
        if (isValidMove(maze, position, direction)) {
          int newPosition = position + direction;
          if (distances[newPosition] == -1) {
            queue[tail] = newPosition;
            tail++;
            distances[newPosition] = distances[position] + 1;
          }
        }
      }
    }
  }
  return -1;
}

// Main function
int main() {
  // Create a maze
  Maze *maze = createMaze(10, 10);
  maze->maze[0][0] = 'S';
  maze->maze[9][9] = 'E';
  for (int i = 0; i < 10; i++) {
    maze->maze[i][2] = '#';
    maze->maze[i][7] = '#';
  }
  for (int i = 2; i < 7; i++) {
    maze->maze[5][i] = '#';
  }

  // Print the maze
  printMaze(maze);

  // Find the shortest path from the starting position to the ending position
  int shortestPath = findShortestPath(maze);
  if (shortestPath == -1) {
    printf("No solution found.\n");
  } else {
    printf("The shortest path is %d moves long.\n", shortestPath);
  }

  // Free the memory allocated for the maze
  freeMaze(maze);

  return 0;
}