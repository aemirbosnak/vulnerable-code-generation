//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char data;
  struct Node* next;
} Node;

typedef struct Parser {
  FILE* file;
  Node* head;
  int line_number;
} Parser;

Parser* parser_init(FILE* file) {
  Parser* parser = malloc(sizeof(Parser));
  parser->file = file;
  parser->head = NULL;
  parser->line_number = 1;

  return parser;
}

void parser_parse(Parser* parser) {
  char line[1024];
  char* token;

  while (fgets(line, 1024, parser->file) != NULL) {
    parser->line_number++;

    token = strtok(line, " \t\n");

    while (token) {
      Node* node = malloc(sizeof(Node));
      node->data = token[0];
      node->next = parser->head;
      parser->head = node;
      token = strtok(NULL, " \t\n");
    }
  }
}

int main() {
  FILE* file = fopen("code.c", "r");
  Parser* parser = parser_init(file);
  parser_parse(parser);

  fclose(file);

  return 0;
}