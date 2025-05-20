//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
  char *data;
  struct Node *next;
} Node;

Node *newNode(char *data) {
  Node *node = malloc(sizeof(Node));
  node->data = strdup(data);
  node->next = NULL;
  return node;
}

void parseJson(char *jsonString) {
  char *buffer = malloc(MAX_BUFFER_SIZE);
  int i = 0;
  Node *head = NULL;

  // Loop over the JSON string
  for (; jsonString[i] != '\0'; i++) {
    // Check for opening curly brace
    if (jsonString[i] == '{') {
      head = newNode(jsonString + i);
    }

    // Check for closing curly brace
    else if (jsonString[i] == '}') {
      // Traverse the linked list and print the data
      Node *current = head;
      while (current) {
        printf("%s\n", current->data);
        current = current->next;
      }

      free(buffer);
      return;
    }

    // Store the character in the buffer
    buffer[i] = jsonString[i];
  }

  // Error: JSON string is malformed
  printf("Error parsing JSON string.\n");
  free(buffer);
}

int main() {
  parseJson("{\"name\":\"John Doe\",\"age\":30}");
  return 0;
}