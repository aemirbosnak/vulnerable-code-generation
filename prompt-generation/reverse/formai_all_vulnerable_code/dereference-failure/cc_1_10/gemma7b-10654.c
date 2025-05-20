//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: scientific
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define BOARD_SIZE 3
#define PLAYER_X 1
#define PLAYER_O 2

int main() {
  int board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0},
                                {0, 0, 0},
                                {0, 0, 0}};

  int player = PLAYER_X;
  int move_count = 0;

  // Game loop
  while (!board[1][1] && move_count < 9) {
    // Get the move
    int move_x = rand() % BOARD_SIZE;
    int move_y = rand() % BOARD_SIZE;

    // Check if the move is valid
    if (board[move_x][move_y] != 0) {
      continue;
    }

    // Make the move
    board[move_x][move_y] = player;

    // Increment the move count
    move_count++;

    // Switch player
    player = (player == PLAYER_X) ? PLAYER_O : PLAYER_X;
  }

  // Check if the player won or if it's a draw
  int winner = check_winner(board);
  if (winner == PLAYER_X) {
    printf("Player X won!\n");
  } else if (winner == PLAYER_O) {
    printf("Player O won!\n");
  } else {
    printf("It's a draw!\n");
  }

  return 0;
}

int check_winner(int **board) {
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != 0) {
      return board[0][i];
    }
  }

  // Check columns
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board[j][0] == board[j][1] && board[j][0] == board[j][2] && board[j][0] != 0) {
      return board[j][0];
    }
  }

  // Check diagonals
  if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != 0) {
    return board[0][0];
  }

  // If there has not been a winner, it's a draw
  return 0;
}