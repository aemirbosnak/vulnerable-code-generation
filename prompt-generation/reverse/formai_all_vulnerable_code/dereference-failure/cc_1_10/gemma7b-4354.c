//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: medieval
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

void initializeBoard(Node** board) {
  *board = NULL;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      Node* newNode = malloc(sizeof(Node));
      newNode->x = i;
      newNode->y = j;
      newNode->next = NULL;
      *board = newNode;
      board = &((*board)->next);
    }
  }
}

int isBoardFull(Node* board) {
  for (Node* current = board; current; current = current->next) {
    if (current->x == -1) {
      return 0;
    }
  }
  return 1;
}

int main() {
  Node** board = NULL;
  initializeBoard(board);

  // Simulate moves
  board[0]->x = 0;
  board[0]->y = 1;

  board[2]->x = 2;
  board[2]->y = 0;

  if (isBoardFull(board) == 1) {
    printf("The board is full.");
  } else {
    printf("The board is not full.");
  }

  return 0;
}