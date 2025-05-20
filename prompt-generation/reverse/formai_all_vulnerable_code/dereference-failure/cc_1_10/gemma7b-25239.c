//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

void GameOfLife(int **board, int rows, int cols)
{
  int i, j, r, c, liveNeighbors = 0;
  for (i = 0; i < rows; i++)
  {
    for (j = 0; j < cols; j++)
    {
      liveNeighbors = 0;
      for (r = -1; r <= 1; r++)
      {
        for (c = -1; c <= 1; c++)
        {
          if (r == 0 && c == 0)
            continue;
          if (board[i + r][j + c] == 1)
            liveNeighbors++;
        }
      }
      if (board[i][j] == 1 && liveNeighbors < 2)
        board[i][j] = 0;
      else if (board[i][j] == 0 && liveNeighbors == 2)
        board[i][j] = 1;
    }
  }
}

int main()
{
  int rows, cols;
  printf("Enter the number of rows: ");
  scanf("%d", &rows);
  printf("Enter the number of columns: ");
  scanf("%d", &cols);

  int **board = malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; i++)
  {
    board[i] = malloc(cols * sizeof(int));
  }

  // Initialize the game board
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      board[i][j] = 0;
    }
  }

  // Set the initial state of the game board
  board[1][1] = board[2][2] = board[3][2] = 1;

  // Play the game of life
  GameOfLife(board, rows, cols);

  // Print the final state of the game board
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }

  free(board);
  return 0;
}