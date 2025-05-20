//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOARD_SIZE 3

typedef struct Node {
  int x;
  int y;
  struct Node* next;
} Node;

Node* createNode(int x, int y) {
  Node* newNode = malloc(sizeof(Node));
  newNode->x = x;
  newNode->y = y;
  newNode->next = NULL;
  return newNode;
}

void printBoard(Node* head) {
  while (head) {
    printf("%c ", head->x + 'a' - 1, head->y + 1);
    head = head->next;
  }
  printf("\n");
}

int isMoveValid(Node* head, int x, int y) {
  if (x < 0 || x >= MAX_BOARD_SIZE || y < 0 || y >= MAX_BOARD_SIZE) {
    return 0;
  }

  for (head = head; head; head = head->next) {
    if (head->x == x && head->y == y) {
      return 0;
    }
  }

  return 1;
}

int main() {
  Node* board = NULL;
  board = createNode(0, 0);
  board = createNode(1, 0);
  board = createNode(2, 0);
  board = createNode(0, 1);
  board = createNode(1, 1);
  board = createNode(2, 1);
  board = createNode(0, 2);
  board = createNode(1, 2);
  board = createNode(2, 2);

  printBoard(board);

  if (isMoveValid(board, 0, 3)) {
    printf("Move is valid\n");
  } else {
    printf("Move is not valid\n");
  }

  return 0;
}