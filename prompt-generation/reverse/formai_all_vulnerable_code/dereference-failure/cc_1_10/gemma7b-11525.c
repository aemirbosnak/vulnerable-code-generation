//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
  char *data;
  struct Node *next;
} Node;

void parse_syntax(char *buffer) {
  Node *head = NULL;
  char *p = buffer;

  while (p) {
    // Identify the keyword and store it in the node
    char *keyword = strpbrk(p, "if else for while switch case");
    Node *node = malloc(sizeof(Node));
    node->data = strdup(keyword);

    // If the head is NULL, make it the first node
    if (head == NULL) {
      head = node;
    } else {
      node->next = head;
      head = node;
    }

    // Skip the keyword and move to the next token
    p = strchr(p, ';') + 1;
  }

  // Print the nodes
  Node *current = head;
  while (current) {
    printf("%s ", current->data);
    current = current->next;
  }

  // Free the nodes
  current = head;
  while (current) {
    free(current->data);
    free(current);
    current = current->next;
  }
}

int main() {
  char buffer[MAX_BUFFER_SIZE] = "if (a == 5) then goto label else print \"Hello, world!\";";
  parse_syntax(buffer);

  return 0;
}