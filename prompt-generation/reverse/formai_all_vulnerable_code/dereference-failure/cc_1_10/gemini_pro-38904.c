//GEMINI-pro DATASET v1.0 Category: Chess engine ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8
#define NUM_PIECES 6

typedef struct {
  int x;
  int y;
} Position;

typedef enum {
  PAWN,
  ROOK,
  KNIGHT,
  BISHOP,
  QUEEN,
  KING
} PieceType;

typedef struct {
  PieceType type;
  Position position;
} Piece;

typedef struct {
  Piece pieces[NUM_PIECES];
} Board;

void init_board(Board *board) {
  // Initialize the pawns
  for (int i = 0; i < BOARD_SIZE; i++) {
    board->pieces[i].type = PAWN;
    board->pieces[i].position.x = i;
    board->pieces[i].position.y = 1;
  }

  // Initialize the rooks
  board->pieces[8].type = ROOK;
  board->pieces[8].position.x = 0;
  board->pieces[8].position.y = 0;
  board->pieces[9].type = ROOK;
  board->pieces[9].position.x = 7;
  board->pieces[9].position.y = 0;

  // Initialize the knights
  board->pieces[10].type = KNIGHT;
  board->pieces[10].position.x = 1;
  board->pieces[10].position.y = 0;
  board->pieces[11].type = KNIGHT;
  board->pieces[11].position.x = 6;
  board->pieces[11].position.y = 0;

  // Initialize the bishops
  board->pieces[12].type = BISHOP;
  board->pieces[12].position.x = 2;
  board->pieces[12].position.y = 0;
  board->pieces[13].type = BISHOP;
  board->pieces[13].position.x = 5;
  board->pieces[13].position.y = 0;

  // Initialize the queen
  board->pieces[14].type = QUEEN;
  board->pieces[14].position.x = 3;
  board->pieces[14].position.y = 0;

  // Initialize the king
  board->pieces[15].type = KING;
  board->pieces[15].position.x = 4;
  board->pieces[15].position.y = 0;
}

void print_board(Board *board) {
  for (int y = 0; y < BOARD_SIZE; y++) {
    for (int x = 0; x < BOARD_SIZE; x++) {
      Piece *piece = &board->pieces[y * BOARD_SIZE + x];
      switch (piece->type) {
        case PAWN:
          printf("P");
          break;
        case ROOK:
          printf("R");
          break;
        case KNIGHT:
          printf("N");
          break;
        case BISHOP:
          printf("B");
          break;
        case QUEEN:
          printf("Q");
          break;
        case KING:
          printf("K");
          break;
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