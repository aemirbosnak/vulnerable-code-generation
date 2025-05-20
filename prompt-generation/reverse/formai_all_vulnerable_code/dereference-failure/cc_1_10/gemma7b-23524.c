//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonNode {
  char *key;
  struct JsonNode *next;
  union {
    int number;
    double decimal;
    char *string;
  } data;
} JsonNode;

JsonNode *parseJson(char *jsonStr) {
  JsonNode *head = NULL;
  JsonNode *currentNode = NULL;
  char *buffer = NULL;
  int bufferSize = 0;
  int i = 0;

  // Allocate memory for the buffer
  buffer = malloc(MAX_BUFFER_SIZE);

  // Copy the JSON string into the buffer
  memcpy(buffer, jsonStr, strlen(jsonStr) + 1);

  // Parse the JSON string
  while (i < strlen(buffer)) {
    // Check if the current character is a key
    if (buffer[i] == '"') {
      // Allocate memory for the key
      currentNode = malloc(sizeof(JsonNode));
      currentNode->key = malloc(MAX_BUFFER_SIZE);

      // Copy the key from the buffer
      memcpy(currentNode->key, buffer + i + 1, strlen(buffer + i + 1) + 1);

      // Add the current node to the head if it is the first node
      if (head == NULL) {
        head = currentNode;
      } else {
        currentNode->next = head;
        head = currentNode;
      }
    }

    // Check if the current character is a colon
    if (buffer[i] == ':') {
      // Determine the data type of the value
      switch (buffer[i + 1]) {
        case 'n':
          currentNode->data.number = atoi(buffer + i + 2);
          break;
        case 'f':
          currentNode->data.decimal = atof(buffer + i + 2);
          break;
        case '"':
          currentNode->data.string = malloc(MAX_BUFFER_SIZE);
          memcpy(currentNode->data.string, buffer + i + 2, strlen(buffer + i + 2) + 1);
          break;
      }
    }

    // Increment the index
    i++;
  }

  // Free the memory allocated for the buffer
  free(buffer);

  // Return the head of the JSON node list
  return head;
}

int main() {
  char *jsonStr = "{ 'name': 'John Doe', 'age': 30, 'interests': ['music', 'reading'] }";
  JsonNode *head = parseJson(jsonStr);

  // Print the JSON data
  for (JsonNode *currentNode = head; currentNode; currentNode = currentNode->next) {
    printf("%s: %s\n", currentNode->key, currentNode->data.string);
  }

  // Free the memory allocated for the JSON node list
  free(head);

  return 0;
}