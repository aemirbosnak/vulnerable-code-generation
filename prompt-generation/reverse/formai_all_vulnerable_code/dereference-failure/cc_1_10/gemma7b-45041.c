//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

struct Node {
  int data;
  struct Node* next;
};

void insertAtTail(struct Node** head, int data)
{
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;

  if (*head == NULL)
  {
    *head = newNode;
  }
  else
  {
    (*head)->next = newNode;
  }
}

void roundRobin(struct Node* head)
{
  struct Node* current = head;
  struct Node* next = NULL;

  while (current)
  {
    next = current->next;
    printf("Processing node with data: %d\n", current->data);
    current->next = head;
    current = next;
  }
}

int main()
{
  struct Node* head = NULL;
  insertAtTail(&head, 10);
  insertAtTail(&head, 20);
  insertAtTail(&head, 30);
  insertAtTail(&head, 40);
  insertAtTail(&head, 50);

  roundRobin(head);

  return 0;
}