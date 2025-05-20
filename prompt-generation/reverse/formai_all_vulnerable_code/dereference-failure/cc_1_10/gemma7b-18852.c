//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

Node* CreateNode(int x, int y) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->x = x;
  node->y = y;
  node->next = NULL;
  return node;
}

int IsBoardFull(Node* head) {
  while (head) {
    if (head->x == BOARD_SIZE - 1 && head->y == BOARD_SIZE - 1) {
      return 1;
    }
    head = head->next;
  }
  return 0;
}

int RandomMove(Node* head) {
  int r = rand() % 2;
  if (r == 0) {
    return head->x + 1;
  } else {
    return head->y + 1;
  }
}

int main() {
  srand(time(NULL));

  Node* head = CreateNode(0, 0);
  head->next = CreateNode(1, 0);
  head->next->next = CreateNode(2, 0);
  head->next->next->next = CreateNode(0, 1);
  head->next->next->next->next = CreateNode(1, 1);
  head->next->next->next->next->next = CreateNode(2, 1);
  head->next->next->next->next->next->next = CreateNode(0, 2);
  head->next->next->next->next->next->next->next = CreateNode(1, 2);
  head->next->next->next->next->next->next->next->next = CreateNode(2, 2);

  while (!IsBoardFull(head)) {
    int move = RandomMove(head);
    printf("Move: %d, %d\n", move, move);
  }

  printf("Game Over!\n");

  return 0;
}