//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define ROWS 20
#define COLS 40

void draw_invaders(int **invaders, int row, int col)
{
  invaders[row][col] = 1;
  printf("%c ", invaders[row][col] ? '#' : ' ');
}

void move_invaders(int **invaders, int direction)
{
  for (int row = 0; row < ROWS; row++)
  {
    for (int col = 0; col < COLS; col++)
    {
      if (invaders[row][col] && direction == 0)
      {
        invaders[row][col] = 0;
        invaders[row][col - 1] = 1;
      }
      else if (invaders[row][col] && direction == 1)
      {
        invaders[row][col] = 0;
        invaders[row][col + 1] = 1;
      }
    }
  }
}

int main()
{
  int **invaders = (int **)malloc(ROWS * sizeof(int *));
  for (int i = 0; i < ROWS; i++)
  {
    invaders[i] = (int *)malloc(COLS * sizeof(int));
  }

  int direction = 0;
  for (int i = 0; i < 100; i++)
  {
    system("clear");
    draw_invaders(invaders, 0, 0);
    move_invaders(invaders, direction);
    draw_invaders(invaders, 0, 0);
    printf("\n");
    sleep(1);
  }

  return 0;
}