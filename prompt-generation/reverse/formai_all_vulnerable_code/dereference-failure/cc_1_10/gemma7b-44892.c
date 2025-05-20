//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct Node {
  int data;
  struct Node* next;
} Node;

void insertRear(Node* head, int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }
}

int deleteFront(Node* head) {
  if (head == NULL) {
    return -1;
  }

  Node* temp = head;
  head = head->next;
  free(temp);

  return 0;
}

int main() {
  Node* head = NULL;

  insertRear(head, 10);
  insertRear(head, 20);
  insertRear(head, 30);
  insertRear(head, 40);
  insertRear(head, 50);

  deleteFront(head);
  deleteFront(head);

  printf("Data at the front: %d", head->data);

  return 0;
}