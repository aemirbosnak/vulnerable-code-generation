//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MOVES 10

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

void printBoard(Node* head) {
  for (Node* current = head; current; current = current->next) {
    printf("(%d, %d) ", current->x, current->y);
  }
  printf("\n");
}

int main() {
  srand(time(NULL));
  int moves = 0;
  Node* head = createNode(0, 0);
  head->next = createNode(1, 0);
  head->next->next = createNode(2, 0);
  head->next->next->next = createNode(3, 0);

  printBoard(head);

  while (moves < MAX_MOVES) {
    int x = rand() % 4;
    int y = rand() % 4;
    Node* newNode = createNode(x, y);

    if (newNode->x == head->x && newNode->y == head->y) {
      // Game Over
      break;
    }

    newNode->next = head;
    head = newNode;

    printBoard(head);
    moves++;
  }

  printf("Game Over!\n");
  return 0;
}