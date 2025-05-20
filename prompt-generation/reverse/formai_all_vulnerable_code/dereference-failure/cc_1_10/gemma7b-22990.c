//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
  char data;
  struct Node* next;
} Node;

typedef struct Parser {
  char* buffer;
  int position;
  Node* head;
  Node* tail;
} Parser;

Parser* parser_init(int size) {
  Parser* parser = malloc(sizeof(Parser));
  parser->buffer = malloc(size * MAX_BUFFER_SIZE);
  parser->position = 0;
  parser->head = NULL;
  parser->tail = NULL;
  return parser;
}

void parser_parse(Parser* parser, char symbol) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = symbol;
  newNode->next = NULL;

  if (parser->head == NULL) {
    parser->head = newNode;
    parser->tail = newNode;
  } else {
    parser->tail->next = newNode;
    parser->tail = newNode;
  }
}

void parser_print(Parser* parser) {
  Node* current = parser->head;
  while (current) {
    printf("%c ", current->data);
    current = current->next;
  }
  printf("\n");
}

int main() {
  Parser* parser = parser_init(10);
  parser_parse(parser, 'a');
  parser_parse(parser, 'b');
  parser_parse(parser, 'c');
  parser_parse(parser, 'd');
  parser_print(parser);

  return 0;
}