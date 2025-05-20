//GEMINI-pro DATASET v1.0 Category: Chess AI ; Style: protected
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
  int num_pieces;
} Side;

typedef struct {
  Side white;
  Side black;
} Board;

void print_board(Board *board) {
  for (int y = 0; y < BOARD_SIZE; y++) {
    for (int x = 0; x < BOARD_SIZE; x++) {
      Piece piece = board->white.pieces[y * BOARD_SIZE + x];
      if (piece.type != ' ') {
        printf("%c", piece.type);
      } else {
        printf(".");
      }
    }
    printf("\n");
  }
}

int main() {
  Board board;

  // Initialize the board.

  for (int i = 0; i < 16; i++) {
    board.white.pieces[i].type = ' ';
    board.black.pieces[i].type = ' ';
  }

  board.white.pieces[0].type = 'R';
  board.white.pieces[1].type = 'N';
  board.white.pieces[2].type = 'B';
  board.white.pieces[3].type = 'Q';
  board.white.pieces[4].type = 'K';
  board.white.pieces[5].type = 'B';
  board.white.pieces[6].type = 'N';
  board.white.pieces[7].type = 'R';

  board.black.pieces[0].type = 'r';
  board.black.pieces[1].type = 'n';
  board.black.pieces[2].type = 'b';
  board.black.pieces[3].type = 'q';
  board.black.pieces[4].type = 'k';
  board.black.pieces[5].type = 'b';
  board.black.pieces[6].type = 'n';
  board.black.pieces[7].type = 'r';

  for (int i = 0; i < 8; i++) {
    board.white.pieces[8 + i].type = 'P';
    board.black.pieces[8 + i].type = 'p';
  }

  // Print the board.

  print_board(&board);

  return 0;
}