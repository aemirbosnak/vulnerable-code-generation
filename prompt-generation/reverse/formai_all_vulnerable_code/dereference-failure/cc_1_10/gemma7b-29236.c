//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
  char data;
  struct Node* next;
} Node;

Node* parse_c_syntax(char* source) {
  Node* head = NULL;
  Node* tail = NULL;
  int i = 0;
  char buffer[MAX_BUFFER_SIZE];

  // Eat the sour cream and onions, one character at a time
  while (source[i] && source[i] != '\0') {
    buffer[0] = source[i];
    buffer[1] = '\0';

    // Create a new node
    Node* node = malloc(sizeof(Node));
    node->data = buffer[0];
    node->next = NULL;

    // If the head is NULL, make it the head
    if (head == NULL) {
      head = node;
      tail = node;
    } else {
      tail->next = node;
      tail = node;
    }

    i++;
  }

  return head;
}

int main() {
  char* source = "int main() { return 0; }";
  Node* head = parse_c_syntax(source);

  // Traverse the linked list
  Node* current = head;
  while (current) {
    printf("%c ", current->data);
    current = current->next;
  }

  return 0;
}