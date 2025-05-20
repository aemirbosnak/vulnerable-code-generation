//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

void game_of_life(int **board, int size)
{
  for (int r = 0; r < size; r++)
  {
    for (int c = 0; c < size; c++)
    {
      int neighbors = 0;
      // Check the 8 neighbors
      for (int dr = -1; dr <= 1; dr++)
      {
        for (int dc = -1; dc <= 1; dc++)
        {
          if (r + dr >= 0 && r + dr < size && c + dc >= 0 && c + dc < size && board[r + dr][c + dc] == 1)
          {
            neighbors++;
          }
        }
      }

      // Apply the rules of life
      if (board[r][c] == 0 && neighbors == 3)
      {
        board[r][c] = 1;
      }
      else if (board[r][c] == 1 && (neighbors < 2 || neighbors > 3))
      {
        board[r][c] = 0;
      }
    }
  }
}

int main()
{
  int size = 10;
  int **board = (int**)malloc(size * sizeof(int*));
  for (int i = 0; i < size; i++)
  {
    board[i] = (int*)malloc(size * sizeof(int));
  }

  // Initialize the board
  board[0][0] = 1;
  board[1][1] = 1;
  board[2][2] = 1;

  // Play the game of life
  game_of_life(board, size);

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
  for (int i = 0; i < size; i++)
  {
    free(board[i]);
  }
  free(board);

  return 0;
}