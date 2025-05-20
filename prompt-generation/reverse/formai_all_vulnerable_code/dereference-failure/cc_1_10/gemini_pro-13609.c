//GEMINI-pro DATASET v1.0 Category: Chess engine ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8

typedef struct {
  int x;
  int y;
} Position;

typedef struct {
  char type;
  Position position;
} Piece;

typedef struct {
  Piece pieces[16];
} Board;

void print_board(Board *board) {
  for (int y = 0; y < BOARD_SIZE; y++) {
    for (int x = 0; x < BOARD_SIZE; x++) {
      Piece piece = board->pieces[y * BOARD_SIZE + x];
      printf("%c", piece.type);
    }
    printf("\n");
  }
}

int main() {
  Board board;

  // Initialize the board with the starting position.
  for (int y = 0; y < BOARD_SIZE; y++) {
    for (int x = 0; x < BOARD_SIZE; x++) {
      Piece piece;
      piece.position.x = x;
      piece.position.y = y;

      if (y == 1 || y == 6) {
        piece.type = 'p';
      } else if (y == 0 || y == 7) {
        if (x == 0 || x == 7) {
          piece.type = 'r';
        } else if (x == 1 || x == 6) {
          piece.type = 'n';
        } else if (x == 2 || x == 5) {
          piece.type = 'b';
        } else if (x == 3) {
          piece.type = 'q';
        } else if (x == 4) {
          piece.type = 'k';
        }
      } else {
        piece.type = ' ';
      }

      board.pieces[y * BOARD_SIZE + x] = piece;
    }
  }

  // Print the board.
  print_board(&board);

  return 0;
}