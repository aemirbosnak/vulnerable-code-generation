//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonNode {
  char type;
  union {
    int number;
    double decimal;
    char stringValue;
    struct JsonNode* array;
    struct JsonNode* object;
  } data;
  struct JsonNode* next;
} JsonNode;

JsonNode* JsonNode_create() {
  JsonNode* node = (JsonNode*)malloc(sizeof(JsonNode));
  node->type = 'n';
  node->data.number = 0;
  node->next = NULL;
  return node;
}

void JsonNode_setNumber(JsonNode* node, int number) {
  node->type = 'i';
  node->data.number = number;
}

void JsonNode_setDecimal(JsonNode* node, double decimal) {
  node->type = 'd';
  node->data.decimal = decimal;
}

void JsonNode_setString(JsonNode* node, char* stringValue) {
  node->type = 's';
  node->data.stringValue = stringValue;
}

void JsonNode_setArray(JsonNode* node, JsonNode* array) {
  node->type = 'a';
  node->data.array = array;
}

void JsonNode_setObject(JsonNode* node, JsonNode* object) {
  node->type = 'o';
  node->data.object = object;
}

void JsonNode_addToTail(JsonNode* head, JsonNode* node) {
  if (head == NULL) {
    head = node;
  } else {
    head->next = node;
    head = node;
  }
}

int JsonNode_parse(char* jsonStr) {
  JsonNode* head = JsonNode_create();
  // Parse JSON string into nodes
  // ...

  // Print JSON data from nodes
  // ...

  return 0;
}

int main() {
  char* jsonStr = "{ 'name': 'John Doe', 'age': 30 }";
  JsonNode_parse(jsonStr);
  return 0;
}