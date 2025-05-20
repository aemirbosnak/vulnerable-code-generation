//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define EMPTY_SPOT 0
#define PLAYER_X 1
#define PLAYER_O 2

int main()
{
  // Seed the random number generator
  srand(time(NULL));

  // Create the game board
  int board[BOARD_SIZE][BOARD_SIZE] = { EMPTY_SPOT, EMPTY_SPOT, EMPTY_SPOT,
                                EMPTY_SPOT, EMPTY_SPOT, EMPTY_SPOT,
                                EMPTY_SPOT, EMPTY_SPOT, EMPTY_SPOT };

  // Determine the player's move
  int move = rand() % 9;

  // Place the player's mark on the board
  board[move / BOARD_SIZE][move % BOARD_SIZE] = PLAYER_X;

  // Check if the player has won
  if (check_win(board, PLAYER_X))
  {
    printf("You win!\n");
  }
  else
  {
    // If the board is full, it's a draw
    if (is_board_full(board))
    {
      printf("Draw!\n");
    }
    else
    {
      // Next move
      move = rand() % 9;
      board[move / BOARD_SIZE][move % BOARD_SIZE] = PLAYER_O;

      // Check if the computer has won
      if (check_win(board, PLAYER_O))
      {
        printf("Computer wins!\n");
      }
      else
      {
        // It's a draw
        printf("Draw!\n");
      }
    }
  }

  return 0;
}

int check_win(int **board, int player)
{
  // Check rows
  for (int r = 0; r < BOARD_SIZE; r++)
  {
    if (board[r][0] == player && board[r][1] == player && board[r][2] == player)
    {
      return 1;
    }
  }

  // Check columns
  for (int c = 0; c < BOARD_SIZE; c++)
  {
    if (board[0][c] == player && board[1][c] == player && board[2][c] == player)
    {
      return 1;
    }
  }

  // Check diagonals
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
  {
    return 1;
  }
  else if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
  {
    return 1;
  }

  return 0;
}

int is_board_full(int **board)
{
  for (int r = 0; r < BOARD_SIZE; r++)
  {
    for (int c = 0; c < BOARD_SIZE; c++)
    {
      if (board[r][c] == EMPTY_SPOT)
      {
        return 0;
      }
    }
  }

  return 1;
}