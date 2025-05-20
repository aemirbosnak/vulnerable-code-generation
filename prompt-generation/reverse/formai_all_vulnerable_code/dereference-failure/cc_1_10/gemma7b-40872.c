//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
};

struct Circle {
  struct Node* head;
  struct Node* tail;
  int size;
};

void InsertAtTail(struct Circle* circle, int data) {
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  newNode->prev = NULL;

  if (circle->head == NULL) {
    circle->head = newNode;
    circle->tail = newNode;
  } else {
    circle->tail->next = newNode;
    circle->tail = newNode;
  }
  circle->size++;
}

void PrintCircle(struct Circle* circle) {
  struct Node* current = circle->head;
  while (current) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

int main() {
  struct Circle* circle = malloc(sizeof(struct Circle));
  circle->head = NULL;
  circle->tail = NULL;
  circle->size = 0;

  InsertAtTail(circle, 10);
  InsertAtTail(circle, 20);
  InsertAtTail(circle, 30);
  InsertAtTail(circle, 40);

  PrintCircle(circle);

  return 0;
}