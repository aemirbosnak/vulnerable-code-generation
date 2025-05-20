//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: safe
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
  } value;
} JsonNode;

void JsonNode_Create(JsonNode **node, char *key, int value) {
  *node = malloc(sizeof(JsonNode));
  (*node)->key = strdup(key);
  (*node)->next = NULL;
  (*node)->value.number = value;
}

void JsonNode_Append(JsonNode **node, char *key, int value) {
  JsonNode *newNode = malloc(sizeof(JsonNode));
  newNode->key = strdup(key);
  newNode->next = NULL;
  newNode->value.number = value;

  if (*node) {
    ((*node)->next = newNode);
  } else {
    *node = newNode;
  }
}

void JsonNode_Print(JsonNode *node) {
  printf("{");
  for (node = node; node; node = node->next) {
    printf("\"%s\": %d,", node->key, node->value.number);
    if (node->next) {
      printf(", ");
    }
  }
  printf("}\n");
}

int main() {
  JsonNode *node = NULL;
  JsonNode_Create(&node, "name", 10);
  JsonNode_Append(&node, "age", 20);
  JsonNode_Append(&node, "address", 1234);
  JsonNode_Print(node);

  return 0;
}