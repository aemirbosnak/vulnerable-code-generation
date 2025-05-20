//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

void initialize_board(int **board)
{
  for (int i = 0; i < MAX_SIZE; i++)
  {
    for (int j = 0; j < MAX_SIZE; j++)
    {
      board[i][j] = 0;
    }
  }
}

void print_board(int **board)
{
  for (int i = 0; i < MAX_SIZE; i++)
  {
    for (int j = 0; j < MAX_SIZE; j++)
    {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }
}

int calculate_alive(int **board, int i, int j)
{
  int alive = 0;
  for (int r = -1; r <= 1; r++)
  {
    for (int c = -1; c <= 1; c++)
    {
      if (board[i + r][j + c] == 1)
      {
        alive++;
      }
    }
  }
  return alive;
}

void update_board(int **board)
{
  for (int i = 0; i < MAX_SIZE; i++)
  {
    for (int j = 0; j < MAX_SIZE; j++)
    {
      int alive = calculate_alive(board, i, j);
      if (alive < 2)
      {
        board[i][j] = 0;
      }
      else if (alive == 2)
      {
        board[i][j] = 1;
      }
    }
  }
}

int main()
{
  int **board = (int **)malloc(MAX_SIZE * sizeof(int *));
  for (int i = 0; i < MAX_SIZE; i++)
  {
    board[i] = (int *)malloc(MAX_SIZE * sizeof(int));
  }

  initialize_board(board);

  // Play the game
  int turn = 0;
  while (1)
  {
    print_board(board);

    // Get the move
    int x, y;
    printf("Enter move (x, y): ");
    scanf("%d %d", &x, &y);

    // Place the mark
    board[x][y] = 1;

    // Update the board
    update_board(board);

    // Check if the game is over
    if (board[2][2] == 1)
    {
      printf("Game over! Player %d won!", turn);
      break;
    }

    // Switch turns
    turn++;
  }

  // Free the memory
  for (int i = 0; i < MAX_SIZE; i++)
  {
    free(board[i]);
  }
  free(board);

  return 0;
}