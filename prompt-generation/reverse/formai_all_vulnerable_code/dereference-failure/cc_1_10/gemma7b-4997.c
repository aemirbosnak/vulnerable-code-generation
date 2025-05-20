//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

void play_game(int **board, int size)
{
  for (int r = 0; r < size; r++)
  {
    for (int c = 0; c < size; c++)
    {
      int neighbors = 0;
      if (r - 1 >= 0) neighbors++;
      if (r + 1 < size) neighbors++;
      if (c - 1 >= 0) neighbors++;
      if (c + 1 < size) neighbors++;

      if (board[r][c] == 1 && neighbors < 2) board[r][c] = 0;
      else if (board[r][c] == 0 && neighbors == 3) board[r][c] = 1;
    }
  }

  for (int r = 0; r < size; r++)
  {
    for (int c = 0; c < size; c++)
    {
      printf("%d ", board[r][c]);
    }
    printf("\n");
  }
}

int main()
{
  int size = 5;
  int **board = malloc(size * size * sizeof(int));

  for (int r = 0; r < size; r++)
  {
    for (int c = 0; c < size; c++)
    {
      board[r][c] = 0;
    }
  }

  board[1][1] = 1;
  board[2][2] = 1;
  board[2][3] = 1;

  play_game(board, size);

  free(board);

  return 0;
}