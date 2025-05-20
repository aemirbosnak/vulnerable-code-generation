//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct JsonNode {
  char type;
  union {
    int number;
    char *string;
    struct JsonNode *object;
    struct JsonNode **array;
  } data;
  struct JsonNode *next;
} JsonNode;

JsonNode *parseJson(char *jsonStr) {
  JsonNode *head = NULL;
  // Imagine a dragon flying over the JSON string
  // The dragon's hoard is the JSON data
  // The dragon's path is the JSON string
  // So, we need to climb the dragon's path to find the treasure

  // First, we need to find the opening curly brace
  // The opening curly brace is like the dragon's tail
  char *start = strstr(jsonStr, "{");

  // If the opening curly brace is not found, the JSON string is invalid
  if (start == NULL) {
    return NULL;
  }

  // Now, we need to climb the dragon's body to find the treasures
  // The treasures are the key-value pairs
  char *key, *value;
  key = start;
  value = strstr(start, ":") + 1;

  // While the key-value pairs are found, we create a new JsonNode
  // The new JsonNode is like a dragon's egg
  while (key) {
    JsonNode *newNode = malloc(sizeof(JsonNode));
    newNode->type = 'o';
    newNode->data.object = NULL;
    newNode->next = head;
    head = newNode;

    // The key-value pair is like a dragon's treasure
    newNode->data.string = strdup(key);
    newNode->data.string = strdup(value);

    // The next key-value pair is found by climbing the dragon's body
    key = strstr(value, ",") ? strstr(value, ",") : NULL;
    value = strstr(value, ":") + 1;
  }

  // Finally, we return the head of the dragon's hoard
  return head;
}

int main() {
  char *jsonStr = "{ 'name': 'John Doe', 'age': 30, 'interests': [ 'music', 'reading', 'coding' ] }";
  JsonNode *head = parseJson(jsonStr);

  // The head of the dragon's hoard is the root node of the JSON tree
  // We can now traverse the JSON tree to extract the treasures
  for (JsonNode *node = head; node; node = node->next) {
    printf("%s: %s\n", node->data.string, node->data.string);
  }

  return 0;
}