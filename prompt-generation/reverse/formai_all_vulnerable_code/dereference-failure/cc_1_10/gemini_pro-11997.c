//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Initialize the random number generator
void init_rand() {
  srand(time(NULL));
}

// Generate a random integer between min and max
int random_int(int min, int max) {
  return min + (rand() % (max - min + 1));
}

// Create a new maze with the given width and height
int** create_maze(int width, int height) {
  // Allocate memory for the maze
  int** maze = malloc(sizeof(int*) * height);
  for (int i = 0; i < height; i++) {
    maze[i] = malloc(sizeof(int) * width);
  }

  // Initialize the maze to all walls
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      maze[i][j] = 1;
    }
  }

  // Carve out a path through the maze
  int current_x = 0;
  int current_y = 0;
  int directions[] = {0, 1, 2, 3}; // North, East, South, West

  while (current_x != width - 1 || current_y != height - 1) {
    // Shuffle the directions array to choose a random direction
    for (int i = 0; i < 4; i++) {
      int j = random_int(0, 3);
      int temp = directions[i];
      directions[i] = directions[j];
      directions[j] = temp;
    }

    // Try each direction in the shuffled order
    for (int i = 0; i < 4; i++) {
      int next_x = current_x;
      int next_y = current_y;

      // Move in the chosen direction
      switch (directions[i]) {
        case 0:
          next_y--;
          break;
        case 1:
          next_x++;
          break;
        case 2:
          next_y++;
          break;
        case 3:
          next_x--;
          break;
      }

      // Check if the move is valid
      if (next_x >= 0 && next_x < width && next_y >= 0 && next_y < height && maze[next_y][next_x] == 1) {
        // Move in the chosen direction and mark the path
        maze[current_y][current_x] = 0;
        maze[next_y][next_x] = 0;
        current_x = next_x;
        current_y = next_y;
        break;
      }
    }
  }

  // Return the maze
  return maze;
}

// Print the maze to the console
void print_maze(int** maze, int width, int height) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      printf("%d ", maze[i][j]);
    }
    printf("\n");
  }
}

// Free the memory allocated for the maze
void free_maze(int** maze, int height) {
  for (int i = 0; i < height; i++) {
    free(maze[i]);
  }
  free(maze);
}

// Main function
int main() {
  // Initialize the random number generator
  init_rand();

  // Create a new maze with the given width and height
  int width = 20;
  int height = 20;
  int** maze = create_maze(width, height);

  // Print the maze to the console
  print_maze(maze, width, height);

  // Free the memory allocated for the maze
  free_maze(maze, height);

  return 0;
}