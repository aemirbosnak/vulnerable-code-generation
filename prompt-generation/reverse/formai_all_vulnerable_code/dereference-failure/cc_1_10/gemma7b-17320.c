//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLOR 5

typedef struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
} Node;

void insertAtTail(Node* head, int data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->prev = newNode;
    newNode->prev = head;
    head = newNode;
  }
}

void graphColoring(Node* head) {
  int colors[MAX_COLOR] = {0};
  Node* current = head;
  while (current) {
    int color = colors[current->data];
    if (color == 0) {
      color = random() % MAX_COLOR;
      colors[current->data] = color;
    }
    current = current->next;
  }

  for (current = head; current; current) {
    printf("Node %d colored with %d\n", current->data, colors[current->data]);
  }
}

int main() {
  Node* head = NULL;
  insertAtTail(head, 0);
  insertAtTail(head, 1);
  insertAtTail(head, 2);
  insertAtTail(head, 3);
  insertAtTail(head, 4);

  graphColoring(head);

  return 0;
}