//Gemma-7B DATASET v1.0 Category: Table Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 5

typedef struct Node {
  int data;
  struct Node* next;
} Node;

void initializeBoard(Node** board) {
  *board = NULL;
  for (int i = 0; i < BOARD_SIZE; i++) {
    *board = malloc(sizeof(Node));
    (*board)->data = 0;
    (*board)->next = NULL;
    board++;
  }
}

void placePiece(Node** board, int piece, int row, int col) {
  Node* current = *board;
  for (int i = 0; i < row; i++) {
    current = current->next;
  }
  current->data = piece;
  current->next = NULL;
}

int getAvailableMoves(Node** board) {
  Node* current = *board;
  int moves = 0;
  for (int i = 0; current; i++) {
    if (current->data == 0) {
      moves++;
    }
    current = current->next;
  }
  return moves;
}

int main() {
  Node** board = NULL;
  initializeBoard(&board);

  placePiece(board, 1, 0, 0);
  placePiece(board, 2, 1, 1);
  placePiece(board, 1, 2, 2);

  int availableMoves = getAvailableMoves(board);

  printf("Number of available moves: %d", availableMoves);

  return 0;
}