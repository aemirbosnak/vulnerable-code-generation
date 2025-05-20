//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main()
{
  system("clear");
  printf("Welcome to the Happy Arcade!\n");

  // Define the game board
  int board[3][3] = {{0, 0, 0},
                           {0, 0, 0},
                           {0, 0, 0}};

  // Define the player's move
  int move_row, move_col;

  // Initialize the game loop
  int game_loop = 1;

  // Game loop
  while (game_loop)
  {
    // Display the game board
    for (int r = 0; r < 3; r++)
    {
      for (int c = 0; c < 3; c++)
      {
        printf("%d ", board[r][c]);
      }
      printf("\n");
    }

    // Get the player's move
    printf("Enter row (1-3): ");
    scanf("%d", &move_row);

    printf("Enter column (1-3): ");
    scanf("%d", &move_col);

    // Validate the move
    if (move_row < 1 || move_row > 3)
    {
      printf("Invalid move. Please try again.\n");
      continue;
    }

    if (move_col < 1 || move_col > 3)
    {
      printf("Invalid move. Please try again.\n");
      continue;
    }

    // Place the player's mark on the board
    board[move_row - 1][move_col - 1] = 1;

    // Check if the player has won
    int winner = check_winner(board);

    // If the player has won, end the game
    if (winner)
    {
      game_loop = 0;
      printf("Congratulations! You have won!\n");
    }

    // If there is no winner, continue the game
    else
    {
      // Check if the board is full
      if (is_board_full(board))
      {
        game_loop = 0;
        printf("It's a draw!\n");
      }
    }
  }

  return 0;
}

int check_winner(int **board)
{
  // Check rows
  for (int r = 0; r < 3; r++)
  {
    if (board[r][0] == board[r][1] && board[r][0] == board[r][2] && board[r][0] != 0)
    {
      return 1;
    }
  }

  // Check columns
  for (int c = 0; c < 3; c++)
  {
    if (board[0][c] == board[1][c] && board[0][c] == board[2][c] && board[0][c] != 0)
    {
      return 1;
    }
  }

  // Check diagonals
  if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != 0)
  {
    return 1;
  }

  // No winner
  return 0;
}

int is_board_full(int **board)
{
  for (int r = 0; r < 3; r++)
  {
    for (int c = 0; c < 3; c++)
    {
      if (board[r][c] == 0)
      {
        return 0;
      }
    }
  }

  // The board is full
  return 1;
}