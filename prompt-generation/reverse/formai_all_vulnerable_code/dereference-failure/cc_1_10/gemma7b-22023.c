//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

void game_of_life(int **board, int rows, int cols)
{
  for (int r = 0; r < rows; r++)
  {
    for (int c = 0; c < cols; c++)
    {
      int neighbors = 0;
      // Check the neighbors
      if (r > 0) neighbors++;
      if (r < rows - 1) neighbors++;
      if (c > 0) neighbors++;
      if (c < cols - 1) neighbors++;

      // Apply the rules
      if (board[r][c] == 1 && neighbors < 2) board[r][c] = 0;
      if (board[r][c] == 0 && neighbors == 3) board[r][c] = 1;
    }
  }
}

int main()
{
  int rows = 5;
  int cols = 5;
  int **board = malloc(rows * sizeof(int *)), **temp_board = malloc(rows * sizeof(int *));

  // Initialize the board
  for (int r = 0; r < rows; r++)
  {
    board[r] = malloc(cols * sizeof(int));
    temp_board[r] = malloc(cols * sizeof(int));
    for (int c = 0; c < cols; c++)
    {
      board[r][c] = 0;
      temp_board[r][c] = 0;
    }
  }

  // Create a game of life
  board[1][1] = 1;
  board[1][2] = 1;
  board[2][1] = 1;
  board[2][2] = 1;
  board[3][1] = 1;

  // Play the game
  game_of_life(board, rows, cols);

  // Print the board
  for (int r = 0; r < rows; r++)
  {
    for (int c = 0; c < cols; c++)
    {
      printf("%d ", board[r][c]);
    }
    printf("\n");
  }

  // Free the memory
  for (int r = 0; r < rows; r++)
  {
    free(board[r]);
    free(temp_board[r]);
  }
  free(board);
  free(temp_board);

  return 0;
}