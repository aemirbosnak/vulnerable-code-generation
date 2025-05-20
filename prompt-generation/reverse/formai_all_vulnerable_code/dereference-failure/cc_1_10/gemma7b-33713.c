//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Cryptic
#include <stdlib.h>
#include <time.h>

#define MAX_BOARD_SIZE 3

typedef struct Board {
  int **board;
  int size;
  int turn;
} Board;

Board *initBoard(int size) {
  Board *board = malloc(sizeof(Board));
  board->size = size;
  board->board = malloc(size * size * sizeof(int));
  board->turn = 0;

  for (int i = 0; i < size * size; i++) {
    board->board[i] = 0;
  }

  return board;
}

int move(Board *board, int x, int y) {
  if (board->board[x][y] != 0) {
    return -1;
  }

  board->board[x][y] = board->turn;
  board->turn++;

  return 0;
}

int checkWin(Board *board, int player) {
  for (int i = 0; i < board->size; i++) {
    // Check rows
    for (int j = 0; j < board->size - 1; j++) {
      if (board->board[i][j] == player && board->board[i][j + 1] == player && board->board[i][j + 2] == player) {
        return 1;
      }
    }

    // Check columns
    for (int j = 0; j < board->size - 1; j++) {
      if (board->board[j][0] == player && board->board[j][1] == player && board->board[j][2] == player) {
        return 1;
      }
    }

    // Check diagonals
    if (board->board[0][0] == player && board->board[1][1] == player && board->board[2][2] == player) {
      return 1;
    }

    if (board->board[0][2] == player && board->board[1][1] == player && board->board[2][0] == player) {
      return 1;
    }
  }

  return 0;
}

int main() {
  Board *board = initBoard(MAX_BOARD_SIZE);

  // Play the game
  move(board, 1, 1);
  move(board, 2, 0);
  move(board, 1, 0);
  move(board, 2, 2);
  move(board, 0, 0);
  move(board, 0, 2);

  // Check if the player won
  if (checkWin(board, board->turn) == 1) {
    printf("Player %d won!", board->turn);
  } else {
    printf("It's a draw!");
  }

  free(board);

  return 0;
}