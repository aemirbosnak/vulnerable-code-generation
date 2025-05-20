//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
  int row;
  int col;
  struct Node* next;
} Node;

void initializeBoard(Node** board) {
  *board = NULL;
  for (int r = 0; r < BOARD_SIZE; r++) {
    for (int c = 0; c < BOARD_SIZE; c++) {
      Node* newNode = malloc(sizeof(Node));
      newNode->row = r;
      newNode->col = c;
      newNode->next = NULL;
      *board = newNode;
      board = &newNode->next;
    }
  }
}

int isMoveValid(Node* board, int row, int col) {
  if (board == NULL) {
    return 0;
  }
  for (Node* current = board; current; current = current->next) {
    if (current->row == row && current->col == col) {
      return 0;
    }
  }
  return 1;
}

int makeMove(Node** board, int row, int col, int player) {
  if (!isMoveValid(*board, row, col)) {
    return -1;
  }

  Node* newNode = malloc(sizeof(Node));
  newNode->row = row;
  newNode->col = col;
  newNode->next = NULL;

  *board = newNode;
  board = &newNode->next;

  return 0;
}

int main() {
  Node* board;
  initializeBoard(&board);

  int player = 1;
  while (!board) {
    int row, col;
    printf("Enter row: ");
    scanf("%d", &row);
    printf("Enter column: ");
    scanf("%d", &col);

    makeMove(&board, row, col, player);

    player = (player == 1) ? 2 : 1;
  }

  printf("Game over!");

  return 0;
}