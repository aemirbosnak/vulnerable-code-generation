//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  system("clear");
  int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  int turn = 1;
  char sign = 'X';
  int game_on = 1;

  while (game_on) {
    // Get the move
    int move_x = rand() % 3;
    int move_y = rand() % 3;

    // Check if the move is valid
    if (board[move_x][move_y] != 0) {
      continue;
    }

    // Make the move
    board[move_x][move_y] = turn;

    // Check if the player has won
    if (check_win(board, turn) == 1) {
      game_on = 0;
      printf("You won!");
    } else if (check_win(board, turn) == 2) {
      game_on = 0;
      printf("The AI won!");
    } else {
      // Next turn
      turn *= -1;
      sign = 'O';
    }
  }

  return 0;
}

int check_win(int **board, int turn) {
  // Check rows
  for (int i = 0; i < 3; i++) {
    if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] == turn) {
      return turn;
    }
  }

  // Check columns
  for (int j = 0; j < 3; j++) {
    if (board[j][0] == board[j][1] && board[j][0] == board[j][2] && board[j][0] == turn) {
      return turn;
    }
  }

  // Check diagonals
  if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == turn) {
    return turn;
  } else if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] == turn) {
    return turn;
  }

  // No win
  return 0;
}