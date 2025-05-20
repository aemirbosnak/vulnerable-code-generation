//Falcon-180B DATASET v1.0 Category: Educational ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int data;
  struct node* next;
} Node;

Node* createNode(int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void addNodeAtEnd(Node** head, int data) {
  Node* newNode = createNode(data);
  Node* temp = *head;

  if (*head == NULL) {
    newNode->next = NULL;
    *head = newNode;
    return;
  }

  while (temp->next!= NULL) {
    temp = temp->next;
  }
  temp->next = newNode;
}

void addNodeAtBeginning(Node** head, int data) {
  Node* newNode = createNode(data);

  if (*head == NULL) {
    newNode->next = NULL;
    *head = newNode;
    return;
  }

  newNode->next = *head;
  *head = newNode;
}

void deleteNode(Node** head, int data) {
  Node* temp = *head;
  Node* prev;

  if (temp!= NULL && temp->data == data) {
    *head = temp->next;
    free(temp);
    return;
  }

  while (temp!= NULL && temp->data!= data) {
    prev = temp;
    temp = temp->next;
  }

  if (temp == NULL) {
    return;
  }

  prev->next = temp->next;
  free(temp);
}

void printList(Node* head) {
  Node* temp = head;

  while (temp!= NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
}

int main() {
  Node* head = NULL;

  addNodeAtEnd(&head, 10);
  addNodeAtBeginning(&head, 20);
  addNodeAtEnd(&head, 30);
  addNodeAtBeginning(&head, 40);

  printf("Original List: ");
  printList(head);

  deleteNode(&head, 20);
  printf("\nList after deleting 20: ");
  printList(head);

  deleteNode(&head, 10);
  printf("\nList after deleting 10: ");
  printList(head);

  deleteNode(&head, 30);
  printf("\nList after deleting 30: ");
  printList(head);

  deleteNode(&head, 40);
  printf("\nList after deleting 40: ");
  printList(head);

  return 0;
}