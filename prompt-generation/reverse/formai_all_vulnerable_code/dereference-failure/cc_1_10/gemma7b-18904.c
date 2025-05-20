//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

void initialize_board(int **board, int size)
{
  for (int r = 0; r < size; r++)
  {
    for (int c = 0; c < size; c++)
    {
      board[r][c] = 0;
    }
  }
}

void print_board(int **board, int size)
{
  for (int r = 0; r < size; r++)
  {
    for (int c = 0; c < size; c++)
    {
      printf("%d ", board[r][c]);
    }
    printf("\n");
  }
}

int count_neighbors(int **board, int r, int c)
{
  int neighbors = 0;

  if (r > 0)
  {
    neighbors++;
  }
  if (r < board[0] - 1)
  {
    neighbors++;
  }
  if (c > 0)
  {
    neighbors++;
  }
  if (c < board[0] - 1)
  {
    neighbors++;
  }

  return neighbors;
}

void update_board(int **board, int size)
{
  for (int r = 0; r < size; r++)
  {
    for (int c = 0; c < size; c++)
    {
      int neighbors = count_neighbors(board, r, c);

      if (neighbors == 3)
      {
        board[r][c] = 1;
      }
      else if (neighbors == 2 && board[r][c] == 1)
      {
        board[r][c] = 0;
      }
    }
  }
}

int main()
{
  int size = 5;
  int **board = (int **)malloc(size * sizeof(int *));
  for (int i = 0; i < size; i++)
  {
    board[i] = (int *)malloc(size * sizeof(int));
  }

  initialize_board(board, size);

  board[1][1] = 1;
  board[2][2] = 1;
  board[2][3] = 1;

  print_board(board, size);

  update_board(board, size);

  print_board(board, size);

  free(board);

  return 0;
}