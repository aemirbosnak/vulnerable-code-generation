//GEMINI-pro DATASET v1.0 Category: Educational ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
  int data;
  struct node *next;
} node;

void insert_at_beginning(node **head, int data)
{
  node *new_node = (node *)malloc(sizeof(node));
  new_node->data = data;
  new_node->next = *head;
  *head = new_node;
}

void insert_at_end(node **head, int data)
{
  node *new_node = (node *)malloc(sizeof(node));
  new_node->data = data;
  new_node->next = NULL;
  if (*head == NULL)
  {
    *head = new_node;
    return;
  }
  node *temp = *head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = new_node;
}

void insert_at_position(node **head, int data, int position)
{
  node *new_node = (node *)malloc(sizeof(node));
  new_node->data = data;
  if (position == 1)
  {
    new_node->next = *head;
    *head = new_node;
    return;
  }
  node *temp = *head;
  for (int i = 1; i < position - 1; i++)
  {
    if (temp == NULL)
    {
      printf("Invalid position\n");
      return;
    }
    temp = temp->next;
  }
  new_node->next = temp->next;
  temp->next = new_node;
}

void delete_at_beginning(node **head)
{
  if (*head == NULL)
  {
    printf("List is empty\n");
    return;
  }
  node *temp = *head;
  *head = (*head)->next;
  free(temp);
}

void delete_at_end(node **head)
{
  if (*head == NULL)
  {
    printf("List is empty\n");
    return;
  }
  if ((*head)->next == NULL)
  {
    free(*head);
    *head = NULL;
    return;
  }
  node *temp = *head;
  while (temp->next->next != NULL)
  {
    temp = temp->next;
  }
  free(temp->next);
  temp->next = NULL;
}

void delete_at_position(node **head, int position)
{
  if (*head == NULL)
  {
    printf("List is empty\n");
    return;
  }
  if (position == 1)
  {
    node *temp = *head;
    *head = (*head)->next;
    free(temp);
    return;
  }
  node *temp = *head;
  for (int i = 1; i < position - 1; i++)
  {
    if (temp == NULL)
    {
      printf("Invalid position\n");
      return;
    }
    temp = temp->next;
  }
  if (temp->next == NULL)
  {
    printf("Invalid position\n");
    return;
  }
  node *temp2 = temp->next;
  temp->next = temp2->next;
  free(temp2);
}

void print_list(node *head)
{
  node *temp = head;
  while (temp != NULL)
  {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main()
{
  node *head = NULL;
  insert_at_beginning(&head, 1);
  insert_at_end(&head, 2);
  insert_at_end(&head, 3);
  insert_at_position(&head, 4, 2);
  print_list(head);
  delete_at_beginning(&head);
  delete_at_end(&head);
  delete_at_position(&head, 2);
  print_list(head);
  return 0;
}