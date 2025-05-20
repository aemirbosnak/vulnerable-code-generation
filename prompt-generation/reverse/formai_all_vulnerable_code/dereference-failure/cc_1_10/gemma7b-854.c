//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
  char data;
  struct Node* next;
} Node;

void parse_syntax(char* buffer)
{
  Node* head = NULL;
  Node* tail = NULL;

  // Eat the first character, it's always a parenthesis
  buffer++;

  // Traverse the remaining characters
  while (*buffer)
  {
    // Allocate a new node
    Node* new_node = malloc(sizeof(Node));

    // Set the node's data
    new_node->data = *buffer;

    // If the head is NULL, make it the head
    if (head == NULL)
    {
      head = new_node;
      tail = new_node;
    }
    else
    {
      tail->next = new_node;
      tail = new_node;
    }

    // Move to the next character
    buffer++;
  }

  // Print the nodes
  for (Node* node = head; node; node = node->next)
  {
    printf("%c ", node->data);
  }

  printf("\n");
}

int main()
{
  char buffer[MAX_BUFFER_SIZE] = "()abc)";

  parse_syntax(buffer);

  return 0;
}