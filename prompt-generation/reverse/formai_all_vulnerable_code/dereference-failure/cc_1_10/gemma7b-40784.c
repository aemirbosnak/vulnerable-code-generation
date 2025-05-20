//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

void simulateBingo(int **board, int size)
{
  for (int row = 0; row < size; row++)
  {
    for (int col = 0; col < size; col++)
    {
      if (board[row][col] == 0)
      {
        printf("Enter number for cell (%d, %d): ", row, col);
        int num = atoi(stdin);
        board[row][col] = num;
      }
    }
  }
  // Check for bingo
  for (int row = 0; row < size; row++)
  {
    if (board[row][0] == board[row][1] && board[row][0] == board[row][2])
    {
      printf("Bingo! Row %d won!\n", row);
    }
  }
  for (int col = 0; col < size; col++)
  {
    if (board[0][col] == board[1][col] && board[0][col] == board[2][col])
    {
      printf("Bingo! Column %d won!\n", col);
    }
  }
  if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
  {
    printf("Bingo! Diagonal won!\n");
  }
}

int main()
{
  int size = 3;
  int **board = (int **)malloc(size * sizeof(int *));
  for (int i = 0; i < size; i++)
  {
    board[i] = (int *)malloc(size * sizeof(int));
  }

  simulateBingo(board, size);

  for (int i = 0; i < size; i++)
  {
    free(board[i]);
  }
  free(board);

  return 0;
}