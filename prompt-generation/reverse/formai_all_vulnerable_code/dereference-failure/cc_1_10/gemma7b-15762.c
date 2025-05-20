//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
  char *data;
  struct Node *next;
} Node;

typedef struct Parser {
  Node *head;
  FILE *fp;
} Parser;

Parser *parser_init(FILE *fp) {
  Parser *parser = malloc(sizeof(Parser));
  parser->head = NULL;
  parser->fp = fp;
  return parser;
}

void parser_parse(Parser *parser) {
  char buffer[MAX_BUFFER_SIZE];
  int read_size = 0;
  while ((read_size = fread(buffer, 1, MAX_BUFFER_SIZE, parser->fp)) > 0) {
    Node *node = malloc(sizeof(Node));
    node->data = strdup(buffer);
    node->next = parser->head;
    parser->head = node;
  }
}

void parser_print(Parser *parser) {
  Node *node = parser->head;
  while (node) {
    printf("%s\n", node->data);
    node = node->next;
  }
}

int main() {
  FILE *fp = fopen("syntax.c", "r");
  Parser *parser = parser_init(fp);
  parser_parse(parser);
  parser_print(parser);
  fclose(fp);
  return 0;
}