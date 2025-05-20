//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: mathematical
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAZE_SIZE 10
#define WALL_CHAR '#'
#define EMPTY_CHAR '.'

void generateMaze(int **maze, int size)
{
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      maze[i][j] = EMPTY_CHAR;
    }
  }

  // Create a random seed
  srand(time(NULL));

  // Generate walls randomly
  for (int i = 0; i < size * size; i++)
  {
    int x = rand() % size;
    int y = rand() % size;
    maze[x][y] = WALL_CHAR;
  }
}

int main()
{
  int **maze = NULL;
  int size = MAZE_SIZE;

  maze = (int **)malloc(size * sizeof(int *));
  for (int i = 0; i < size; i++)
  {
    maze[i] = (int *)malloc(size * sizeof(int));
  }

  generateMaze(maze, size);

  // Print the maze
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      printf("%c ", maze[i][j]);
    }
    printf("\n");
  }

  return 0;
}