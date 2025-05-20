//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
} Node;

typedef struct Parser {
  Node* head;
  int state;
  char* current_symbol;
} Parser;

void parser_init(Parser* parser) {
  parser->head = NULL;
  parser->state = 0;
  parser->current_symbol = NULL;
}

void parser_add_symbol(Parser* parser, char* symbol) {
  Node* new_node = malloc(sizeof(Node));
  new_node->data = parser->state;
  new_node->next = parser->head;
  parser->head = new_node;
  parser->current_symbol = symbol;
  parser->state++;
}

void parser_parse(Parser* parser) {
  switch (parser->state) {
    case 0:
      parser_add_symbol(parser, "IDENTIFIER");
      break;
    case 1:
      parser_add_symbol(parser, "NUMBER");
      break;
    case 2:
      parser_add_symbol(parser, "OPERATION");
      break;
    case 3:
      parser_add_symbol(parser, "PARENTHESES");
      break;
  }
}

int main() {
  Parser* parser = malloc(sizeof(Parser));
  parser_init(parser);

  char* input = "12 + 34 (5) * 6";

  for (int i = 0; i < strlen(input); i++) {
    char symbol = input[i];
    parser_parse(parser);
    parser_add_symbol(parser, &symbol);
  }

  printf("Symbols: \n");
  for (Node* node = parser->head; node; node++) {
    printf("%s ", parser->current_symbol);
  }

  free(parser);
  return 0;
}