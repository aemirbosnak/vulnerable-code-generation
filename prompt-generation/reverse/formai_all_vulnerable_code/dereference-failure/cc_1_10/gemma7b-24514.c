//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

struct Node {
  int data;
  struct Node* next;
};

void insert(struct Node** head, int data)
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

void schedule(struct Node** head)
{
  struct Node* current = *head;
  srand(time(NULL));

  for (int i = 0; i < MAX; i++)
  {
    int random_time = rand() % 10;
    current->data = random_time;

    current = current->next;
  }

  *head = current;
}

int main()
{
  struct Node* head = NULL;

  insert(&head, 5);
  insert(&head, 10);
  insert(&head, 15);
  insert(&head, 20);

  schedule(&head);

  struct Node* current = head;

  while (current)
  {
    printf("Data: %d, Time: %d\n", current->data, current->data);
    current = current->next;
  }

  return 0;
}