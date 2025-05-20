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

JsonNode *parseJson(char *jsonString) {
  JsonNode *head = NULL;
  JsonNode *currentNode = NULL;
  int i = 0;
  char buffer[MAX_BUFFER_SIZE];

  // Allocate memory for the first node
  if (jsonString) {
    head = malloc(sizeof(JsonNode));
    head->key = NULL;
    head->next = NULL;
    head->data.string = strdup(jsonString);

    currentNode = head;
  }

  // Loop over the JSON string
  while (jsonString[i] && i < MAX_BUFFER_SIZE) {
    // Check if the current character is a key
    if (jsonString[i] >= 'a' && jsonString[i] <= 'z') {
      // Allocate memory for the key
      currentNode->key = malloc(sizeof(char) * 256);
      currentNode->key = strdup(&jsonString[i]);

      // Move to the next character
      i++;
    }

    // Check if the current character is a colon
    else if (jsonString[i] == ':') {
      // Move to the next character
      i++;

      // Allocate memory for the data
      currentNode->data.string = malloc(sizeof(char) * 256);
      currentNode->data.string = strdup(&jsonString[i]);

      // Move to the next character
      i++;
    }

    // Check if the current character is a comma
    else if (jsonString[i] == ',') {
      // Allocate memory for the next node
      currentNode->next = malloc(sizeof(JsonNode));
      currentNode = currentNode->next;
    }

    // Move to the next character
    i++;
  }

  return head;
}

int main() {
  char *jsonString = "{ 'name': 'Ada Lovelace', 'age': 19 }";
  JsonNode *head = parseJson(jsonString);

  // Print the JSON data
  for (JsonNode *currentNode = head; currentNode; currentNode = currentNode->next) {
    printf("%s: %s\n", currentNode->key, currentNode->data.string);
  }

  return 0;
}