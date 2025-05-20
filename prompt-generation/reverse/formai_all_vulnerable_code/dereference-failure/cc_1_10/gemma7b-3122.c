//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct node {
  int data;
  struct node* next;
} node;

void display(node* head)
{
  node* current = head;
  while(current)
  {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

void insert(node** head, int data)
{
  node* new_node = malloc(sizeof(node));
  new_node->data = data;
  new_node->next = NULL;

  if(*head == NULL)
  {
    *head = new_node;
  }
  else
  {
    (*head)->next = new_node;
  }
}

int main()
{
  node* head = NULL;

  insert(&head, 10);
  insert(&head, 20);
  insert(&head, 30);
  insert(&head, 40);

  display(head);

  return 0;
}