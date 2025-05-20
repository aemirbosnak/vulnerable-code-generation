//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: recursive
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

void generate_maze(int x, int y, int **maze);

int main()
{
  int **maze;
  int x, y;

  maze = (int **)malloc(WIDTH * sizeof(int *));
  for (x = 0; x < WIDTH; x++)
    maze[x] = (int *)malloc(HEIGHT * sizeof(int));

  srand(time(NULL));

  generate_maze(0, 0, maze);

  for (x = 0; x < WIDTH; x++)
  {
    for (y = 0; y < HEIGHT; y++)
    {
      printf("%d ", maze[x][y]);
    }
    printf("\n");
  }

  return 0;
}

void generate_maze(int x, int y, int **maze)
{
  int r, c;

  if (x >= WIDTH || y >= HEIGHT)
    return;

  maze[x][y] = 1;

  r = rand() % 4;

  switch (r)
  {
    case 0:
      generate_maze(x + 1, y, maze);
      break;
    case 1:
      generate_maze(x, y + 1, maze);
      break;
    case 2:
      generate_maze(x - 1, y, maze);
      break;
    case 3:
      generate_maze(x, y - 1, maze);
      break;
  }
}