//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void GameOfLife(int **board, int n, int m)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      int neighbors = 0;
      if (i > 0) neighbors++;
      if (i < n - 1) neighbors++;
      if (j > 0) neighbors++;
      if (j < m - 1) neighbors++;

      if (board[i][j] == 1)
      {
        if (neighbors < 2) board[i][j] = 0;
        else if (neighbors > 3) board[i][j] = 0;
      }
      else if (neighbors == 3) board[i][j] = 1;
    }
  }
  return;
}

int main()
{
  int n, m;
  scanf("Enter the number of rows:", &n);
  scanf("Enter the number of columns:", &m);

  int **board = malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) board[i] = malloc(m * sizeof(int));

  // Initialize the game board
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++) board[i][j] = 0;
  }

  // Get the initial state of the game board
  // (This part can be replaced with actual logic to read the initial state from the user)
  board[0][0] = 1;
  board[0][1] = 1;
  board[1][0] = 1;
  board[1][1] = 1;

  // Play the game
  GameOfLife(board, n, m);

  // Print the final state of the game board
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++) printf("%d ", board[i][j]);
    printf("\n");
  }

  return 0;
}