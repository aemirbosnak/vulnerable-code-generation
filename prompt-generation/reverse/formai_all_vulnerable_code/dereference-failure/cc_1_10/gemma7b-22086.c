//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
  int row;
  int col;
  struct Node* next;
} Node;

struct Node* insertNode(struct Node* head, int row, int col) {
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->row = row;
  newNode->col = col;
  newNode->next = head;
  head = newNode;
  return head;
}

int isBoardFull(struct Node* head) {
  while (head) {
    if (head->row == BOARD_SIZE - 1) {
      return 1;
    }
    head = head->next;
  }
  return 0;
}

int main() {
  struct Node* head = NULL;
  head = insertNode(head, 0, 0);
  head = insertNode(head, 0, 1);
  head = insertNode(head, 0, 2);
  head = insertNode(head, 1, 0);
  head = insertNode(head, 1, 1);
  head = insertNode(head, 1, 2);
  head = insertNode(head, 2, 0);
  head = insertNode(head, 2, 1);
  head = insertNode(head, 2, 2);

  if (isBoardFull(head) == 1) {
    printf("The board is full.");
  } else {
    printf("The board is not full.");
  }

  return 0;
}