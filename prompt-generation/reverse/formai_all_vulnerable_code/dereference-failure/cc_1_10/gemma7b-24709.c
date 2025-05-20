//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

typedef struct Board {
  int **board;
  int current_player;
  int winner;
} Board;

Board *init_board() {
  Board *board = malloc(sizeof(Board));
  board->board = malloc(BOARD_SIZE * BOARD_SIZE * sizeof(int));
  board->current_player = 1;
  board->winner = 0;

  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board->board[i][j] = 0;
    }
  }

  return board;
}

void play_game(Board *board) {
  int move_row, move_col;

  printf("Enter your move (row, column): ");
  scanf("%d %d", &move_row, &move_col);

  if (!valid_move(board, move_row, move_col)) {
    printf("Invalid move.\n");
    return;
  }

  board->board[move_row][move_col] = board->current_player;

  if (check_winner(board)) {
    board->winner = board->current_player;
  } else {
    board->current_player *= -1;
  }
}

int valid_move(Board *board, int move_row, int move_col) {
  if (move_row < 0 || move_row >= BOARD_SIZE) {
    return 0;
  }

  if (move_col < 0 || move_col >= BOARD_SIZE) {
    return 0;
  }

  if (board->board[move_row][move_col] != 0) {
    return 0;
  }

  return 1;
}

int check_winner(Board *board) {
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

  // No winner
  return 0;
}

int main() {
  Board *board = init_board();

  while (!board->winner) {
    play_game(board);
  }

  printf("The winner is: %d\n", board->winner);

  free(board->board);
  free(board);

  return 0;
}