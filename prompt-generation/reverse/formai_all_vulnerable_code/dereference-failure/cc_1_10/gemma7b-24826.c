//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: Alan Turing
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

int main()
{
  int x, y;
  int **maze = NULL;
  int seed = time(NULL);

  maze = malloc(WIDTH * HEIGHT * sizeof(int));
  for (x = 0; x < WIDTH; x++)
  {
    for (y = 0; y < HEIGHT; y++)
    {
      maze[x][y] = 0;
    }
  }

  // Seed the random number generator
  srand(seed);

  // Generate the maze
  for (x = 0; x < WIDTH; x++)
  {
    for (y = 0; y < HEIGHT; y++)
    {
      if (rand() % 2 == 0)
      {
        maze[x][y] = 1;
      }
    }
  }

  // Draw the maze
  for (x = 0; x < WIDTH; x++)
  {
    for (y = 0; y < HEIGHT; y++)
    {
      if (maze[x][y] == 1)
      {
        printf("%c", '#');
      }
      else
      {
        printf("%c", '.');
      }
    }
    printf("\n");
  }

  free(maze);

  return 0;
}