//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct node {
  int data;
  struct node* next;
} node;

void insertAtTail(node* head, int data) {
  node* newNode = (node*)malloc(sizeof(node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }
}

void graphColoring(node* head) {
  int colors[MAX] = {0};
  int currentColor = 0;

  while (head) {
    int nodeColor = colors[head->data];
    if (nodeColor == 0) {
      colors[head->data] = currentColor;
      currentColor++;
    }
    head = head->next;
  }

  printf("The number of colors used is: %d\n", currentColor);
}

int main() {
  node* head = NULL;
  insertAtTail(head, 1);
  insertAtTail(head, 2);
  insertAtTail(head, 3);
  insertAtTail(head, 4);
  insertAtTail(head, 5);

  graphColoring(head);

  return 0;
}