//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

Node* insert_node(Node* head, int x, int y) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->x = x;
  newNode->y = y;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  return head;
}

int move_ai(Node* head) {
  time_t t = time(NULL);
  srand(t);

  int move_x = rand() % BOARD_SIZE;
  int move_y = rand() % BOARD_SIZE;

  while (head->x == move_x && head->y == move_y) {
    move_x = rand() % BOARD_SIZE;
    move_y = rand() % BOARD_SIZE;
  }

  return move_x;
}

int main() {
  Node* head = NULL;

  // Simulate game logic
  for (int i = 0; i < 10; i++) {
    int move_x = move_ai(head);
    int move_y = 1; // Hardcoded for example, should be from the AI

    insert_node(head, move_x, move_y);
  }

  return 0;
}