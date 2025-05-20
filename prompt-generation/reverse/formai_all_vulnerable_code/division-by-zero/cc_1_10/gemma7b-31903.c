//Gemma-7B DATASET v1.0 Category: Table Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBER 10

int main()
{
  int number_of_players = 2;
  int current_player = 0;
  int board[MAX_NUMBER] = {0};

  // Initialize the board
  for (int i = 0; i < MAX_NUMBER; i++)
  {
    board[i] = -1;
  }

  // Game loop
  while (number_of_players > 0)
  {
    // Get the player's move
    int move = get_player_move();

    // Validate the move
    if (move < 0 || move >= MAX_NUMBER)
    {
      printf("Invalid move.\n");
      continue;
    }

    // Place the piece on the board
    board[move] = current_player;

    // Check if the player has won
    if (check_win(board, current_player))
    {
      printf("Player %d has won!\n", current_player);
      number_of_players--;
    }

    // Next player
    current_player = (current_player + 1) % number_of_players;
  }

  // Game over
  printf("Game over.\n");

  return 0;
}

int get_player_move()
{
  int move;

  printf("Enter your move: ");
  scanf("%d", &move);

  return move;
}

int check_win(int board[], int player)
{
  // Check rows
  for (int i = 0; i < MAX_NUMBER - 2; i++)
  {
    if (board[i] == board[i + 1] && board[i] == board[i + 2] && board[i] == player)
    {
      return 1;
    }
  }

  // Check columns
  for (int j = 0; j < MAX_NUMBER - 2; j++)
  {
    if (board[j] == board[j + 1] && board[j] == board[j + 2] && board[j] == player)
    {
      return 1;
    }
  }

  // Check diagonals
  if (board[0] == board[4] && board[0] == board[8] && board[0] == player)
  {
    return 1;
  }

  // No win
  return 0;
}