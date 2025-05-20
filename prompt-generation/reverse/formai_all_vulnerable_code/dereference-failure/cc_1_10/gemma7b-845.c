//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

void initialize_board(int **board, int size)
{
  int i, j;
  board = (int *)malloc(size * size * sizeof(int));
  for (i = 0; i < size; i++)
  {
    for (j = 0; j < size; j++)
    {
      board[i][j] = 0;
    }
  }
}

void print_board(int **board, int size)
{
  int i, j;
  for (i = 0; i < size; i++)
  {
    for (j = 0; j < size; j++)
    {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }
}

void calculate_next_generation(int **board, int size)
{
  int i, j, neighbors, alive_neighbors;
  for (i = 0; i < size; i++)
  {
    for (j = 0; j < size; j++)
    {
      neighbors = 0;
      alive_neighbors = 0;
      // Check the four neighbors
      if (i > 0) neighbors++;
      if (i < size - 1) neighbors++;
      if (j > 0) neighbors++;
      if (j < size - 1) neighbors++;

      // Count the number of alive neighbors
      if (board[i - 1][j] == 1) alive_neighbors++;
      if (board[i + 1][j] == 1) alive_neighbors++;
      if (board[i][j - 1] == 1) alive_neighbors++;
      if (board[i][j + 1] == 1) alive_neighbors++;

      // Apply the Game of Life rules
      if (board[i][j] == 1 && (neighbors < 2 || neighbors > 3)) board[i][j] = 0;
      else if (board[i][j] == 0 && neighbors == 3) board[i][j] = 1;
    }
  }
}

int main()
{
  int size = MAX_SIZE;
  int **board;

  initialize_board(board, size);

  // Create an initial board
  board[0][0] = 1;
  board[0][1] = 1;
  board[1][0] = 1;
  board[1][1] = 1;

  print_board(board, size);

  // Calculate the next generation
  calculate_next_generation(board, size);

  print_board(board, size);

  return 0;
}