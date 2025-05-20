//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

Node* createNode(int x, int y) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->x = x;
  newNode->y = y;
  newNode->next = NULL;
  return newNode;
}

void playTicTacToe() {
  Node* head = createNode(0, 0);
  head->next = createNode(1, 0);
  head->next->next = createNode(2, 0);
  head->next->next->next = createNode(0, 1);
  head->next->next->next->next = createNode(1, 1);
  head->next->next->next->next->next = createNode(2, 1);
  head->next->next->next->next->next->next = createNode(0, 2);
  head->next->next->next->next->next->next->next = createNode(1, 2);
  head->next->next->next->next->next->next->next->next = createNode(2, 2);

  srand(time(NULL));
  int move = rand() % BOARD_SIZE * BOARD_SIZE;

  switch (move) {
    case 0:
      head->x = 0;
      head->y = 0;
      break;
    case 1:
      head->x = 1;
      head->y = 0;
      break;
    case 2:
      head->x = 2;
      head->y = 0;
      break;
    case 3:
      head->x = 0;
      head->y = 1;
      break;
    case 4:
      head->x = 1;
      head->y = 1;
      break;
    case 5:
      head->x = 2;
      head->y = 1;
      break;
    case 6:
      head->x = 0;
      head->y = 2;
      break;
    case 7:
      head->x = 1;
      head->y = 2;
      break;
    case 8:
      head->x = 2;
      head->y = 2;
      break;
  }

  printf("Move: (%d, %d)\n", head->x, head->y);
}

int main() {
  playTicTacToe();
  return 0;
}