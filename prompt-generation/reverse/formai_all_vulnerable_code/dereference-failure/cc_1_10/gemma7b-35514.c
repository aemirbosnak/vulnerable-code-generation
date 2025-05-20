//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: surprised
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
  int data;
  struct Node* next;
} Node;

Node* newNode(int data) {
  Node* node = malloc(sizeof(struct Node));
  node->data = data;
  node->next = NULL;
  return node;
}

void printBoard(Node* board) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%d ", board->data);
      board = board->next;
    }
    printf("\n");
  }
}

int main() {
  srand(time(NULL));
  Node* board = newNode(0);
  board->next = newNode(1);
  board->next->next = newNode(2);
  board->next->next->next = newNode(3);
  board->next->next->next->next = newNode(4);

  printBoard(board);

  int move = rand() % 9;

  switch (move) {
    case 0:
      board->data = 5;
      break;
    case 1:
      board->next->data = 5;
      break;
    case 2:
      board->next->next->data = 5;
      break;
    case 3:
      board->next->next->next->data = 5;
      break;
    case 4:
      board->next->next->next->next->data = 5;
      break;
  }

  printBoard(board);

  return 0;
}