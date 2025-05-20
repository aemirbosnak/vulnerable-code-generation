//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE 20
#define PLAYER_SIZE 3

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

void drawGrid(Node* head) {
  for (int x = 0; x < GRID_SIZE; x++) {
    for (int y = 0; y < GRID_SIZE; y++) {
      Node* current = head;
      while (current) {
        if (current->x == x && current->y == y) {
          printf("* ");
        } else {
          printf("  ");
        }
      }
    }
    printf("\n");
  }
}

void moveRight(Node* head) {
  head->x++;
}

void moveLeft(Node* head) {
  head->x--;
}

void moveDown(Node* head) {
  head->y++;
}

int main() {
  Node* head = createNode(0, 0);
  head->next = createNode(1, 0);
  head->next->next = createNode(2, 0);

  drawGrid(head);

  moveRight(head);
  moveRight(head->next);
  moveRight(head->next->next);

  drawGrid(head);

  moveDown(head);
  moveDown(head->next);
  moveDown(head->next->next);

  drawGrid(head);

  return 0;
}