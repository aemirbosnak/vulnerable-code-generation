//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: unmistakable
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_X 1
#define PLAYER_O 2

int main()
{
  int board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0},
                               {0, 0, 0},
                               {0, 0, 0}};

  // Seed the random number generator
  srand(time(NULL));

  // Play until one player wins or it's a draw
  while (1)
  {
    // Get the player's move
    int move = rand() % 9;

    // If the move is valid, make it
    if (board[move / BOARD_SIZE][move % BOARD_SIZE] == 0)
    {
      board[move / BOARD_SIZE][move % BOARD_SIZE] = PLAYER_X;

      // Check if the player has won
      if (check_win(board, PLAYER_X))
      {
        printf("Player X has won!\n");
        break;
      }
    }
  }

  // If the game ends in a draw, print a draw message
  if (board[0][0] == 0 && board[1][0] == 0 && board[2][0] == 0)
  {
    printf("It's a draw!\n");
  }

  return 0;
}

int check_win(int **board, int player)
{
  // Check if the player has won in a row
  for (int i = 0; i < BOARD_SIZE; i++)
  {
    if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
    {
      return 1;
    }
  }

  // Check if the player has won in a column
  for (int j = 0; j < BOARD_SIZE; j++)
  {
    if (board[j][0] == player && board[j][1] == player && board[j][2] == player)
    {
      return 1;
    }
  }

  // Check if the player has won in a diagonal
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
  {
    return 1;
  }

  // If the player has not won, return 0
  return 0;
}