//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
  char *data;
  struct Node *next;
} Node;

Node *parseJSON(char *jsonString);

int main() {
  char jsonString[] = "{ 'name': 'John Doe', 'age': 30 }";
  Node *parsedNode = parseJSON(jsonString);

  if (parsedNode) {
    printf("Name: %s\n", parsedNode->data);
    printf("Age: %d\n", atoi(parsedNode->next->data));
  } else {
    printf("Error parsing JSON\n");
  }

  return 0;
}

Node *parseJSON(char *jsonString) {
  // Allocate memory for the parser
  Node *parsedNode = malloc(sizeof(Node));
  parsedNode->data = malloc(MAX_BUFFER_SIZE);

  // Copy the JSON string into the parser
  strcpy(parsedNode->data, jsonString);

  // Find the key-value pairs in the JSON string
  char *key = NULL;
  char *value = NULL;
  while ((key = strstr(parsedNode->data, ":")) && (value = strstr(key, "{"))) {
    // Extract the key and value
    *key = '\0';
    *value = '\0';

    // Create a new node
    Node *newNode = malloc(sizeof(Node));
    newNode->data = malloc(MAX_BUFFER_SIZE);

    // Copy the key and value into the new node
    strcpy(newNode->data, key + 1);
    strcpy(newNode->next->data, value + 1);

    // Add the new node to the parsed node
    parsedNode->next = newNode;

    // Update the parsed node
    parsedNode = newNode;
  }

  // Return the parsed node
  return parsedNode;
}