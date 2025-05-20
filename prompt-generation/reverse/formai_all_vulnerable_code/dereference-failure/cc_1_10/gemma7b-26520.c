//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Board {
  int **board;
  int current_player;
  int game_state;
} Board;

void initialize_board(Board *board) {
  board->board = malloc(BOARD_SIZE * sizeof(int *));
  for (int i = 0; i < BOARD_SIZE; i++) {
    board->board[i] = malloc(BOARD_SIZE * sizeof(int));
  }

  board->current_player = 1;
  board->game_state = 0;
}

void display_board(Board *board) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%d ", board->board[i][j]);
    }
    printf("\n");
  }
}

int check_board(Board *board) {
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board->board[0][i] == board->board[1][i] && board->board[0][i] == board->board[2][i] && board->board[0][i] != 0) {
      return board->board[0][i];
    }
  }

  // Check columns
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board->board[j][0] == board->board[j][1] && board->board[j][0] == board->board[j][2] && board->board[j][0] != 0) {
      return board->board[j][0];
    }
  }

  // Check diagonals
  if (board->board[0][0] == board->board[1][1] && board->board[0][0] == board->board[2][2] && board->board[0][0] != 0) {
    return board->board[0][0];
  }

  // If all else fails, it's a draw
  return 0;
}

int main() {
  Board board;
  initialize_board(&board);

  display_board(&board);

  int game_state = check_board(&board);

  if (game_state != 0) {
    printf("The winner is: %d", game_state);
  } else {
    printf("It's a draw!");
  }

  return 0;
}