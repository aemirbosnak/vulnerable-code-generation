//Gemma-7B DATASET v1.0 Category: Checkers Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 6

typedef struct Piece {
  int row, col, color, direction;
} Piece;

void initBoard(Piece **board) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j].row = i;
      board[i][j].col = j;
      board[i][j].color = 0;
      board[i][j].direction = 0;
    }
  }
}

void placePiece(Piece **board, int row, int col, int color) {
  board[row][col].row = row;
  board[row][col].col = col;
  board[row][col].color = color;
}

void movePiece(Piece **board, int srcRow, int srcCol, int destRow, int destCol) {
  board[destRow][destCol].row = srcRow;
  board[destRow][destCol].col = srcCol;
  board[srcRow][srcCol].row = -1;
  board[srcRow][srcCol].col = -1;
}

int main() {
  Piece **board = (Piece **)malloc(BOARD_SIZE * sizeof(Piece *));
  for (int i = 0; i < BOARD_SIZE; i++) {
    board[i] = (Piece *)malloc(BOARD_SIZE * sizeof(Piece));
  }

  initBoard(board);

  placePiece(board, 0, 0, 1);
  placePiece(board, 1, 0, 1);
  placePiece(board, 2, 0, 1);
  placePiece(board, 3, 0, 1);
  placePiece(board, 4, 0, 1);

  movePiece(board, 0, 0, 2, 0);

  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%d ", board[i][j].color);
    }
    printf("\n");
  }

  free(board);

  return 0;
}