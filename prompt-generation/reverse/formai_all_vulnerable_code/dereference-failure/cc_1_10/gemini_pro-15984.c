//GEMINI-pro DATASET v1.0 Category: Chess engine ; Style: minimalist
#include <stdio.h>
#include <string.h>

typedef struct {
  int x, y;
} Point;

typedef struct {
  char type;
  Point pos;
} Piece;

typedef struct {
  Piece pieces[32];
  int turn;
} Board;

void printBoard(Board* board) {
  for (int y = 7; y >= 0; y--) {
    for (int x = 0; x < 8; x++) {
      Piece* piece = &board->pieces[y * 8 + x];
      printf("%c", piece->type);
    }
    printf("\n");
  }
}

int main() {
  Board board;
  memset(&board, 0, sizeof(Board));
  board.pieces[0].type = 'R';
  board.pieces[0].pos.x = 0;
  board.pieces[0].pos.y = 0;
  board.pieces[1].type = 'N';
  board.pieces[1].pos.x = 1;
  board.pieces[1].pos.y = 0;
  board.pieces[2].type = 'B';
  board.pieces[2].pos.x = 2;
  board.pieces[2].pos.y = 0;
  board.pieces[3].type = 'Q';
  board.pieces[3].pos.x = 3;
  board.pieces[3].pos.y = 0;
  board.pieces[4].type = 'K';
  board.pieces[4].pos.x = 4;
  board.pieces[4].pos.y = 0;
  board.pieces[5].type = 'B';
  board.pieces[5].pos.x = 5;
  board.pieces[5].pos.y = 0;
  board.pieces[6].type = 'N';
  board.pieces[6].pos.x = 6;
  board.pieces[6].pos.y = 0;
  board.pieces[7].type = 'R';
  board.pieces[7].pos.x = 7;
  board.pieces[7].pos.y = 0;
  for (int i = 0; i < 8; i++) {
    board.pieces[8 + i].type = 'P';
    board.pieces[8 + i].pos.x = i;
    board.pieces[8 + i].pos.y = 1;
    board.pieces[16 + i].type = 'p';
    board.pieces[16 + i].pos.x = i;
    board.pieces[16 + i].pos.y = 6;
  }
  printBoard(&board);
  return 0;
}