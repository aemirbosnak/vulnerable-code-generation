//Gemma-7B DATASET v1.0 Category: Memory management ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_ALLOC 10

typedef struct Node {
  struct Node* next;
  int data;
} Node;

Node* head = NULL;

void* alloc(int size)
{
  if (head == NULL)
  {
    head = malloc(sizeof(Node));
    head->next = NULL;
    head->data = 0;
  }

  Node* newNode = malloc(size);
  newNode->next = head->next;
  head->next = newNode;

  return (void*) newNode;
}

void free(void* ptr)
{
  Node* node = head;

  while (node)
  {
    if (node->next == ptr)
    {
      free(node);
      node = node->next;
    }
  }

  return;
}

int main()
{
  alloc(10);
  alloc(20);
  alloc(30);

  free(alloc(40));

  return 0;
}