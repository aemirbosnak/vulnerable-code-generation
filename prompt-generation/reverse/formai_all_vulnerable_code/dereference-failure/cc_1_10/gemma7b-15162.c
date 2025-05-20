//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonNode {
  char type;
  union {
    struct JsonNode *child;
    struct JsonNode **children;
    int number;
    char *string;
  } data;
} JsonNode;

JsonNode *parseJson(char *jsonStr) {
  JsonNode *node = malloc(sizeof(JsonNode));
  node->type = 'o';
  node->data.children = NULL;

  char *buffer = malloc(MAX_BUFFER_SIZE);
  int pos = 0;
  int state = 0;

  while (*jsonStr) {
    switch (state) {
      case 0:
        if (*jsonStr == '"') {
          state = 1;
          node->type = 's';
          node->data.string = buffer;
          buffer = malloc(MAX_BUFFER_SIZE);
          pos = 0;
        } else if (*jsonStr == '{' || *jsonStr == '[') {
          state = 2;
          node->type = 'a';
          node->data.children = malloc(MAX_BUFFER_SIZE);
          node->data.children[0] = parseJson(jsonStr);
          node->data.children[1] = NULL;
        } else if (*jsonStr == ',') {
          state = 2;
          node->data.children[pos] = parseJson(jsonStr);
          node->data.children[++pos] = NULL;
        } else if (*jsonStr == '}') {
          state = 0;
          node->data.children[pos] = NULL;
        }
        break;
      case 1:
        if (*jsonStr == '"') {
          buffer[pos++] = '\0';
          node->data.string = buffer;
          state = 0;
        } else {
          buffer[pos++] = *jsonStr;
        }
        break;
      case 2:
        if (*jsonStr == '}') {
          state = 0;
          node->data.children[pos] = NULL;
        } else if (*jsonStr == ',') {
          state = 2;
          node->data.children[pos] = parseJson(jsonStr);
          node->data.children[++pos] = NULL;
        } else {
          node->data.children[pos] = parseJson(jsonStr);
          node->data.children[++pos] = NULL;
        }
        break;
    }

    jsonStr++;
  }

  return node;
}

int main() {
  char *jsonStr = "{ 'name': 'John Doe', 'age': 30, 'children': [ { 'name': 'Jane Doe', 'age': 20 } ] }";
  JsonNode *node = parseJson(jsonStr);

  printf("Name: %s\n", node->data.string);
  printf("Age: %d\n", node->data.number);
  printf("Children:\n");
  for (int i = 0; node->data.children[i] != NULL; i++) {
    printf("  Name: %s\n", node->data.children[i]->data.string);
    printf("  Age: %d\n", node->data.children[i]->data.number);
  }

  return 0;
}