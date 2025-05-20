//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonNode {
  char type;
  union {
    int number;
    double dnumber;
    char *string;
    struct JsonNode *array;
    struct JsonNode *object;
  } data;
  struct JsonNode *next;
} JsonNode;

JsonNode *parseJson(char *jsonStr) {
  // Allocate memory for the JSON node
  JsonNode *head = malloc(sizeof(JsonNode));
  head->type = 'o';
  head->data.object = NULL;
  head->next = NULL;

  // Tokenize the JSON string
  char *token = strtok(jsonStr, ",");
  while (token) {
    // Create a new JSON node for each key-value pair
    JsonNode *newNode = malloc(sizeof(JsonNode));
    newNode->type = 'k';
    newNode->data.string = strdup(token);
    newNode->next = NULL;

    // Add the new node to the object
    if (head->data.object) {
      head->data.object->next = newNode;
    } else {
      head->data.object = newNode;
    }

    // Get the next token
    token = strtok(NULL, ",");
  }

  // Return the head of the JSON node
  return head;
}

int main() {
  char jsonStr[] = "{ 'name': 'John Doe', 'age': 30 }";
  JsonNode *head = parseJson(jsonStr);

  // Print the JSON data
  printf("Name: %s\n", head->data.object->data.string);
  printf("Age: %d\n", head->data.object->data.number);

  return 0;
}