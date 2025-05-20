//Gemma-7B DATASET v1.0 Category: User Input Sanitizer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER_SIZE 256

typedef struct Node {
  char data;
  struct Node* next;
} Node;

Node* sanitizeInput(char* input) {
  Node* head = NULL;
  Node* tail = NULL;

  for (int i = 0; input[i] != '\0'; i++) {
    char character = input[i];

    // Ignore whitespace and special characters
    if (!isalnum(character) && character != '_' && character != '-') {
      continue;
    }

    // Convert character to lowercase
    character = tolower(character);

    // Create a new node
    Node* newNode = malloc(sizeof(Node));
    newNode->data = character;
    newNode->next = NULL;

    // If the head is NULL, make it the head
    if (head == NULL) {
      head = newNode;
    }

    // Otherwise, add the node to the tail
    if (tail) {
      tail->next = newNode;
    }

    tail = newNode;
  }

  return head;
}

int main() {
  char input[MAX_BUFFER_SIZE];

  printf("Enter a string: ");
  fgets(input, MAX_BUFFER_SIZE, stdin);

  Node* sanitizedInput = sanitizeInput(input);

  printf("Sanitized input: ");
  for (Node* node = sanitizedInput; node; node = node->next) {
    printf("%c ", node->data);
  }

  printf("\n");

  return 0;
}