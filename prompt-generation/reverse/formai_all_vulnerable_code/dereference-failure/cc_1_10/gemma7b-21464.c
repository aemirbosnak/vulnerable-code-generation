//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOARD_SIZE 3

typedef struct Node {
  int x;
  int y;
  struct Node* next;
} Node;

Node* insertNode(Node* head, int x, int y) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->x = x;
  newNode->y = y;
  newNode->next = head;
  return newNode;
}

int isBoardFull(Node* head) {
  while (head) {
    if (head->x == MAX_BOARD_SIZE - 1 && head->y == MAX_BOARD_SIZE - 1) {
      return 1;
    }
    head = head->next;
  }
  return 0;
}

int main() {
  Node* head = NULL;
  head = insertNode(head, 0, 0);
  head = insertNode(head, 1, 0);
  head = insertNode(head, 2, 0);
  head = insertNode(head, 0, 1);
  head = insertNode(head, 1, 1);
  head = insertNode(head, 2, 1);
  head = insertNode(head, 0, 2);
  head = insertNode(head, 1, 2);
  head = insertNode(head, 2, 2);

  if (isBoardFull(head)) {
    printf("The board is full.");
  } else {
    printf("The board is not full.");
  }

  return 0;
}