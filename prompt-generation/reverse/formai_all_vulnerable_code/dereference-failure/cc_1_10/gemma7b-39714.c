//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonNode {
  char type;
  union {
    int number;
    double decimal;
    char *string;
    struct JsonNode *object;
    struct JsonNode *array;
  } data;
  struct JsonNode *next;
} JsonNode;

void parseJson(char *jsonStr) {
  // Create a JSON node
  JsonNode *node = malloc(sizeof(JsonNode));
  node->type = 'o';
  node->data.object = NULL;
  node->next = NULL;

  // Parse the JSON string
  char *ptr = jsonStr;
  while (*ptr) {
    // Skip whitespace
    while (*ptr && isspace(*ptr)) {
      ptr++;
    }

    // Check for object start
    if (*ptr == '{') {
      // Create a new object node
      JsonNode *newObject = malloc(sizeof(JsonNode));
      newObject->type = 'o';
      newObject->data.object = NULL;
      newObject->next = node->data.object;
      node->data.object = newObject;
    }

    // Check for array start
    else if (*ptr == '[') {
      // Create a new array node
      JsonNode *newArray = malloc(sizeof(JsonNode));
      newArray->type = 'a';
      newArray->data.array = NULL;
      newArray->next = node->data.object;
      node->data.object = newArray;
    }

    // Check for string
    else if (*ptr == '"') {
      // Create a new string node
      JsonNode *newString = malloc(sizeof(JsonNode));
      newString->type = 's';
      newString->data.string = strdup(ptr);
      newString->next = node->data.object;
      node->data.object = newString;
    }

    // Check for number
    else if (isdigit(*ptr)) {
      // Create a new number node
      JsonNode *newNumber = malloc(sizeof(JsonNode));
      newNumber->type = 'n';
      newNumber->data.number = atoi(ptr);
      newNumber->next = node->data.object;
      node->data.object = newNumber;
    }

    // Increment pointer
    ptr++;
  }

  // Free the JSON node
  free(node);
}

int main() {
  char jsonStr[] = "{ 'name': 'Ada Lovelace', 'age': 19, 'interests': [ 'music', 'science', 'coding' ] }";

  parseJson(jsonStr);

  return 0;
}