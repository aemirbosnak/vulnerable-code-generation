//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
  int data;
  struct Node* next;
} Node;

void insert_at_rear(Node** head, int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    ((*head)->next = newNode);
    *head = newNode;
  }
}

int delete_from_front(Node** head) {
  if (*head == NULL) {
    return -1;
  }

  Node* temp = *head;
  *head = (*head)->next;
  free(temp);
  return 0;
}

int main() {
  Node* head = NULL;
  insert_at_rear(&head, 10);
  insert_at_rear(&head, 20);
  insert_at_rear(&head, 30);
  insert_at_rear(&head, 40);

  delete_from_front(&head);
  delete_from_front(&head);

  printf("Elements of the queue:\n");
  while (head) {
    printf("%d ", head->data);
    head = head->next;
  }

  return 0;
}