//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

void insert(Node** head, int x, int y) {
  Node* newNode = malloc(sizeof(Node));
  newNode->x = x;
  newNode->y = y;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
    *head = newNode;
  }
}

void draw(Node* head) {
  while (head) {
    printf("(");
    printf("%d, %d)", head->x, head->y);
    printf(")\n");
    head = head->next;
  }
}

int main() {
  Node* head = NULL;

  // Multiplayer code
  // Client connects to server
  // Server sends list of nodes to client
  // Client draws the nodes

  insert(head, 10, 10);
  insert(head, 20, 20);
  insert(head, 30, 30);
  insert(head, 40, 40);

  draw(head);

  return 0;
}