//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonNode {
  char *key;
  struct JsonNode *next;
  union {
    int number;
    char *string;
  } data;
} JsonNode;

void parseJson(char *jsonString) {
  JsonNode *head = NULL;
  JsonNode *currentNode = NULL;

  // Allocate memory for the first node
  head = malloc(sizeof(JsonNode));
  currentNode = head;

  // Loop over the JSON string
  for (int i = 0; jsonString[i] != '\0'; i++) {
    // Check if the current character is a key-value separator or a colon
    if (jsonString[i] == ',' || jsonString[i] == ':' || jsonString[i] == '}') {
      // Allocate memory for the key and data nodes
      JsonNode *keyNode = malloc(sizeof(JsonNode));
      JsonNode *dataNode = malloc(sizeof(JsonNode));

      // Set the key and data nodes
      keyNode->key = malloc(MAX_BUFFER_SIZE);
      dataNode->data.string = malloc(MAX_BUFFER_SIZE);

      // Copy the key and data from the JSON string
      memcpy(keyNode->key, jsonString + i - MAX_BUFFER_SIZE, MAX_BUFFER_SIZE);
      memcpy(dataNode->data.string, jsonString + i + 1, MAX_BUFFER_SIZE);

      // Insert the key and data nodes into the linked list
      currentNode->next = keyNode;
      keyNode->next = dataNode;
      currentNode = dataNode;
    }
  }

  // Free the memory allocated for the JSON nodes
  free(head);
}

int main() {
  char jsonString[] = "{ 'name': 'Ada Lovelace', 'age': 19, 'interests': [ 'music', 'science', 'poetry' ] }";
  parseJson(jsonString);

  return 0;
}