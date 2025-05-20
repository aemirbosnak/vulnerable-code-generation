//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: automated
#include <stdlib.h>
#include <time.h>

int main() {
  int x, y, n, i, j, seed, wall_num = 0, current_pos = 0;
  char **maze;

  seed = time(NULL);
  srand(seed);

  // Maze size
  n = 10 + rand() % 5;
  maze = malloc(n * sizeof(char *));
  for (i = 0; i < n; i++) {
    maze[i] = malloc(n * sizeof(char));
  }

  // Generate walls
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (rand() % 2) {
        maze[i][j] = '#';
        wall_num++;
      } else {
        maze[i][j] = ' ';
      }
    }
  }

  // Create the start and end points
  maze[0][0] = 'S';
  maze[n - 1][n - 1] = 'E';

  // Display the maze
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%c ", maze[i][j]);
    }
    printf("\n");
  }

  // Calculate the total number of walls
  printf("Total number of walls: %d\n", wall_num);

  // Free the memory
  for (i = 0; i < n; i++) {
    free(maze[i]);
  }
  free(maze);

  return 0;
}