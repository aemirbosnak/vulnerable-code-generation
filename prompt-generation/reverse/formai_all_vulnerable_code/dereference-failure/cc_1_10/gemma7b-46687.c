//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonNode {
  char *key;
  char *value;
  struct JsonNode *next;
} JsonNode;

JsonNode *parseJson(char *jsonString) {
  JsonNode *head = NULL;
  JsonNode *tail = NULL;
  char *buffer = malloc(MAX_BUFFER_SIZE);
  strcpy(buffer, jsonString);
  char *token = strtok(buffer, ",");

  while (token) {
    char *key = strtok(token, ":");
    char *value = strtok(NULL, ":");
    JsonNode *newNode = malloc(sizeof(JsonNode));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;

    if (head == NULL) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }

    token = strtok(NULL, ",");
  }

  free(buffer);
  return head;
}

int main() {
  char *jsonString = "{ 'name': 'John Doe', 'age': 30, 'interests': [ 'music', 'reading', 'coding' ] }";
  JsonNode *head = parseJson(jsonString);

  printf("Key: %s, Value: %s\n", head->key, head->value);
  printf("Key: %s, Value: %s\n", head->next->key, head->next->value);
  printf("Key: %s, Value: %s\n", head->next->next->key, head->next->next->value);

  return 0;
}