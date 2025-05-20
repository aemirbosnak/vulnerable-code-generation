//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct item
{
  char name[20];
  int value;
  struct item* next;
} item;

void traverse(item* head)
{
  item* current = head;
  while (current)
  {
    printf("%s (Value: %d) ", current->name, current->value);
    current = current->next;
  }
}

int main()
{
  item* head = NULL;
  item* tail = NULL;

  // Create a few items
  for (int i = 0; i < MAX_ITEMS; i++)
  {
    item* new_item = (item*)malloc(sizeof(item));
    strcpy(new_item->name, "Item #");
    new_item->value = rand() % 101;
    new_item->next = NULL;

    if (head == NULL)
    {
      head = new_item;
      tail = new_item;
    }
    else
    {
      tail->next = new_item;
      tail = new_item;
    }
  }

  // Traverse the items
  traverse(head);

  return 0;
}