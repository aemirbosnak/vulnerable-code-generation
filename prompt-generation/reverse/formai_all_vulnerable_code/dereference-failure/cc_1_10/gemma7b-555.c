//Gemma-7B DATASET v1.0 Category: Linked list operations ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct Node {
  int data;
  struct Node* next;
};

struct Node* InsertAtTail(struct Node* head, int data)
{
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    struct Node* temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
  }

  return head;
}

struct Node* InsertAtHead(struct Node* head, int data)
{
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    newNode->next = head;
    head = newNode;
  }

  return head;
}

struct Node* DeleteNode(struct Node* head, int data)
{
  struct Node* temp = head;
  struct Node* prev = NULL;

  while (temp && temp->data != data) {
    prev = temp;
    temp = temp->next;
  }

  if (prev) {
    prev->next = temp->next;
  } else {
    head = temp->next;
  }

  free(temp);

  return head;
}

int main()
{
  struct Node* head = NULL;

  InsertAtTail(head, 10);
  InsertAtTail(head, 20);
  InsertAtTail(head, 30);
  InsertAtHead(head, 40);
  DeleteNode(head, 20);

  struct Node* current = head;
  while (current) {
    printf("%d ", current->data);
    current = current->next;
  }

  return 0;
}