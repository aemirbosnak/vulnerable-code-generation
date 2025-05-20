//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
  char *data;
  struct Node *next;
} Node;

typedef struct JSONParser {
  Node *root;
  int size;
} JSONParser;

JSONParser *parser_init(int size) {
  JSONParser *parser = malloc(sizeof(JSONParser));
  parser->root = NULL;
  parser->size = size;
  return parser;
}

void parser_add(JSONParser *parser, char *data) {
  Node *newNode = malloc(sizeof(Node));
  newNode->data = strdup(data);
  newNode->next = NULL;

  if (parser->root == NULL) {
    parser->root = newNode;
  } else {
    parser->root->next = newNode;
  }

  parser->size++;
}

void parser_print(JSONParser *parser) {
  Node *currentNode = parser->root;
  while (currentNode) {
    printf("%s\n", currentNode->data);
    currentNode = currentNode->next;
  }
}

int main() {
  JSONParser *parser = parser_init(10);
  parser_add(parser, "John Doe");
  parser_add(parser, "Jane Doe");
  parser_add(parser, "Peter Pan");

  parser_print(parser);

  return 0;
}