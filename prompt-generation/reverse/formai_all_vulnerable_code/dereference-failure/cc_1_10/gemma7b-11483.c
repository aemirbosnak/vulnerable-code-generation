//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10

void generate_maze(int **maze, int w, int h)
{
  int i, j, r, n_rooms = 0;
  time_t t = time(NULL);

  // Allocate memory for the maze
  maze = (int **)malloc(w * h * sizeof(int *));
  for (i = 0; i < w * h; i++)
  {
    maze[i] = (int *)malloc(h * sizeof(int));
  }

  // Randomly choose the number of rooms
  n_rooms = rand() % MAX_ROOMS;

  // Create the rooms
  for (r = 0; r < n_rooms; r++)
  {
    i = rand() % w;
    j = rand() % h;
    maze[i][j] = 1;
  }

  // Connect the rooms
  for (r = 0; r < n_rooms; r++)
  {
    i = rand() % w;
    j = rand() % h;
    if (maze[i][j] == 1)
    {
      maze[i][j] = 2;
    }
  }
}

int main()
{
  int w, h, **maze;

  // Generate the maze
  generate_maze(&maze, w, h);

  // Print the maze
  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      printf("%d ", maze[i][j]);
    }
    printf("\n");
  }

  return 0;
}