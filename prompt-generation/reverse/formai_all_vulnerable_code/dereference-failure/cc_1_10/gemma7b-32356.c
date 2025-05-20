//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

void GameOfLife(int **board, int size)
{
  for (int r = 0; r < size; r++)
  {
    for (int c = 0; c < size; c++)
    {
      int neighbors = 0;
      // Check neighbors to the right
      if (c + 1 < size)
      {
        neighbors++;
      }
      // Check neighbors to the left
      if (c - 1 >= 0)
      {
        neighbors++;
      }
      // Check neighbors above
      if (r - 1 >= 0)
      {
        neighbors++;
      }
      // Check neighbors below
      if (r + 1 < size)
      {
        neighbors++;
      }

      // Apply Game of Life rules
      if (board[r][c] == 1 && neighbors < 2)
      {
        board[r][c] = 0;
      }
      else if (board[r][c] == 0 && neighbors == 3)
      {
        board[r][c] = 1;
      }
    }
  }
}

int main()
{
  int size = 10;
  int **board = (int **)malloc(size * sizeof(int *));
  for (int r = 0; r < size; r++)
  {
    board[r] = (int *)malloc(size * sizeof(int));
  }

  // Initialize the board
  board[0][0] = board[0][1] = board[1][0] = 1;

  // Play the Game of Life
  GameOfLife(board, size);

  // Print the board
  for (int r = 0; r < size; r++)
  {
    for (int c = 0; c < size; c++)
    {
      printf("%d ", board[r][c]);
    }
    printf("\n");
  }

  // Free the memory
  for (int r = 0; r < size; r++)
  {
    free(board[r]);
  }
  free(board);

  return 0;
}