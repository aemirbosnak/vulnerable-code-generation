//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

void insertNode(Node** head, int x, int y) {
  Node* newNode = malloc(sizeof(Node));
  newNode->x = x;
  newNode->y = y;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

void drawLine(Node* head) {
  while (head) {
    printf("(");
    printf("%d, %d)", head->x, head->y);
    printf("),");
    head = head->next;
  }

  printf("\n");
}

int main() {
  Node* head = NULL;

  insertNode(&head, 0, 0);
  insertNode(&head, 5, 0);
  insertNode(&head, 10, 0);
  insertNode(&head, 15, 0);
  insertNode(&head, 20, 0);

  insertNode(&head, 0, 5);
  insertNode(&head, 5, 5);
  insertNode(&head, 10, 5);
  insertNode(&head, 15, 5);
  insertNode(&head, 20, 5);

  drawLine(head);

  return 0;
}