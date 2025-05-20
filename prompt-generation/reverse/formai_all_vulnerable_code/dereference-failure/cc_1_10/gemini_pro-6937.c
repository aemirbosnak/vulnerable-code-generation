//GEMINI-pro DATASET v1.0 Category: Chess engine ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8
#define PIECES 6

typedef struct {
  int x, y;
} Position;

typedef struct {
  char type;
  int color;
  Position position;
} Piece;

typedef struct {
  Piece pieces[PIECES];
  int active_color;
} Board;

void init_board(Board *board) {
  for (int i = 0; i < PIECES; i++) {
    board->pieces[i].type = 'p';
    board->pieces[i].color = 1;
    board->pieces[i].position.x = i;
    board->pieces[i].position.y = 1;
  }
  for (int i = 0; i < PIECES; i++) {
    board->pieces[i + PIECES].type = 'p';
    board->pieces[i + PIECES].color = 2;
    board->pieces[i + PIECES].position.x = i;
    board->pieces[i + PIECES].position.y = 6;
  }
  board->pieces[0].type = 'r';
  board->pieces[7].type = 'r';
  board->pieces[1].type = 'n';
  board->pieces[6].type = 'n';
  board->pieces[2].type = 'b';
  board->pieces[5].type = 'b';
  board->pieces[3].type = 'q';
  board->pieces[4].type = 'k';
  board->active_color = 1;
}

void print_board(Board *board) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      Piece piece = board->pieces[i * BOARD_SIZE + j];
      if (piece.type == ' ') {
        printf("  ");
      } else {
        printf("%c%d", piece.type, piece.color);
      }
    }
    printf("\n");
  }
}

int main() {
  Board board;
  init_board(&board);
  print_board(&board);
  return 0;
}