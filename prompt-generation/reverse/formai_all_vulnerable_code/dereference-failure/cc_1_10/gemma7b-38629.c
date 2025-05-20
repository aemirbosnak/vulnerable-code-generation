//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Knight {
  char name[20];
  int position;
  struct Knight *next;
} Knight;

Knight *insert_at_tail(Knight *head)
{
  Knight *new_knight = (Knight *)malloc(sizeof(Knight));
  new_knight->position = MAX_SIZE - 1;
  new_knight->next = NULL;

  if (head == NULL)
  {
    head = new_knight;
  }
  else
  {
    head->next = new_knight;
  }

  return head;
}

Knight *remove_from_head(Knight *head)
{
  Knight *temp = head;
  head = head->next;
  free(temp);

  return head;
}

int main()
{
  Knight *head = NULL;
  head = insert_at_tail(head);
  insert_at_tail(head);
  insert_at_tail(head);

  head = remove_from_head(head);
  insert_at_tail(head);

  return 0;
}