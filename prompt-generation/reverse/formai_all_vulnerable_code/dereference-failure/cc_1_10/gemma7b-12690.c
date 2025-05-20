//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

void draw_board(int **board, int size)
{
  for(int r = 0; r < size; r++)
  {
    for(int c = 0; c < size; c++)
    {
      printf("%c ", board[r][c] ? 'O' : '.');
    }
    printf("\n");
  }
}

int main()
{
  int size = 5;
  int **board = (int**)malloc(size * sizeof(int*));
  for(int r = 0; r < size; r++)
  {
    board[r] = (int*)malloc(size * sizeof(int));
  }

  // Game setup
  board[2][2] = 1;
  board[2][3] = 1;
  board[3][2] = 1;
  board[3][3] = 1;

  // Game loop
  int generations = 0;
  while(1)
  {
    draw_board(board, size);
    printf("Generation: %d\n", generations);

    // Calculate next generation
    int **next_board = (int**)malloc(size * sizeof(int*));
    for(int r = 0; r < size; r++)
    {
      next_board[r] = (int*)malloc(size * sizeof(int));
    }

    for(int r = 0; r < size; r++)
    {
      for(int c = 0; c < size; c++)
      {
        int neighbors = 0;
        if(board[r-1][c] == 1) neighbors++;
        if(board[r+1][c] == 1) neighbors++;
        if(board[r][c-1] == 1) neighbors++;
        if(board[r][c+1] == 1) neighbors++;

        next_board[r][c] = neighbors == 3 ? 1 : 0;
      }
    }

    // Free previous generation
    for(int r = 0; r < size; r++)
    {
      free(board[r]);
    }
    free(board);

    // Update board
    board = next_board;
    generations++;

    // Check if game is over
    if(board[0][0] == 1)
    {
      draw_board(board, size);
      printf("Game over! Cell %d, %d is alive.\n", 0, 0);
      break;
    }
  }

  return 0;
}