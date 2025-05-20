//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
  char *key;
  struct Node *next;
  struct Node *child;
} Node;

Node *parseJson(char *jsonString) {
  Node *head = NULL;
  int i = 0;
  char buffer[MAX_BUFFER_SIZE];

  // Allocate memory for the root node
  head = malloc(sizeof(Node));
  head->key = NULL;
  head->next = NULL;
  head->child = NULL;

  // Loop over the JSON string
  while (jsonString[i] != '\0') {
    // Check if the current character is a key-value separator
    if (jsonString[i] == ':') {
      // Allocate memory for the key
      buffer[0] = '\0';
      i++;
      // Copy the key from the string
      while (jsonString[i] != ',' && jsonString[i] != '}' && jsonString[i] != '\0') {
        buffer[i - 1] = jsonString[i];
        i++;
      }
      buffer[i - 1] = '\0';

      // Create a new node and add it to the head
      Node *newNode = malloc(sizeof(Node));
      newNode->key = strdup(buffer);
      newNode->next = NULL;
      newNode->child = NULL;
      head->child = newNode;
      head = newNode;
    }

    // Check if the current character is a comma or closing brace
    if (jsonString[i] == ',' || jsonString[i] == '}') {
      // Move to the next character
      i++;
    }
  }

  return head;
}

int main() {
  char jsonString[] = "{ 'name': 'John Doe', 'age': 30, 'interests': [ 'music', 'reading', 'coding' ] }";
  Node *head = parseJson(jsonString);

  // Print the key-value pairs in the JSON object
  for (Node *node = head->child; node; node = node->next) {
    printf("%s: %s\n", node->key, node->key);
  }

  return 0;
}