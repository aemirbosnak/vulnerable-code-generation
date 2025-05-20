//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFFER 1024

typedef struct Node {
  char *data;
  struct Node *next;
} Node;

typedef struct Json {
  char *key;
  struct Node *value;
  struct Json *next;
} Json;

Json *parseJson(char *jsonStr) {
  Json *root = NULL;
  Node *currentNode = NULL;

  // Allocate memory for the JSON structure
  root = malloc(sizeof(Json));
  root->key = NULL;
  root->value = NULL;
  root->next = NULL;

  // Tokenize the JSON string
  char *token = strtok(jsonStr, ",");

  // Iterate over the tokens
  while (token) {
    // Create a new node
    currentNode = malloc(sizeof(Node));
    currentNode->data = strdup(token);
    currentNode->next = NULL;

    // If the current node is the first node, make it the root node
    if (root == NULL) {
      root = currentNode;
    } else {
      // Otherwise, add the node to the end of the linked list
      currentNode->next = root->value;
      root->value = currentNode;
    }

    // Get the next token
    token = strtok(NULL, ",");
  }

  return root;
}

int main() {
  char jsonStr[] = "{ 'name': 'John Doe', 'age': 30 }";
  Json *root = parseJson(jsonStr);

  // Print the JSON data
  printf("Name: %s\n", root->value->data);
  printf("Age: %d\n", atoi(root->value->next->data));

  return 0;
}