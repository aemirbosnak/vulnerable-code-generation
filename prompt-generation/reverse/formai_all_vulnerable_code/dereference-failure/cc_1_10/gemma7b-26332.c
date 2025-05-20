//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char data;
  struct Node* next;
} Node;

typedef struct Parser {
  Node* head;
  Node* tail;
  char current_state;
  char previous_state;
} Parser;

Parser* parser_init() {
  Parser* p = malloc(sizeof(Parser));
  p->head = NULL;
  p->tail = NULL;
  p->current_state = 'S';
  p->previous_state = 'N';
  return p;
}

void parser_parse(Parser* p, char input) {
  switch (p->current_state) {
    case 'S':
      if (input == '(') {
        p->previous_state = 'S';
        p->current_state = 'I';
      } else if (input == ')') {
        fprintf(stderr, "Syntax error: unbalanced parenthesis.\n");
      } else {
        fprintf(stderr, "Syntax error: unexpected character.\n");
      }
      break;
    case 'I':
      if (input == ')') {
        p->previous_state = 'S';
        p->current_state = 'E';
      } else if (input == '(') {
        fprintf(stderr, "Syntax error: nested parenthesis is not allowed.\n");
      } else {
        fprintf(stderr, "Syntax error: unexpected character.\n");
      }
      break;
    case 'E':
      if (input == ')') {
        fprintf(stderr, "Syntax error: unbalanced parenthesis.\n");
      } else if (input == '\n') {
        p->previous_state = 'S';
        p->current_state = 'N';
      } else {
        fprintf(stderr, "Syntax error: unexpected character.\n");
      }
      break;
  }
}

int main() {
  Parser* p = parser_init();
  char input;
  while ((input = getchar()) != '\n') {
    parser_parse(p, input);
  }
  return 0;
}