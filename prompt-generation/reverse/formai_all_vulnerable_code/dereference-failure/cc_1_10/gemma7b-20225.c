//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char data[1024];
  struct Node* next;
} Node;

typedef struct Parser {
  Node* head;
  char** parsed_data;
  int parsed_data_size;
  int current_level;
  struct Parser* next;
} Parser;

Parser* parser_init(int data_size) {
  Parser* parser = (Parser*)malloc(sizeof(Parser));
  parser->head = NULL;
  parser->parsed_data = NULL;
  parser->parsed_data_size = 0;
  parser->current_level = 0;
  parser->next = NULL;

  return parser;
}

void parser_add_data(Parser* parser, char* data) {
  Node* node = (Node*)malloc(sizeof(Node));
  strcpy(node->data, data);
  node->next = parser->head;
  parser->head = node;
}

void parser_parse(Parser* parser) {
  parser->parsed_data = (char**)malloc(sizeof(char*) * parser->parsed_data_size);
  parser->parsed_data_size++;

  parser->current_level++;
  parser_parse(parser->next);
  parser->current_level--;

  parser->parsed_data[parser->parsed_data_size - 1] = parser->head->data;
  parser_add_data(parser, parser->head->data);
  free(parser->head);
  parser->head = NULL;
}

int main() {
  char json_data[] = "{ 'name': 'John Doe', 'age': 30, 'interests': [ 'music', 'reading', 'coding' ] }";

  Parser* parser = parser_init(1024);
  parser_add_data(parser, json_data);
  parser_parse(parser);

  printf("Parsed data:\n");
  for (int i = 0; i < parser->parsed_data_size; i++) {
    printf("%s\n", parser->parsed_data[i]);
  }

  free(parser);

  return 0;
}