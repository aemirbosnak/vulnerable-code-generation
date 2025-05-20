//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
  char *data;
  struct Node *next;
} Node;

void insertAtTail(Node *head, char *data) {
  Node *newNode = malloc(sizeof(Node));
  newNode->data = strdup(data);
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  head = newNode;
}

int main() {
  Node *head = NULL;

  char buffer[MAX_BUFFER_SIZE];
  printf("Enter a C syntax expression: ");
  fgets(buffer, MAX_BUFFER_SIZE, stdin);

  // Parse the C syntax expression
  char *token = strtok(buffer, " ");
  while (token) {
    insertAtTail(head, token);
    token = strtok(NULL, " ");
  }

  // Print the parsed nodes
  Node *current = head;
  while (current) {
    printf("%s ", current->data);
    current = current->next;
  }

  printf("\n");

  return 0;
}