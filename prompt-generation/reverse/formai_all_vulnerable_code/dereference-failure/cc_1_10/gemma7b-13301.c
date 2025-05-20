//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX 9

int sudoku_solver(int **board, int size)
{
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      if (board[i][j] == 0)
      {
        for (int k = 0; k < size; k++)
        {
          if (board[k][j] != 0 && board[i][k] != 0 && board[k][j] == board[i][j])
          {
            board[i][j] = board[k][j];
          }
        }
        if (board[i][j] == 0)
        {
          return 0;
        }
      }
    }
  }
  return 1;
}

int main()
{
  int board[MAX][MAX] = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
                            {6, 0, 0, 1, 9, 5, 0, 0, 0},
                            {0, 9, 8, 0, 0, 0, 0, 0, 0},
                            {8, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0}};

  if (sudoku_solver(board, MAX) == 1)
  {
    for (int i = 0; i < MAX; i++)
    {
      for (int j = 0; j < MAX; j++)
      {
        printf("%d ", board[i][j]);
      }
      printf("\n");
    }
  }
  else
  {
    printf("No solution found!");
  }

  return 0;
}