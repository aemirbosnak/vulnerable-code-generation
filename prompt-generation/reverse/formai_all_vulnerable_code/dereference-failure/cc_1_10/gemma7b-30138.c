//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonNode {
  struct JsonNode* next;
  char* key;
  char* value;
} JsonNode;

void parseJson(char* jsonStr) {
  JsonNode* head = NULL;
  JsonNode* tail = NULL;

  // Allocate memory for the first node
  head = malloc(sizeof(JsonNode));
  tail = head;

  // Parse the JSON string
  char* key = NULL;
  char* value = NULL;
  int i = 0;
  for (i = 0; jsonStr[i] != '\0'; i++) {
    // Check if the current character is a key-value separator
    if (jsonStr[i] == ':') {
      // Allocate memory for the key and value
      key = malloc(MAX_BUFFER_SIZE);
      value = malloc(MAX_BUFFER_SIZE);

      // Copy the key and value from the JSON string
      int j = 0;
      for (j = i + 1; jsonStr[j] != ',' && jsonStr[j] != '}'; j++) {
        key[j - i - 1] = jsonStr[j];
      }
      key[j - i - 1] = '\0';

      int k = 0;
      for (k = j + 1; jsonStr[k] != ',' && jsonStr[k] != '}'; k++) {
        value[k - j - 1] = jsonStr[k];
      }
      value[k - j - 1] = '\0';

      // Add the node to the JSON tree
      tail->next = malloc(sizeof(JsonNode));
      tail = tail->next;
      tail->key = key;
      tail->value = value;
    }
  }

  // Print the JSON tree
  JsonNode* current = head;
  while (current) {
    printf("Key: %s, Value: %s\n", current->key, current->value);
    current = current->next;
  }
}

int main() {
  char* jsonStr = "{ 'name': 'Ada Lovelace', 'age': 19, 'interests': [ 'music', 'science', 'computing' ] }";
  parseJson(jsonStr);

  return 0;
}