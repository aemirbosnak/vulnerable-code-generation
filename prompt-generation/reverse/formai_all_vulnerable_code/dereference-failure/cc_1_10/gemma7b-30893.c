//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: mind-bending
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Board {
  int **board;
  int current_player;
  int game_status;
} Board;

Board* initialize_board() {
  Board* board = malloc(sizeof(Board));
  board->board = malloc(sizeof(int*) * BOARD_SIZE);
  for (int i = 0; i < BOARD_SIZE; i++) {
    board->board[i] = malloc(sizeof(int) * BOARD_SIZE);
  }
  board->current_player = 1;
  board->game_status = 0;
  return board;
}

void place_mark(Board* board, int row, int col) {
  if (board->board[row][col] != 0) {
    return;
  }
  board->board[row][col] = board->current_player;
}

int check_win(Board* board) {
  // Check rows
  for (int r = 0; r < BOARD_SIZE; r++) {
    if (board->board[r][0] == board->board[r][1] && board->board[r][0] == board->board[r][2] && board->board[r][0] != 0) {
      return board->board[r][0];
    }
  }

  // Check columns
  for (int c = 0; c < BOARD_SIZE; c++) {
    if (board->board[0][c] == board->board[1][c] && board->board[0][c] == board->board[2][c] && board->board[0][c] != 0) {
      return board->board[0][c];
    }
  }

  // Check diagonals
  if (board->board[0][0] == board->board[1][1] && board->board[0][0] == board->board[2][2] && board->board[0][0] != 0) {
    return board->board[0][0];
  }

  // If all cells are occupied and there is no winner, it's a draw
  return 0;
}

void play_game(Board* board) {
  int game_continue = 1;
  while (game_continue) {
    int row, col;
    printf("Enter row: ");
    scanf("%d", &row);
    printf("Enter column: ");
    scanf("%d", &col);

    place_mark(board, row, col);

    int winner = check_win(board);
    if (winner != 0) {
      game_continue = 0;
      printf("Winner: Player %d\n", winner);
    } else if (board->game_status == 1) {
      game_continue = 0;
      printf("It's a draw!\n");
    } else {
      board->current_player = (board->current_player == 1) ? 2 : 1;
    }
  }
}

int main() {
  Board* board = initialize_board();
  play_game(board);
  free(board);
  return 0;
}