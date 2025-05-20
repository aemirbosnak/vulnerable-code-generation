//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
  char data;
  struct Node* next;
} Node;

typedef struct JsonParser {
  Node* head;
  int size;
} JsonParser;

JsonParser* parser_init(int size) {
  JsonParser* parser = malloc(sizeof(JsonParser));
  parser->head = NULL;
  parser->size = size;
  return parser;
}

void parser_add(JsonParser* parser, char data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = parser->head;
  parser->head = newNode;
  parser->size++;
}

char parser_get(JsonParser* parser, int index) {
  if (index < 0 || index >= parser->size) {
    return '\0';
  }
  Node* current = parser->head;
  for (int i = 0; i < index; i++) {
    current = current->next;
  }
  return current->data;
}

void parser_free(JsonParser* parser) {
  free(parser->head);
  free(parser);
}

int main() {
  JsonParser* parser = parser_init(10);
  parser_add(parser, 'a');
  parser_add(parser, 'b');
  parser_add(parser, 'c');
  parser_add(parser, 'd');

  printf("%c", parser_get(parser, 2));

  parser_free(parser);

  return 0;
}