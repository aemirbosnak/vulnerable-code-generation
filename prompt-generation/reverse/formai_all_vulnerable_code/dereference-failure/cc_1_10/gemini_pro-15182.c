//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// Cell directions
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

// Maze dimensions
#define WIDTH 100
#define HEIGHT 50

// Maze data structure
typedef struct {
  int x;
  int y;
  int walls[4]; // 0 = no wall, 1 = wall
} cell;

// Function to generate a maze
void generate_maze(cell *maze) {
  // Initialize the maze
  for (int i = 0; i < WIDTH; i++) {
    for (int j = 0; j < HEIGHT; j++) {
      maze[i * HEIGHT + j].x = i;
      maze[i * HEIGHT + j].y = j;
      for (int k = 0; k < 4; k++) {
        maze[i * HEIGHT + j].walls[k] = 1;
      }
    }
  }

  // Create the maze using a depth-first search
  int stack[WIDTH * HEIGHT];
  int stack_size = 0;
  int current_cell = rand() % (WIDTH * HEIGHT);
  while (stack_size > 0 || maze[current_cell].walls[NORTH]) {
    // Push the current cell onto the stack
    stack[stack_size++] = current_cell;

    // Check if there are any unvisited neighbors
    int neighbors[4];
    int num_neighbors = 0;
    if (maze[current_cell].y > 0 && maze[current_cell - HEIGHT].walls[SOUTH]) {
      neighbors[num_neighbors++] = current_cell - HEIGHT;
    }
    if (maze[current_cell].x < WIDTH - 1 && maze[current_cell + 1].walls[WEST]) {
      neighbors[num_neighbors++] = current_cell + 1;
    }
    if (maze[current_cell].y < HEIGHT - 1 && maze[current_cell + HEIGHT].walls[NORTH]) {
      neighbors[num_neighbors++] = current_cell + HEIGHT;
    }
    if (maze[current_cell].x > 0 && maze[current_cell - 1].walls[EAST]) {
      neighbors[num_neighbors++] = current_cell - 1;
    }

    // If there are no unvisited neighbors, pop the current cell from the stack
    if (num_neighbors == 0) {
      current_cell = stack[--stack_size];
    }
    // Otherwise, choose a random unvisited neighbor and visit it
    else {
      int next_cell = neighbors[rand() % num_neighbors];
      maze[current_cell].walls[next_cell < current_cell ? SOUTH : NORTH] = 0;
      maze[next_cell].walls[current_cell < next_cell ? NORTH : SOUTH] = 0;
      current_cell = next_cell;
    }
  }
}

// Function to print the maze
void print_maze(cell *maze) {
  // Print the top border
  for (int i = 0; i < WIDTH; i++) {
    printf("+--");
  }
  printf("+\n");

  // Print the maze cells
  for (int j = 0; j < HEIGHT; j++) {
    // Print the left border
    printf("| ");

    // Print the cell contents
    for (int i = 0; i < WIDTH; i++) {
      if (maze[i * HEIGHT + j].walls[EAST]) {
        printf(" |");
      } else {
        printf("  ");
      }
    }

    // Print the right border
    printf(" |\n");

    // Print the bottom border
    if (j < HEIGHT - 1) {
      for (int i = 0; i < WIDTH; i++) {
        if (maze[i * HEIGHT + j].walls[SOUTH]) {
          printf("+--");
        } else {
          printf("  ");
        }
      }
      printf("+\n");
    }
  }
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Allocate memory for the maze
  cell *maze = malloc(sizeof(cell) * WIDTH * HEIGHT);

  // Generate the maze
  generate_maze(maze);

  // Print the maze
  print_maze(maze);

  // Free the memory for the maze
  free(maze);

  return 0;
}