//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
  int row, col;
  struct Node* next;
} Node;

Node* createNode(int row, int col) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->row = row;
  node->col = col;
  node->next = NULL;
  return node;
}

void insertNode(Node* head, int row, int col) {
  Node* newNode = createNode(row, col);
  if (head == NULL) {
    head = newNode;
  } else {
    Node* current = head;
    while (current->next) {
      current = current->next;
    }
    current->next = newNode;
  }
}

int getMove(Node* head) {
  srand(time(NULL));
  int move = rand() % BOARD_SIZE;
  while (head->row == move || head->col == move) {
    move = rand() % BOARD_SIZE;
  }
  return move;
}

int main() {
  Node* head = NULL;
  insertNode(head, 1, 2);
  insertNode(head, 2, 1);
  insertNode(head, 0, 0);
  insertNode(head, 2, 2);

  int move = getMove(head);
  printf("Move: %d", move);

  return 0;
}