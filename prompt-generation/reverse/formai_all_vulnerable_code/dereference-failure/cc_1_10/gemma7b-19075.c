//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: retro
#include <stdlib.h>
#include <time.h>

void draw_board(int **board, int size)
{
  for (int r = 0; r < size; r++)
  {
    for (int c = 0; c < size; c++)
    {
      printf("%c ", board[r][c] ? '*' : '.');
    }
    printf("\n");
  }
}

int main()
{
  int size = 10;
  int **board = (int**)malloc(size * sizeof(int *));
  for (int r = 0; r < size; r++)
  {
    board[r] = (int*)malloc(size * sizeof(int));
  }

  // Initialize the board with random values
  srand(time(NULL));
  for (int r = 0; r < size; r++)
  {
    for (int c = 0; c < size; c++)
    {
      board[r][c] = rand() % 2;
    }
  }

  // Simulate the game of life for 10 generations
  for (int gen = 0; gen < 10; gen++)
  {
    draw_board(board, size);
    // Calculate the next generation of cells
    for (int r = 0; r < size; r++)
    {
      for (int c = 0; c < size; c++)
      {
        int neighbors = 0;
        // Check the number of neighbors
        for (int dr = -1; dr <= 1; dr++)
        {
          for (int dc = -1; dc <= 1; dc++)
          {
            if (board[r + dr][c + dc] && board[r + dr][c + dc] != 0)
            {
              neighbors++;
            }
          }
        }

        // Update the cell's state
        if (board[r][c] == 0 && neighbors >= 3)
        {
          board[r][c] = 1;
        }
        else if (board[r][c] == 1 && neighbors < 2)
        {
          board[r][c] = 0;
        }
      }
    }
  }

  draw_board(board, size);

  free(board);

  return 0;
}