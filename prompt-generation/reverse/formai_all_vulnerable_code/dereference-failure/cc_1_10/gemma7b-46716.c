//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void initialize_board(int **board, int size)
{
  board = (int *)malloc(size * size * sizeof(int));
  for (int i = 0; i < size * size; i++)
  {
    board[i] = 0;
  }
}

void print_board(int **board, int size)
{
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }
}

void calculate_next_state(int **board, int size)
{
  int **next_board = (int *)malloc(size * size * sizeof(int));
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      int alive_neighbors = 0;
      for (int r = -1; r <= 1; r++)
      {
        for (int c = -1; c <= 1; c++)
        {
          if (r == 0 && c == 0)
            continue;
          if (board[i + r][j + c] == 1)
            alive_neighbors++;
        }
      }
      next_board[i][j] = (alive_neighbors == 2) || (alive_neighbors == 3);
    }
  }
  free(next_board);
}

int main()
{
  int size = MAX;
  int **board = NULL;
  initialize_board(board, size);

  // Play the game
  for (int t = 0; t < 10; t++)
  {
    print_board(board, size);
    calculate_next_state(board, size);
  }

  print_board(board, size);
  free(board);

  return 0;
}