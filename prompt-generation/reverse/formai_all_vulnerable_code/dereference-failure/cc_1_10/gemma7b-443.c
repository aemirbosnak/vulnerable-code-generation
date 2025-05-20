//Gemma-7B DATASET v1.0 Category: Memory management ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALLOC 1024

typedef struct Node {
  struct Node* next;
  char* data;
} Node;

Node* AllocateNode(int size)
{
  Node* newNode = NULL;

  if (size <= MAX_ALLOC)
  {
    newNode = malloc(sizeof(Node) + size);
    if (newNode)
    {
      newNode->next = NULL;
      newNode->data = (char*)newNode + sizeof(Node);
      return newNode;
    }
  }

  return NULL;
}

void FreeNode(Node* node)
{
  free(node);
}

int main()
{
  Node* head = NULL;
  Node* tail = NULL;

  // Allocate and insert first node
  tail = AllocateNode(10);
  head = tail;
  tail->data = "Cyberpunk City";

  // Allocate and insert second node
  tail = AllocateNode(20);
  tail->data = "The Matrix";

  // Print data of nodes
  printf("Data of first node: %s\n", head->data);
  printf("Data of second node: %s\n", tail->data);

  // Free nodes
  FreeNode(head);
  FreeNode(tail);

  return 0;
}