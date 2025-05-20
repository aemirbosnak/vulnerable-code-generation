//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: thoughtful
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
  int x;
  int y;
  struct Node* next;
} Node;

Node* createNode(int x, int y) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->x = x;
  node->y = y;
  node->next = NULL;
  return node;
}

void printBoard(Node* head) {
  for (Node* node = head; node; node = node->next) {
    printf("%d ", node->x);
  }
  printf("\n");
  for (Node* node = head; node; node = node->next) {
    printf("%d ", node->y);
  }
  printf("\n");
}

int isMoveValid(Node* head, int x, int y) {
  for (Node* node = head; node; node = node->next) {
    if (node->x == x && node->y == y) {
      return 0;
    }
  }
  return 1;
}

int main() {
  Node* head = createNode(0, 0);
  head->next = createNode(1, 0);
  head->next->next = createNode(2, 0);
  head->next->next->next = createNode(0, 1);
  head->next->next->next->next = createNode(1, 1);
  head->next->next->next->next->next = createNode(2, 1);
  head->next->next->next->next->next->next = createNode(0, 2);
  head->next->next->next->next->next->next->next = createNode(1, 2);
  head->next->next->next->next->next->next->next->next = createNode(2, 2);

  printBoard(head);

  int x = 1;
  int y = 1;

  while (isMoveValid(head, x, y)) {
    Node* newNode = createNode(x, y);
    newNode->next = head;
    head = newNode;

    printBoard(head);
    x++;
    y++;
  }

  return 0;
}