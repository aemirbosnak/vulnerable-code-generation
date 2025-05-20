//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonNode {
  char type;
  union {
    int number;
    char *string;
    struct JsonNode *object;
    struct JsonNode *array;
  } data;
  struct JsonNode *next;
} JsonNode;

JsonNode *parseJson(char *json_string) {
  JsonNode *head = NULL;
  JsonNode *tail = NULL;

  // Allocate memory for the first node
  head = malloc(sizeof(JsonNode));
  tail = head;

  // Parse the JSON string
  char *p = json_string;
  int state = 0; // 0 for object, 1 for array, 2 for string

  // Iterate over the JSON string
  while (*p) {
    // Handle quotes for strings
    if (*p == '"') {
      state = 2;
    }

    // Handle commas and colons
    else if (*p == ',' || *p == ':') {
      state = 0;
    }

    // Handle opening square bracket for arrays
    else if (*p == '[') {
      state = 1;
    }

    // Handle closing square bracket and curly brace
    else if (*p == ']' || *p == '}') {
      state = 0;
    }

    // Add data to the node
    switch (state) {
      case 0:
        tail->type = 'o';
        tail->data.object = NULL;
        break;
      case 1:
        tail->type = 'a';
        tail->data.array = NULL;
        break;
      case 2:
        tail->type = 's';
        tail->data.string = strdup(p + 1);
        break;
    }

    // Allocate memory for the next node
    tail->next = malloc(sizeof(JsonNode));
    tail = tail->next;
  }

  // Return the head node
  return head;
}

int main() {
  char json_string[] = "{ 'name': 'John Doe', 'age': 30, 'friends': [ 'Alice', 'Bob' ] }";
  JsonNode *json_parser = parseJson(json_string);

  // Print the JSON data
  while (json_parser) {
    switch (json_parser->type) {
      case 'o':
        printf("Object:\n");
        break;
      case 'a':
        printf("Array:\n");
        break;
      case 's':
        printf("String: %s\n", json_parser->data.string);
        break;
    }
    json_parser = json_parser->next;
  }

  return 0;
}