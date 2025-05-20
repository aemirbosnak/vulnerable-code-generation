//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: intelligent
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

Node* createNode(int x, int y) {
  Node* newNode = malloc(sizeof(Node));
  newNode->x = x;
  newNode->y = y;
  newNode->next = NULL;
  return newNode;
}

void insertNode(Node* head, int x, int y) {
  Node* newNode = createNode(x, y);
  if (head == NULL) {
    head = newNode;
  } else {
    Node* traverse = head;
    while (traverse->next) {
      traverse = traverse->next;
    }
    traverse->next = newNode;
  }
}

int checkWin(Node* head) {
  int win = 0;
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    Node* row = head;
    while (row) {
      if (row->x == i && row->y == 0) {
        win = 1;
      }
    }
  }

  // Check columns
  for (int j = 0; j < BOARD_SIZE; j++) {
    Node* col = head;
    while (col) {
      if (col->x == 0 && col->y == j) {
        win = 1;
      }
    }
  }

  // Check diagonals
  Node* diag = head;
  while (diag) {
    if (diag->x - diag->y == 0) {
      win = 1;
    }
    diag = diag->next;
  }

  return win;
}

int main() {
  Node* board = NULL;
  insertNode(board, 0, 0);
  insertNode(board, 1, 0);
  insertNode(board, 2, 0);
  insertNode(board, 0, 1);
  insertNode(board, 1, 1);
  insertNode(board, 2, 1);
  insertNode(board, 0, 2);
  insertNode(board, 1, 2);
  insertNode(board, 2, 2);

  if (checkWin(board)) {
    printf("Player won!");
  } else {
    printf("Draw!");
  }

  return 0;
}