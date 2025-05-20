//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Board {
  int **board;
  int current_player;
  int game_status;
} Board;

void initialize_board(Board *board) {
  board->board = malloc(BOARD_SIZE * BOARD_SIZE * sizeof(int));
  board->current_player = 1;
  board->game_status = 0;

  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board->board[i][j] = 0;
    }
  }
}

int check_if_won(Board *board) {
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board->board[0][i] == board->board[1][i] && board->board[0][i] == board->board[2][i] && board->board[0][i] != 0) {
      return board->board[0][i] * 2;
    }
  }

  // Check columns
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board->board[j][0] == board->board[j][1] && board->board[j][0] == board->board[j][2] && board->board[j][0] != 0) {
      return board->board[j][0] * 2;
    }
  }

  // Check diagonals
  if (board->board[0][0] == board->board[1][1] && board->board[0][0] == board->board[2][2] && board->board[0][0] != 0) {
    return board->board[0][0] * 2;
  }

  // If all else fails, it's a draw
  return 0;
}

void play_game(Board *board) {
  int move_made = 0;

  // Loop until someone wins, draws, or it's a tie
  while (!board->game_status) {
    // Get the player's move
    int row, column;
    printf("Enter your move (row, column): ");
    scanf("%d %d", &row, &column);

    // Check if the move is valid
    if (board->board[row][column] != 0) {
      printf("Invalid move. Please try again.\n");
      continue;
    }

    // Make the move
    board->board[row][column] = board->current_player;

    // Check if the player has won
    if (check_if_won(board) != 0) {
      board->game_status = 1;
      printf("Congratulations! You won!\n");
    } else {
      // If there has not been a winner, switch to the next player
      board->current_player *= -1;
    }

    move_made++;
  }

  // If the game has ended, but there has not been a winner, it's a draw
  if (move_made == BOARD_SIZE * BOARD_SIZE && board->game_status == 0) {
    board->game_status = 1;
    printf("It's a draw!\n");
  }
}

int main() {
  Board board;
  initialize_board(&board);
  play_game(&board);

  return 0;
}