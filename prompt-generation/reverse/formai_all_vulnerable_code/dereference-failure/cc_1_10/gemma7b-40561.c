//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

typedef struct Node {
  char data;
  struct Node* next;
} Node;

void parse_syntax(char* buffer) {
  Node* head = NULL;
  Node* tail = NULL;

  // Tokenize the buffer
  char* token = strtok(buffer, " ");

  // Iterate over the tokens
  while (token) {
    // Allocate a new node
    Node* new_node = malloc(sizeof(Node));
    new_node->data = token[0];
    new_node->next = NULL;

    // If the head is NULL, make it the head
    if (head == NULL) {
      head = new_node;
      tail = new_node;
    } else {
      tail->next = new_node;
      tail = new_node;
    }
  }

  // Print the nodes
  for (Node* node = head; node; node = node->next) {
    printf("%c ", node->data);
  }

  printf("\n");
}

int main() {
  char buffer[MAX_BUFFER_SIZE];

  // Get the buffer
  printf("Enter a syntax: ");
  fgets(buffer, MAX_BUFFER_SIZE, stdin);

  // Parse the syntax
  parse_syntax(buffer);

  return 0;
}